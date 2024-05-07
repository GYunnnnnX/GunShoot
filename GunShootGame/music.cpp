#include "music.h"
#include<QKeyEvent>
#include<QPainter>
#include<QPainterPath>
#include<QDebug>
#include<QPixmap>
#include<QObject>
#include<QGraphicsItem>
QRectF Music::boundingRect()const
{
    return QRect(0, 0, 70, 70);
}
QPainterPath Music::shape() const
{
    QPainterPath path;
    path.addRect(0,0,70,70);
    return path;
}
void Music::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,70,70,QPixmap(":/music.png"));
}
void Music::setDir(double x,double y)
{
    dirx=x;diry=y;
}
void Music::move()
{
    if(this->isVisible())
    {this->moveBy(dirx*30,diry*30);}
}
