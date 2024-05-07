#include "deadwindow.h"

#include <QApplication>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QPoint>
#include<QImage>
#include<QPainter>
#include<QTimer>
DeadWindow::DeadWindow(QWidget *parent)
    : QWidget{parent}
{
    this->setWindowTitle("死亡");
    this->setFixedSize(300,200);
    // 创建一个 QFont 对象用于设置字体
    QFont font1;
    font1.setFamily("Arial");
    font1.setPointSize(15);
    font1.setBold(true);


    // 创建一个 QFont 对象用于设置字体
    QFont font2;
    font2.setFamily("STXingkai");
    font2.setPointSize(36);
    font2.setBold(true);
    label->setText("您死了");
    label->setFont(font2);
    label->setStyleSheet("color: black;");
    label->setParent(this);
    label->setGeometry(75, 10, 250, 100);


    exitButton->setParent(this);
    restartButton->setParent(this);
    exitButton->setGeometry(25, 110, 100, 60); // 设置退出按钮位置和大小
    restartButton->setGeometry(175, 110, 100, 60); // 设置重启按钮位置和大小

    exitButton->setText("退出游戏");
    exitButton->setFont(font1);
    restartButton->setText("重新开始");
    restartButton->setFont(font1);
}
