#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include <QGraphicsItem>
#include<QPixmap>
#include<QPainter>
#include<QPainterPath>
#include<QKeyEvent>
#include<QEvent>
#include<QTimer>
#include<QObject>
class Bullet : public QGraphicsItem
{
public:Bullet();
    QRectF boundingRect() const override;
    QPainterPath shape()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void move();//子弹移动函数
    void setdir(int dir);

private:
    int dir=1;
};

#endif // BULLET_H
