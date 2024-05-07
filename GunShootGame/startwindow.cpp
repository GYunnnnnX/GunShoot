#include "startwindow.h"
#include <QApplication>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QPoint>
#include<QPixmap>
#include<QPainter>
#include<QTimer>
StartWindow::StartWindow(QWidget *parent)
    : QWidget{parent}
{
    this->setWindowTitle("周处除三害");
    this->setFixedSize(600,400);
    setWindowTitle("周处除三害");
    setFixedSize(600,400);
    setWindowIcon(QIcon(":/Icon.png"));
    // 创建QFont对象用于设置字体
    QFont font1;
    font1.setFamily("Arial");
    font1.setPointSize(15);
    font1.setBold(true);
    QFont font2;
    font2.setFamily("STXingkai");
    font2.setPointSize(36);
    font2.setBold(true);
    label->setText("下一发，绝不卡壳！");
    label->setFont(font2);
    label->setStyleSheet("color: black;");
    label->setParent(this);
    label->setGeometry(75, 90, 600, 100);


    exitButton->setParent(this);
    startButton->setParent(this);
    ruleButton->setParent(this);
    exitButton->setGeometry(490, 320, 100, 60); // 设置退出按钮位置和大小
    startButton->setGeometry(380, 320, 100, 60); // 设置重启按钮位置和大小
    ruleButton->setGeometry(270,320,100,60);//设置规则按钮位置和大小
    ruleButton->setText("规则");
    ruleButton->setFont(font1);
    exitButton->setText("退出游戏");
    exitButton->setFont(font1);
    startButton->setText("开始游戏");
    startButton->setFont(font1);
}
void StartWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix=QPixmap(":/background.png");
    painter.drawPixmap(-20,-30,620,440,pix);
}
void StartWindow::showRule()
{
    r.show();
}
