#include "bullet.h"
#include<QObject>
Bullet::Bullet()
{
}
QRectF Bullet::boundingRect()const
{
    return QRect(0, 0,50, 50);
}
QPainterPath Bullet::shape() const
{
    QPainterPath path;
    path.addRect(22.5,22.5,5,5);
    return path;
}
void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,50,50,QPixmap(":/bullet.png"));
}
void Bullet::setdir(int f)
{
    dir=f;
}
void Bullet::move()
{
    this->moveBy(dir*25,0);
}
