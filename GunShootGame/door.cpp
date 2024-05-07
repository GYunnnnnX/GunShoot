#include "door.h"
#include<QKeyEvent>
#include<QPainter>
#include<QPainterPath>
#include<QDebug>
#include<QPixmap>
#include<QObject>
#include<QGraphicsItem>
QRectF Door::boundingRect()const
{
    return QRect(0, 0, 200, 200);
}
QPainterPath Door::shape() const
{
    QPainterPath path;
    path.addRect(0,0,200,200);
    return path;
}
void Door::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(isOpen)
    {painter->drawPixmap(0,0,200,200,QPixmap(":/dooropen.png"));}
    else{
        painter->drawPixmap(0,0,200,200,QPixmap(":/doorclosed.png"));
    }
}
void Door::open()
{
    isOpen=true;
    update();
}
void Door::close()
{
    isOpen=false;
    update();
}
bool Door::openOrNot()
{
    return isOpen;
}
