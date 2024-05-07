#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QGraphicsItem>

class HealthBar : public QGraphicsItem
{
public:
    QRectF boundingRect() const override;
    QPainterPath shape()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    int currentLife=100;
private:
    int height=4;
    int maxLife=100;
    int width=200;
signals:
};

#endif // HEALTHBAR_H
