#include "mobs.h"
#include<QKeyEvent>
#include<QPainter>
#include<QPainterPath>
#include<QDebug>
#include<QPixmap>
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
    if(face==1)
        painter->drawPixmap(0,0,50,50,Mlist1[n]);
    if(face==-1)
        painter->drawPixmap(0,0,50,50,Mlist2[n]);
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
