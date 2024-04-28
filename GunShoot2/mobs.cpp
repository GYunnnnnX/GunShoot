#include "mobs.h"
#include<QKeyEvent>
#include<QPainter>
#include<QPainterPath>
#include<QDebug>
#include<QPixmap>
#include<QObject>
#include<QGraphicsItem>
QRectF Mobs::boundingRect()const
{
    return QRect(0, 0, 50, 50);
}
QPainterPath Mobs::shape() const
{
    QPainterPath path;
    path.addRect(0,0,50,50);
    return path;
}
void Mobs::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(dead&&isVisible())
    {if(deadAni==1&&face==1)
        {
            painter->drawPixmap(0,0,50,50,Dlist1[0]);return;
        }
        if(deadAni==2&&face==1)
        {
            painter->drawPixmap(0,0,50,50,Dlist1[1]);return;
        }
        if(deadAni==3&&face==1)
        {
            painter->drawPixmap(0,0,50,50,Dlist1[0]);return;
        }
        if(deadAni==4&&face==1)
        {
            painter->drawPixmap(0,0,50,50,Dlist1[1]);return;
        }
        if(deadAni==1&&face==-1)
        {
            painter->drawPixmap(0,0,50,50,Dlist2[0]);return;
        }
        if(deadAni==2&&face==-1)
        {
            painter->drawPixmap(0,0,50,50,Dlist2[1]);return;
        }
        if(deadAni==3&&face==-1)
        {
            painter->drawPixmap(0,0,50,50,Dlist2[0]);return;
        }
        if(deadAni==4&&face==-1)
        {
            painter->drawPixmap(0,0,50,50,Dlist2[1]);return;
        }
    }
    if(beHit)
    {
        if(face==1)
            painter->drawPixmap(0,0,50,50,Slist1);
        if(face==-1)
            painter->drawPixmap(0,0,50,50,Slist2);
    }
    else
    {if(face==1)
            painter->drawPixmap(0,0,50,50,Mlist1[n]);
        if(face==-1)
            painter->drawPixmap(0,0,50,50,Mlist2[n]);
    }
}
Mobs::Mobs(int t,int v,int l)//产生时间，移动速度，生命值
{
    this->time=t;
    this->speed=v;
    this->life=l;
}
void Mobs::move(int x)//移动速度
{
    if(this->pos().rx()>x)
    {
        face=-1;
        this->moveBy(-this->speed/2,0);
    }
    else
    {
        face=1;
        this->moveBy(this->speed/2,0);
    }
    this->update();
}
void Mobs::beingHit()
{
    beHit=true;
    canMove=false;
    update();
    if(life==0){QTimer::singleShot(100,[=](){dead=true;return;});}
    QTimer::singleShot(1000,[=](){beHit=false;canMove=true;this->update();});
}
void Mobs::die()
{
    deadAni++;update();
    if(deadAni==5)this->hide();
}
