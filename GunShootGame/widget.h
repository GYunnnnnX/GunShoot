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
#include"healthbar.h"
#include"music.h"
#include"items.h"
#include<QRandomGenerator>
#include<QPushButton>
#include<QLabel>
#include<QPropertyAnimation>
#include<QGraphicsOpacityEffect>
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
    int nowChallenge=1;
    void startGame();//开始游戏

    QPushButton *button=new QPushButton();//结束按钮
    QLabel *label=new QLabel();//结束语
    // 动画
    QPropertyAnimation *animation=new QPropertyAnimation(label,"geometry");



    void skill1();
    void skill2();
    void skill3();//技能逻辑
    void Formskill1();
    void Formskill2();
    void Formskill3();//技能形式
private:
    QList<Bullet *> bulletPool;//创建子弹池
    QList<Items*> itemPool;//创建道具池
    Music music[5];//创建音乐数组
    QList<Mobs*>mobsPool;//创建npc对象池
    Role *role=new Role();//创建主人物
    QGraphicsScene *scene;//创建场景
    QGraphicsView *view;//创建视图
    Door *door=new Door();//创建门
    DeadWindow *deadWindow=new DeadWindow();//创建死亡窗口
    Life life[7];//创建爱心
    Boss *boss=new Boss();//创建吉他女
    HealthBar *healthBar=new HealthBar();
    int w;
    int h;
    QRandomGenerator *generator1 = QRandomGenerator::global();
    QRandomGenerator *generator2 = QRandomGenerator::global();
    QTimer *bulletTimer=new QTimer();//子弹移动定时器
    //第一关
    QTimer *timer0=new QTimer();//复活npc定时器
    QTimer *timer01=new QTimer();//npc移动定时器
    QTimer *timer02=new QTimer();//npc碰撞检测定时器
    QTimer *timer03=new QTimer();//子弹击中npc碰撞检测定时器
    QTimer *timer04=new QTimer();//npc死亡动画的定时器
    //第二关
    void TheSecond();//第二关初始化
    QTimer *timer201=new QTimer();//boss转向定时器
    QTimer *timer202=new QTimer();//boss碰撞检测定时器
    QTimer *timer203=new QTimer();//子弹击中boss碰撞检测定时器
    QTimer *timer204=new QTimer();//boss死亡动画定时器
    QTimer *barTimer=new QTimer();//boss血条定时器
    QTimer *skillTimer=new QTimer();//技能计时器
    QTimer *musicTimer=new QTimer();//音乐碰撞检测定时器
    QTimer *itemsTimer=new QTimer();//道具随机生成定时器


    Mobs *AWoman=new Mobs(2000,20,3,15);//时间，速度，生命值,数量
    Mobs *BWoman=new Mobs(5000,20,5,15);
    Mobs *AMan=new Mobs(5000,15,9,10);
    Mobs *BMan=new Mobs(10000,10,15,4);
    Ui::Widget *ui;
};
#endif // WIDGET_H
