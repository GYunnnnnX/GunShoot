 #ifndef WIDGET_H
#define WIDGET_H
#include"role.h"
#include"bullet.h"
#include <QWidget>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QPixmap>
#include"mobs.h"
#include"door.h"
#include"life.h"
#include"boss.h"
#include"deadwindow.h"
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
    int recordOfAllMobsNumber=0;
private:
    QList<Bullet *> bulletPool;//创建子弹池
    QList<Mobs*>mobsPool;//创建npc对象池
    Role *role=new Role();//创建主人物
    QGraphicsScene *scene;//创建场景
    QGraphicsView *view;//创建视图
    Door *door=new Door();//创建门
    DeadWindow *deadWindow=new DeadWindow();//创建死亡窗口
    Life life[7];//创建爱心
    Boss *boss=new Boss();//创建吉他女
    int w;
    int h;

    QTimer *bulletTimer=new QTimer();//子弹移动定时器
    //第一关
    QTimer *timer0=new QTimer();//复活npc定时器
    QTimer *timer01=new QTimer();//npc移动定时器
    QTimer *timer02=new QTimer();//npc碰撞检测定时器
    QTimer *timer03=new QTimer();//子弹与npc碰撞检测定时器
    QTimer *timer04=new QTimer();//npc死亡动画的定时器
    //第二关
    void TheSecond();//第二关初始化
    QTimer *timer201=new QTimer();//boss转向定时器

    Mobs *AWoman=new Mobs(2000,20,1,2);//时间，速度，生命值,数量
    Mobs *BWoman=new Mobs(5000,20,1,2);
    Mobs *AMan=new Mobs(5000,15,1,2);
    Mobs *BMan=new Mobs(10000,10,2,2);
    Ui::Widget *ui;
};
#endif // WIDGET_H
