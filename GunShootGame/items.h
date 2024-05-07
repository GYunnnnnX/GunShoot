#ifndef ITEMS_H
#define ITEMS_H

#include <QGraphicsItem>

class Items : public QGraphicsItem
{
public:
    QRectF boundingRect() const override;
    QPainterPath shape()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    Items(int n);
    int n;
    QPixmap pix;
signals:
};

#endif // ITEMS_H
