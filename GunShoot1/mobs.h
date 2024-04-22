#ifndef MOBS_H
#define MOBS_H


#include <QGraphicsItem>
#include<QPixmap>
#include<QPainter>
#include<QPainterPath>
#include<QKeyEvent>
#include<QFocusEvent>
#include<QEvent>
#include<QTimer>
class Mobs : public QGraphicsItem
{
public:
    Mobs(int t,int v,int l);//产生的时间，移动速度，生命值
    QRectF boundingRect() const override;
    QPainterPath shape()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPixmap Mlist1[3];//前进移动帧
    QPixmap Mlist2[3];//后退移动帧
    int face=1;//脸朝向
    int n=0;//序列数
    int time;//产生时间
    int speed;//移动速度
    int canmove=true;//判断是否可以移动
    int life;//生命值
    void move(int x);
protected:

};

#endif // MOBS_H
