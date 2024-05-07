#ifndef RULE_H
#define RULE_H

#include <QWidget>
#include<QPushButton>
#include<QEvent>
#include<QLabel>
class Rule : public QWidget
{
    Q_OBJECT
public:
    explicit Rule(QWidget *parent = nullptr);
    QLabel *label=new QLabel();
    QPushButton *backButton=new QPushButton();
signals:
};

#endif // RULE_H
