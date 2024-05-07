 #include "role.h"
#include<QKeyEvent>
#include<QPainter>
#include<QPainterPath>
#include<QDebug>
#include<QPixmap>
#include<QGraphicsItem>
#include<QGraphicsItemAnimation>
#include<QObject>
#include<QTimeLine>
#include<QPainterPath>
#include<QTimer>
#include"bullet.h"
QRectF Role::boundingRect()const
{
    // 返回一个矩形，用于指定项目的边界
    return QRect(0, 0, 50, 50);
}
QPainterPath Role::shape() const
{
    QPainterPath path;
    path.addRect(0,0,50,50);
    return path;
}
void Role::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(beingHit)
    {
        if(face==1)
            painter->drawPixmap(0,0,50,50,QPixmap(":/beingHit.png"));
        if(face==-1)
            painter->drawPixmap(0,0,50,50,QPixmap(":/beingHit-.png"));
    }
    else if(attacking)
    {
        if(face==1)
            painter->drawPixmap(0,0,50,50,QPixmap(":/attack.png"));
        if(face==-1)
            painter->drawPixmap(0,0,50,50,QPixmap(":/attack-.png"));
    }
    else{
        if(face==1)
            painter->drawPixmap(0,0,50,50,list1[n]);
        if(face==-1)
            painter->drawPixmap(0,0,50,50,list2[n]);
    }
}
Role::Role()
{
    list1[0]=QPixmap(":/Chen0.png");
    list1[1]=QPixmap(":/Chen1.png");
    list1[2]=QPixmap(":/Chen2.png");
    list1[3]=QPixmap(":/Chen3.png");
    list1[4]=QPixmap(":/Chen4.png");
    list1[5]=QPixmap(":/Chen5.png");
    list2[0]=QPixmap(":/Chen0-.png");
    list2[1]=QPixmap(":/Chen1-.png");
    list2[2]=QPixmap(":/Chen2-.png");
    list2[3]=QPixmap(":/Chen3-.png");
    list2[4]=QPixmap(":/Chen4-.png");
    list2[5]=QPixmap(":/Chen5-.png");

    blood->start(500);//生命计时器启动
}
void Role::move()//移动函数
{
    if (moving&&!beingHit&&this->life!=0) {
        switch (direction)
        {
        case Qt::Key_A:
            if(this->x()>=0)
                this->moveBy(-10,0);
            break;
        case Qt::Key_D:
            if(this->x()<=1119)
                this->moveBy(+10,0);
            break;
        case Qt::Key_W:
            this->moveBy(0,-10);
            break;
        case Qt::Key_S:
            this->moveBy(0,+10);
            break;
        }
    }
    this->update();
}
void Role::Hit()//受击函数
{
    beingHit=true;
    update();
    beingprotected=true;
    life--;
    QTimer::singleShot(500,[=]()
                       {
                           beingHit=false;
                       });
    QTimer::singleShot(1500,[=]()
                       {
                           beingprotected=false;
                       });
}
void Role::jump()//跳跃函数
{
    if(!beingHit)
    {  t++;
        int h=(7-t)*(7-t);
        if(t<=7)
            this->moveBy(0,-h);
        if(t>7)
            this->moveBy(0,+h);
        if(t==13)
        {timer2->stop();
            t=0;}}
}
void Role::attack()//攻击函数
{
    this->update();
    QTimer::singleShot(150,[=]()
                       {
                           attacking=false;
                           this->update();
                       }) ;
}
int Role::getLife()
{
    return life;
}
void Role::reborn()
{
    life=7;
    face=1;
    attacking=false;
    n=0;
    moving=false;
    beingprotected=false;
    beingHit=false;
    update();
}
