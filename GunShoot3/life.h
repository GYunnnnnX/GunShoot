#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsItem>

class Life : public QGraphicsItem
{
public:
    QRectF boundingRect() const override;
    QPainterPath shape()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
signals:
};

#endif // LIFE_H
