#include "widget.h"
#include "./ui_widget.h"
#include"role.h"
#include <QApplication>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QPoint>
#include<QImage>
#include<QPainter>
#include<QTimer>
#include<QRandomGenerator>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //创建一个场景
    setFixedSize(600,400);
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);//设置索引方法

    //为场景添加视图
    view=new QGraphicsView(scene,this);
    view->setRenderHint(QPainter::Antialiasing);//反锯齿
    view->setBackgroundBrush(QPixmap(":/background1.png"));//添加背景图片
    QPixmap pix=QPixmap(":/background1.png");
    int w=pix.width(),h=pix.height();
    scene->setSceneRect(0, 0,w, h);//设置场景矩形
    scene->addItem(role);//添加主人公

    //视图的相关设置
    view->setCacheMode(QGraphicsView::CacheBackground);//设置视图的缓存模式为 CacheBackground
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);//设置视图的视口更新模式为 BoundingRectViewportUpdate
    view->resize(600, 400);
    view->show();
    role->moveBy(50,340);
    view->centerOn(role);

    //为主人物的操作添加定时器
    connect(role->timer1,&QTimer::timeout,[=]()//移动定时器
            {
                role->n++;
                if(role->n==6)role->n=1;
                role->move();
                view->centerOn(role);
            });
    connect(role->timer2,&QTimer::timeout,[=]()//跳跃定时器
            {
                role->jump();
            });



    //创建“四大教徒”
    AWoman->Mlist1[0]=QPixmap(":/AWoman0.png");
    AWoman->Mlist1[1]=QPixmap(":/AWoman1.png");
    AWoman->Mlist1[2]=QPixmap(":/AWoman2.png");
    AWoman->Mlist2[0]=QPixmap(":/AWoman0-.png");
    AWoman->Mlist2[1]=QPixmap(":/AWoman1-.png");
    AWoman->Mlist2[2]=QPixmap(":/AWoman2-.png");
    QTimer::singleShot(AWoman->time,this,[=](){
        AWoman->moveBy(500,340);
        scene->addItem(AWoman);
    });


    BWoman->Mlist1[0]=QPixmap(":/BWoman0.png");
    BWoman->Mlist1[1]=QPixmap(":/BWoman1.png");
    BWoman->Mlist1[2]=QPixmap(":/BWoman2.png");
    BWoman->Mlist2[0]=QPixmap(":/BWoman0-.png");
    BWoman->Mlist2[1]=QPixmap(":/BWoman1-.png");
    BWoman->Mlist2[2]=QPixmap(":/BWoman2-.png");
    QTimer::singleShot(BWoman->time,this,[=](){
        BWoman->moveBy(500,340);
        scene->addItem(BWoman);});

    AMan->Mlist1[0]=QPixmap(":/AMan0.png");
    AMan->Mlist1[1]=QPixmap(":/AMan1.png");
    AMan->Mlist1[2]=QPixmap(":/AMan2.png");
    AMan->Mlist2[0]=QPixmap(":/AMan0-.png");
    AMan->Mlist2[1]=QPixmap(":/AMan1-.png");
    AMan->Mlist2[2]=QPixmap(":/AMan2-.png");
    QTimer::singleShot(AMan->time,this,[=](){
        AMan->moveBy(500,340);
        scene->addItem(AMan);});

    BMan->Mlist1[0]=QPixmap(":/BMan0.png");
    BMan->Mlist1[1]=QPixmap(":/BMan1.png");
    BMan->Mlist1[2]=QPixmap(":/BMan2.png");
    BMan->Mlist2[0]=QPixmap(":/BMan0-.png");
    BMan->Mlist2[1]=QPixmap(":/BMan1-.png");
    BMan->Mlist2[2]=QPixmap(":/BMan2-.png");
    QTimer::singleShot(BMan->time,this,[=](){
        BMan->moveBy(500,340);
        scene->addItem(BMan);});


    QTimer *timer01=new QTimer();//移动定时器
    timer01->start(100);
    connect(timer01,&QTimer::timeout,this,[=]()
            {
                if(AWoman->canmove)npcmove(AWoman);
                if(BWoman->canmove) npcmove(BWoman);
                if(AMan->canmove) npcmove(AMan);
                if(BMan->canmove)npcmove(BMan);
            });
    QTimer *timer02=new QTimer();//碰撞检测定时器
    timer02->start(100);
    connect(timer02,&QTimer::timeout,this,[=]()
            {
                //碰撞检测
                if(AWoman->x()-role->x()>=-15&&AWoman->x()-role->x()<=15&&AWoman->y()-role->y()<=30&&AWoman->y()-role->y()>=-30)
                {
                    if(!role->beingprotected)
                        role->Hit();
                }
                if(BWoman->x()-role->x()>=-15&&BWoman->x()-role->x()<=15&&BWoman->y()-role->y()<=30&&BWoman->y()-role->y()>=-30)
                {
                    if(!role->beingprotected)
                        role->Hit();
                }
                if(AMan->x()-role->x()>=-15&&AMan->x()-role->x()<=15&&AMan->y()-role->y()<=30&&AMan->y()-role->y()>=-30)
                {
                    if(!role->beingprotected)
                        role->Hit();
                }
                if(BMan->x()-role->x()>=-15&&BMan->x()-role->x()<=15&&BMan->y()-role->y()<=30&&BMan->y()-role->y()>=-30)
                {
                    if(!role->beingprotected)
                        role->Hit();
                }
            });
}

Widget::~Widget()
{
    delete ui;
}

//人物移动
void Widget::npcmove(Mobs *mob)
{

    //调用移动函数
    mob->n++;
    if(mob->n==3)mob->n=1;
    mob->move(role->pos().rx());

    if(role->beingHit&&mob->x()-role->x()>=-15&&mob->x()-role->x()<=15)
    {
        mob->n=0;mob->update();
        mob->canmove=false;
        QTimer::singleShot(1500,this,[=]()
                           {
                               mob->canmove=true;
                           });
    }
}
void Widget::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        if (event->key() == Qt::Key_D)
        {
            role->direction = event->key();
            role->moving = true;role->face=1;
            role->timer1->start(50);
        }
        if(event->key() == Qt::Key_A)
        {
            role->direction = event->key();
            role->moving = true;role->face=-1;
            role->timer1->start(50);
        }
        if(event->key()==Qt::Key_K)
        {
            role->timer2->start(50);
        }
    }
}
void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        if (role->moving &&  (event->key() == Qt::Key_D))
        {
            role->moving = false;
            role->face=1;
            role->timer1->stop();
            role->n=0;role->update();
        }
        if (role->moving && (event->key() == Qt::Key_A))
        {
            role->moving = false;
            role->face=-1;
            role->timer1->stop();
            role->n=0;role->update();
        }
    }
}
