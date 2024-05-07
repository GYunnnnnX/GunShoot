#include "boss.h"
#include<QKeyEvent>
#include<QPainter>
#include<QPainterPath>
#include<QDebug>
#include<QPixmap>
#include<QGraphicsItem>
QRectF Boss::boundingRect()const
{
    return QRect(0, 0, 50, 50);
}
QPainterPath Boss::shape() const
{
    QPainterPath path;
    path.addRect(0,0,50,50);
    return path;
}
void Boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(face==1)
    {painter->drawPixmap(0,0,50,50,QPixmap(":/Boss0.png"));}
    if(face==-1)
    {
        painter->drawPixmap(0,0,50,50,QPixmap(":/Boss0-.png"));
    }
}
Boss::Boss()
{
}
