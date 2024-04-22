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
    QGraphicsScene *scene;//创建场景
    QGraphicsView *view;//创建视图
    Role *role=new Role();//创建主人物
    Mobs *AWoman=new Mobs(2000,5,2);//创建各种教徒
    Mobs *BWoman=new Mobs(5000,5,2);
    Mobs *AMan=new Mobs(10000,10,4);
    Mobs *BMan=new Mobs(20000,10,6);
    void npcmove(Mobs *mob);//移动
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
