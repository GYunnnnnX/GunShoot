#ifndef STARTWINDOW_H
#define STARTWINDOW_H
#include <QWidget>
#include<QPushButton>
#include<QEvent>
#include<QLabel>
#include"rule.h"
class StartWindow : public QWidget
{
    Q_OBJECT
public:
    explicit StartWindow(QWidget *parent = nullptr);
    QPushButton *exitButton=new QPushButton();//退出按钮
    QPushButton *startButton=new QPushButton();//开始按钮
    QPushButton *ruleButton=new QPushButton();//规则按钮
    QLabel *label=new QLabel();
    Rule r;
    void showRule();
    void paintEvent(QPaintEvent *event) override;
signals:
};

#endif // STARTWINDOW_H
