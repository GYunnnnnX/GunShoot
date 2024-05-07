#ifndef MUSIC_H
#define MUSIC_H

#include <QGraphicsItem>
class Music : public QGraphicsItem
{
public:
    QRectF boundingRect() const override;
    QPainterPath shape()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setDir(double x,double y);
    void move();
private:
    double dirx;
    double diry;
signals:
};

#endif // MUSIC_H
