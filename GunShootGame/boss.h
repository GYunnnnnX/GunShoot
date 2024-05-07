#ifndef BOSS_H
#define BOSS_H
#include <QGraphicsItem>
#include<QPixmap>
#include<QPainter>
#include<QPainterPath>
#include<QKeyEvent>
#include<QEvent>
#include<QTimer>
#include"music.h"
class Boss : public QGraphicsItem
{
public:
    Boss();
    QRectF boundingRect() const override;
    QPainterPath shape()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    int face=-1;//脸的朝向
    QPixmap Slist1,Slist2;//击中帧
    QPixmap Dlist1[2];
    QPixmap Dlist2[2];//死亡帧
    int deadAni=0;
    bool dead=false;//死亡状态
    bool deadForALongTime=false;//是否死透
    QTimer *timer=new QTimer();//死亡计时器

    bool beHit=false;
    void beingHit();
    void die();
    int life=100;
    void reborn();//复活

    //技能
    bool inSkill3=false;
    int skilln=0;
    Music *music=new Music();
    QTimer *timer1=new QTimer();
    QTimer *timer2=new QTimer();
    QTimer *timer3=new QTimer();
protected:
private:

};

#endif // BOSS_H
