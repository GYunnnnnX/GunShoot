 #include "life.h"
#include<QKeyEvent>
#include<QPainter>
#include<QPainterPath>
#include<QDebug>
#include<QPixmap>
#include<QObject>
#include<QGraphicsItem>
QRectF Life::boundingRect()const
{
    return QRect(-20, -20, 40, 40);
}
QPainterPath Life::shape() const
{
    QPainterPath path;
    path.addRect(-20,-20,40,40);
    return path;
}
void Life::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-20,-20,40,40,QPixmap(":/heart.png"));
}
