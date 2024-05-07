#ifndef ROLE_H
#define ROLE_H
#include"bullet.h"
#include <QGraphicsItem>
#include<QPixmap>
#include<QPainter>
#include<QPainterPath>
#include<QKeyEvent>
#include<QFocusEvent>
#include<QEvent>
#include<QTimer>
#include<QGraphicsItemAnimation>
class Role : public QGraphicsItem
{
public:
    Role();
    QRectF boundingRect() const override;
    QPainterPath shape()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    //移动
    QTimer *timer1=new QTimer();//平移计时器
    int n=0;//帧数
    QPixmap list1[6];//前进帧照片
    QPixmap list2[6];//后退帧照片
    void move();//移动函数
    int direction;//移动方向
    bool moving=false;//移动状态
    int face=1;//脸的朝向

    //跳跃
    QTimer *timer2=new QTimer();//跳跃计时器
    void jump();
    int t=0;

    //受击
    QTimer *blood=new QTimer();//生命计时器
    bool beingHit=false;//受击状态
    void Hit();//受击函数
    bool beingprotected=false;//是否处于无敌状态

    //攻击
    void attack();//攻击函数
    bool attacking =false;//攻击状态

    int getLife();
    void changeLife(int n);
    void reborn();
private:
    int life=7;//生命值

protected:

};

#endif // ROLE_H
