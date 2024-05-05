 #ifndef BOSS_H
#define BOSS_H
#include <QGraphicsItem>
#include<QPixmap>
#include<QPainter>
#include<QPainterPath>
#include<QKeyEvent>
#include<QEvent>
#include<QTimer>
class Boss : public QGraphicsItem
{
public:
    Boss();
    QRectF boundingRect() const override;
    QPainterPath shape()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    int face=-1;//脸的朝向
protected:
private:

};

#endif //BOSS_H
