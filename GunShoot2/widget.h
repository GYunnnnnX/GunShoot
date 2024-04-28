#ifndef WIDGET_H
#define WIDGET_H
#include"role.h"
#include <QWidget>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QPixmap>
#include"mobs.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void keyPressEvent(QKeyEvent *event)override;
    void keyReleaseEvent(QKeyEvent *event)override;

    void npcmove(Mobs *mob);//自动移动

private:
    QList<Bullet *> bulletPool;
    QList<Mobs*>mobsPool;
    Role *role=new Role();//创建主人物
    QGraphicsScene *scene;//创建场景
    QGraphicsView *view;//创建视图
    QTimer *bulletTimer=new QTimer();
    Mobs *AWoman=new Mobs(2000,5,2);//创建。时间，速度，生命值
    Mobs *BWoman=new Mobs(5000,5,2);
    Mobs *AMan=new Mobs(10000,10,4);
    Mobs *BMan=new Mobs(20000,10,6);
    Ui::Widget *ui;
};
#endif // WIDGET_H

