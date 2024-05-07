#include "items.h"
#include<QKeyEvent>
#include<QPainter>
#include<QPainterPath>
#include<QDebug>
#include<QPixmap>
#include<QObject>
#include<QGraphicsItem>
Items::Items(int n)
{
    if(n==1)
    {
        pix=QPixmap(":/apple.png");
    }
    if(n==2)
    {
        pix=QPixmap(":/knife.png");
    }
    this->n=n;
}
QRectF Items::boundingRect()const
{
    return QRect(0, 0, 40, 40);
}
QPainterPath Items::shape() const
{
    QPainterPath path;
    path.addRect(0,0,40,40);
    return path;
}
void Items::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,40,40,pix);
}

