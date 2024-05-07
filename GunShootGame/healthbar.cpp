#include "healthbar.h"
#include<QKeyEvent>
#include<QPainter>
#include<QPainterPath>
#include<QDebug>
#include<QPixmap>
#include<QObject>
#include<QGraphicsItem>
QRectF HealthBar::boundingRect()const
{
    return QRect(0, 0, width, height);
}
QPainterPath HealthBar::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, width, height);
    return path;
}
void HealthBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(0, 0, width, height);
    painter->setBrush(Qt::red);//血条行
    painter->drawRect(0, 0, width * currentLife / maxLife, height);
}

