#ifndef GAMEGRAPIC_H
#define GAMEGRAPIC_H

#include <QWidget>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMessageBox>

#include"enum.h"
#include"logics.h"
#include"variables.h"
#include"datadisplay.h"
#include"noticewindow.h"
#include"selectwindow.h"
#include"battlewindow.h"

namespace Ui {
class gamegrapic;
}

class gamegrapic : public QWidget
{
    Q_OBJECT

public:
    explicit gamegrapic(QWidget *parent = nullptr);
    ~gamegrapic();
    void init_grapic();


protected:
    QTimer* timer_update;
    QTimer* timer_cut;
    QTimer* timer_battle;
    QTimer* timer_pickupitem;
    QTimer* timer_notice;

    QImage img_floor;
    QImage img_wall[3];
    QImage img_upstairs;
    QImage img_downstairs;
    QImage img_yellowdoor;
    QImage img_bluedoor;
    QImage img_reddoor;
    QImage img_jaildoor;
    QImage img_cyandoor;
    QImage img_enemy[TOTAL_enemy];
    QImage img_hero[4][4];
    QImage img_store[3];
    QImage img_yellowkey;
    QImage img_bluewkey;
    QImage img_redkey;
    QImage img_redbottle;
    QImage img_bluebottle;
    QImage img_redgem;
    QImage img_bluegem;
    QImage img_ironsword;
    QImage img_ironshied;
    QImage img_oldnpc;
    QImage img_tradernpc;
    QImage img_thiefnpc;

    QGraphicsScene *scene_storey;
    QGraphicsPixmapItem **pixmap_items;

    noticewindow *NoticeWindow;
    selectwindow *SelectWindow;
    battlewindow *BattleWindow;

    void keyPressEvent(QKeyEvent *event);
protected slots:
    void on_timer_update_triggered();
    //void on_timer_cut_triggered();
    //void on_timer_pickupitem_triggered();
    //void on_timer_notice_triggered();
    void update_grapic();
public slots:
    void stop_battle_timer();
    void notice_after_battle();

private:
    Ui::gamegrapic *ui;
    int id_temp_enemy;
    int pos_battle;
    int count_keyup;
    bool leftright_step;
    int count_stairs;
};

#endif // GAMEGRAPIC_H
