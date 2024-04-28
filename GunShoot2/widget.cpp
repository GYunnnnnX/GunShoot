#include "widget.h"
#include "./ui_widget.h"
#include"role.h"
#include"bullet.h"
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
    ui->setupUi(this);
    // 设置滚动条策略为永久隐藏
    setWindowTitle("周处除三害");
    setFixedSize(600,400);

    //设置场景
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
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);//设置视图的视口更新模式为 BoundingRectViewportUpdate。
    view->resize(600, 400);
    view->setFrameStyle(QFrame::NoFrame);
    view->show();
    role->moveBy(50,340);
    view->centerOn(role);
    // 设置滚动条策略为永久隐藏
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//禁用滚动条

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

    //创建子弹对象池
    for (int i = 0; i < 10; ++i) {
        Bullet *bullet = new Bullet();
        bullet->hide(); // 初始隐藏
        scene->addItem(bullet);
        bulletPool.append(bullet);
    };
    connect(bulletTimer,&QTimer::timeout,[=]()//定时对可视的子弹进行移动
            {
                for (Bullet *bullet : bulletPool) {
                    if (bullet->isVisible()) {
                        bullet->move();
                    }
                    if(bullet->x()<0||bullet->x()>w)
                    {
                        bullet->hide();bullet->moveBy(0,-100);
                    }
                }
            });
    bulletTimer->start(50);

    //创建“四大教徒”
    AWoman->Mlist1[0]=QPixmap(":/AWoman0.png");
    AWoman->Mlist1[1]=QPixmap(":/AWoman1.png");
    AWoman->Mlist1[2]=QPixmap(":/AWoman2.png");
    AWoman->Mlist2[0]=QPixmap(":/AWoman0-.png");
    AWoman->Mlist2[1]=QPixmap(":/AWoman1-.png");
    AWoman->Mlist2[2]=QPixmap(":/AWoman2-.png");
    AWoman->Slist1=QPixmap(":/AWomanRed.png");
    AWoman->Slist2=QPixmap(":/AWomanRed-.png");
    AWoman->Dlist1[0]=QPixmap(":/Dead.png");
    AWoman->Dlist1[1]=QPixmap(":/DeadRed.png");
    AWoman->Dlist2[0]=QPixmap(":/Dead-.png");
    AWoman->Dlist2[1]=QPixmap(":/DeadRed-.png");
    QTimer::singleShot(AWoman->time,this,[=](){
        AWoman->moveBy(500,340);
        scene->addItem(AWoman);
        mobsPool.append(AWoman);
    });



    BWoman->Mlist1[0]=QPixmap(":/BWoman0.png");
    BWoman->Mlist1[1]=QPixmap(":/BWoman1.png");
    BWoman->Mlist1[2]=QPixmap(":/BWoman2.png");
    BWoman->Mlist2[0]=QPixmap(":/BWoman0-.png");
    BWoman->Mlist2[1]=QPixmap(":/BWoman1-.png");
    BWoman->Mlist2[2]=QPixmap(":/BWoman2-.png");
    BWoman->Slist1=QPixmap(":/BWomanRed.png");
    BWoman->Slist2=QPixmap(":/BWomanRed-.png");
    BWoman->Dlist1[0]=QPixmap(":/Dead.png");
    BWoman->Dlist1[1]=QPixmap(":/DeadRed.png");
    BWoman->Dlist2[0]=QPixmap(":/Dead-.png");
    BWoman->Dlist2[1]=QPixmap(":/DeadRed-.png");
    QTimer::singleShot(BWoman->time,this,[=](){
        BWoman->moveBy(500,340);
        scene->addItem(BWoman);
        mobsPool.append(BWoman);
    });

    AMan->Mlist1[0]=QPixmap(":/AMan0.png");
    AMan->Mlist1[1]=QPixmap(":/AMan1.png");
    AMan->Mlist1[2]=QPixmap(":/AMan2.png");
    AMan->Mlist2[0]=QPixmap(":/AMan0-.png");
    AMan->Mlist2[1]=QPixmap(":/AMan1-.png");
    AMan->Mlist2[2]=QPixmap(":/AMan2-.png");
    AMan->Slist1=QPixmap(":/AManRed.png");
    AMan->Slist2=QPixmap(":/AManRed-.png");
    AMan->Dlist1[0]=QPixmap(":/Dead.png");
    AMan->Dlist1[1]=QPixmap(":/DeadRed.png");
    AMan->Dlist2[0]=QPixmap(":/Dead-.png");
    AMan->Dlist2[1]=QPixmap(":/DeadRed-.png");
    QTimer::singleShot(AMan->time,this,[=](){
        AMan->moveBy(500,340);
        scene->addItem(AMan);
        mobsPool.append(AMan);
    });

    BMan->Mlist1[0]=QPixmap(":/BMan0.png");
    BMan->Mlist1[1]=QPixmap(":/BMan1.png");
    BMan->Mlist1[2]=QPixmap(":/BMan2.png");
    BMan->Mlist2[0]=QPixmap(":/BMan0-.png");
    BMan->Mlist2[1]=QPixmap(":/BMan1-.png");
    BMan->Mlist2[2]=QPixmap(":/BMan2-.png");
    BMan->Slist1=QPixmap(":/BManRed.png");
    BMan->Slist2=QPixmap(":/BManRed-.png");
    BMan->Dlist1[0]=QPixmap(":/Dead.png");
    BMan->Dlist1[1]=QPixmap(":/DeadRed.png");
    BMan->Dlist2[0]=QPixmap(":/Dead-.png");
    BMan->Dlist2[1]=QPixmap(":/DeadRed-.png");
    QTimer::singleShot(BMan->time,this,[=](){
        BMan->moveBy(500,340);
        scene->addItem(BMan);
        mobsPool.append(BMan);
    });



    QTimer *timer01=new QTimer();//人物移动定时器
    timer01->start(100);
    connect(timer01,&QTimer::timeout,this,[=]()
            {
                if(AWoman->canMove&&!AWoman->dead)npcmove(AWoman);
                if(BWoman->canMove&&!BWoman->dead) npcmove(BWoman);
                if(AMan->canMove&&!AMan->dead) npcmove(AMan);
                if(BMan->canMove&&!BMan->dead)npcmove(BMan);
            });
    QTimer *timer02=new QTimer();//人物碰撞检测定时器
    timer02->start(100);
    connect(timer02,&QTimer::timeout,this,[=]()
            {
                //碰撞检测
                for(Mobs *mob:mobsPool)
                {
                    if(mob->x()-role->x()>=-15&&mob->x()-role->x()<=15&&mob->y()-role->y()<=30&&mob->y()-role->y()>=-30&&!mob->dead)
                    {
                        if(!role->beingprotected)
                            role->Hit();
                    }
                }
            });
    QTimer *timer03=new QTimer();//子弹碰撞检测定时器
    timer03->start(1);
    connect(timer03,&QTimer::timeout,this,[=]()
            {
                //碰撞检测
                for(Mobs *mob:mobsPool)
                {
                    for(Bullet *bullet:bulletPool)
                    {
                        if(bullet->isVisible()&&!mob->dead)
                        // 获取敌人和子弹的形状
                        { QPainterPath mobShape = mob->shape();
                            QPainterPath bulletShape = bullet->shape();

                            // 将敌人和子弹的形状移动到它们当前的位置
                            mobShape.translate(-mob->pos());
                            bulletShape.translate(-bullet->pos());

                            // 检测形状是否相交
                            if(mobShape.intersects(bulletShape)) {
                                // 如果相交，执行击中逻辑
                                bullet->hide();
                                mob->life--;
                                if(mob->beHit==false)
                                {mob->beingHit();}
                            }
                        }
                    }
                }
            });
    QTimer *timer04=new QTimer();//死亡的定时器
    timer04->start(300);
    connect(timer04,&QTimer::timeout,[=]()
            {
                for(Mobs *mob:mobsPool)
                {if(mob->dead&&mob->isVisible())
                        mob->die();
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
        mob->canMove=false;
        QTimer::singleShot(1500,this,[=]()
                           {
                               mob->canMove=true;
                           });
    }
}
//操作主人物
void Widget::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        //平移
        if (event->key() == Qt::Key_D)
        {
            role->direction = event->key();
            role->face=1;
            role->moving = true;role->face=1;
            role->timer1->start(50);
        }
        if(event->key() == Qt::Key_A)
        {
            role->direction = event->key();
            role->face=-1;
            role->moving = true;
            role->timer1->start(50);
        }
        //跳跃
        if(event->key()==Qt::Key_K)
        {
            role->timer2->start(50);
        }
        //攻击
        if(event->key()==Qt::Key_J&&!role->moving)
        {
            role->attacking=true;
            role->attack();
            for (Bullet *bullet : bulletPool) {
                if (!bullet->isVisible()) {
                    bullet->setPos(role->x(),role->y());
                    bullet->setdir(role->face);
                    bullet->show();
                    return; // 一次只发射一个子弹
                }
            }
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
