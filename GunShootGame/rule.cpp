#include <QApplication>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QPoint>
#include<QPixmap>
#include<QPainter>
#include<QTimer>
#include "rule.h"

Rule::Rule(QWidget *parent)
    : QWidget{parent}
{
    this->setWindowTitle("周处除三害");
    this->setFixedSize(600,400);
    // 创建一个 QFont 对象用于设置字体
    QFont font1;
    font1.setFamily("Arial");
    font1.setPointSize(15);
    font1.setBold(true);


    // 创建一个 QFont 对象用于设置字体
    QFont font2;
    font2.setFamily("Arial");
    font2.setPointSize(22);
    font2.setBold(true);
    label->setText("'A'向左移动，'D'向右移动，'J'发射子弹，'K'跳跃.....                                    “杀掉所有人”");
    label->setFont(font2);
    label->setWordWrap(true);
    label->setStyleSheet("color: black;");
    label->setParent(this);
    label->setGeometry(60, 10, 500, 200);
    backButton->setParent(this);
    backButton->setGeometry(270,320,100,60);
    backButton->setText("返回");
    backButton->setFont(font1);

}
