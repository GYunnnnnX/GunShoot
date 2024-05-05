#ifndef DOOR_H
#define DOOR_H

#include <QGraphicsItem>

class Door : public QGraphicsItem
{
public:
    QRectF boundingRect() const override;
    QPainterPath shape()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void open();//把门打开
    void close();//把门关闭
    bool openOrNot();
private:
    bool isOpen=false;//门是否开着
signals:
};

#endif // DOOR_H
