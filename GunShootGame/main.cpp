#include "widget.h"
#include <QApplication>
#include<QTimer>
#include"startwindow.h"
#include"rule.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow start;
    start.show();
    Widget w;
    Rule r;
    QObject::connect(start.exitButton,&QPushButton::clicked,[=]()
                     {
                         QApplication::quit();
                     });
    QObject::connect(start.startButton,&QPushButton::clicked,&start,&QWidget::hide);
    QObject::connect(start.startButton,&QPushButton::clicked,&w,&Widget::show);
    QObject::connect(start.startButton,&QPushButton::clicked,&w,&Widget::startGame);
    QObject::connect(start.ruleButton,&QPushButton::clicked,&start,&StartWindow::showRule);
    QObject::connect(start.r.backButton,&QPushButton::clicked,&start.r,&QWidget::hide);
    return a.exec();
}
