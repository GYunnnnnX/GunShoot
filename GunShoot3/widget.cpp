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
#include<QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("周处除三害");
    setFixedSize(600,400);
    setWindowIcon(QIcon(":/Icon.png"));

    //设置场景
    scene=new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);//设置索引方法

    //为场景添加视图
    view=new QGraphicsView(scene,this);
    view->setRenderHint(QPainter::Antialiasing);//反锯齿
    view->setBackgroundBrush(QPixmap(":/background1.png"));//添加背景图片
    QPixmap pix=QPixmap(":/background1.png");
    w=pix.width(),h=pix.height();
    scene->setSceneRect(0, 0,w, h);//设置场景矩形
    //添加主人公
    scene->addItem(role);
    role->setZValue(3);

    //添加爱心
    for(int i=0;i<7;i++)
    {
        scene->addItem(&life[i]);
        life[i].setPos(i*30+15,15);
    }

    //添加门
    scene->addItem(door);
    door->setZValue(1);
    door->moveBy(500,150);

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
                QPointF viewCenter = view->mapToScene(0,0); //让爱心跟随移动
                for(int i=0;i<7;i++)
                {
                    life[i].setPos(viewCenter);
                    life[i].moveBy(i*30+15,15);
                }

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
                    if(bullet->x()<-15||bullet->x()>1119)
                    {
                        bullet->hide();bullet->moveBy(0,-100);
                    }
                }
            });
    bulletTimer->start(50);

    //对象池循环调用
    recordOfAllMobsNumber=AWoman->num+BWoman->num+AMan->num+BMan->num;
    connect(timer0,&QTimer::timeout,this,[=]()
            {
                for(Mobs *mob:mobsPool)
                {
                    if(!mob->isVisible()&&mob->num!=1)
                    {
                        mob->num--;
                        mob->dead=false;
                        mob->canMove=true;
                        mob->beHit=false;
                        mob->deadAni=0;
                        mob->life=mob->lifeRecord;
                        mob->setPos(500,340);
                        mob->show();
                    }
                }
                if(Mobs::killNumber==recordOfAllMobsNumber)
                {
                    door->open();
                }
            });

    //创建npc
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
        AWoman->setZValue(1);
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
        BWoman->setZValue(1);
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
        AMan->setZValue(1);
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
        BMan->setZValue(1);
        mobsPool.append(BMan);
        timer0->start(2000);//npc复活定时器启动
    });

    timer01->start(100);//npc移动定时器启动
    connect(timer01,&QTimer::timeout,this,[=]()
            {
                if(AWoman->canMove&&!AWoman->dead)npcmove(AWoman);
                if(BWoman->canMove&&!BWoman->dead) npcmove(BWoman);
                if(AMan->canMove&&!AMan->dead) npcmove(AMan);
                if(BMan->canMove&&!BMan->dead)npcmove(BMan);
            });

    timer02->start(100);//npc碰撞检测定时器启动
    connect(timer02,&QTimer::timeout,this,[=]()
            {
                for(Mobs *mob:mobsPool)
                {
                    if(mob->x()-role->x()>=-15&&mob->x()-role->x()<=15&&mob->y()-role->y()<=30&&mob->y()-role->y()>=-30&&!mob->dead)
                    {
                        if(!role->beingprotected)
                        {role->Hit();}
                        if(role->getLife()>=0)
                            life[role->getLife()].hide();//受击事件
                    }
                    if(role->getLife()==0)
                    {
                        deadWindow->show();
                        role->moveBy(0,-300);
                        timer02->stop();
                        role->timer1->stop();
                        role->timer2->stop();
                    }
                }
            });

    timer03->start(1);//子弹碰撞检测定时器启动
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
                                if(mob->beHit==false)
                                {mob->beingHit();}
                            }
                        }
                    }
                }
            });

    timer04->start(300);//npc死亡动画定时器启动
    connect(timer04,&QTimer::timeout,this,[=]()
            {
                for(Mobs *mob:mobsPool)
                {if(mob->dead&&mob->isVisible())
                        mob->die();
                }
            });


    connect(deadWindow->exitButton,&QPushButton::clicked,[=]()//退出游戏
            {
                deadWindow->close();
                this->close();
            });
    connect(deadWindow->restartButton,&QPushButton::clicked,[=]()//重新开始
            {
                role->reborn();
                role->setPos(50,340);
                view->centerOn(role);
                update();
                deadWindow->hide();
                for(int i=0;i<7;i++)
                {
                    life[i].show();
                    life[i].setPos(i*30+15,15);
                }
                AWoman->reborn();AWoman->hide();
                BWoman->reborn();BWoman->hide();
                AMan->reborn();AMan->hide();
                BMan->reborn();BMan->hide();
                timer0->stop();
                QTimer::singleShot(AWoman->time,this,[=](){
                    AWoman->setPos(500,340);
                    AWoman->show();
                    timer02->start(100);
                });
                QTimer::singleShot(BWoman->time,this,[=](){
                    BWoman->setPos(500,340);
                    BWoman->show();
                });
                QTimer::singleShot(AMan->time,this,[=](){
                    AMan->setPos(500,340);
                    AMan->show();
                });
                QTimer::singleShot(BMan->time,this,[=](){
                    BMan->setPos(500,340);
                    BMan->show();
                    timer0->start(2000);
                });
            }
            );


    //第二关
    connect(timer201,&QTimer::timeout,this,[=]()
            {
                if(boss->x()<=role->x())
                {boss->face=1;}
                else
                {boss->face=-1;}
                boss->update();
            }
            );






}

Widget::~Widget()
{
    delete ui;
}

//npc移动
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
                    bullet->setPos(role->x()+role->face*10,role->y()+2.5);
                    bullet->setdir(role->face);
                    bullet->show();
                    return; // 一次只发射一个子弹
                }
            }
        }
        if(event->key()==Qt::Key_W&&door->openOrNot()&&role->x()>=550&&role->x()<=600)
        {
            if(role->y()==340)
                TheSecond();//第二关进入
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
void Widget::TheSecond()//第二关初始化函数
{
    //关闭第一关的东西
    delete AWoman;
    delete  BWoman;
    delete AMan;
    delete BMan;
    role->reborn();
    role->setPos(50,340);
    view->centerOn(role);
    update();
    deadWindow->hide();
    for(int i=0;i<7;i++)
    {
        life[i].show();
        life[i].setPos(i*30+15,15);
    }
    timer0->stop();
    timer01->stop();
    timer02->stop();
    timer03->stop();
    timer04->stop();
    door->hide();

    //第二关的背景
    QPixmap pix=QPixmap(":/background2.png");
    pix=pix.scaled(w,h+150);
    view->setBackgroundBrush(pix);
    scene->setSceneRect(0, 0,w, h);

    //Boss出场
    QTimer::singleShot(5000,this,[=]()
                       {
                           scene->addItem(boss);
                           boss->moveBy(550,340);
                       });
    timer201->start(2000);
}
