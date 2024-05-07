#ifndef DEADWINDOW_H
#define DEADWINDOW_H

#include <QWidget>
#include<QPushButton>
#include<QEvent>
#include<QLabel>
class DeadWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DeadWindow(QWidget *parent = nullptr);
    QPushButton *exitButton=new QPushButton();
    QPushButton *restartButton=new QPushButton();
    QLabel *label=new QLabel();
signals:
};

#endif // DEADWINDOW_H
