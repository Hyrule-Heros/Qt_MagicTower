#ifndef BATTLEWINDOW_H
#define BATTLEWINDOW_H

#include <QWidget>
#include <QTimer>
#include "variables.h"
#include"logics.h"

namespace Ui {
class battlewindow;
}

class battlewindow : public QWidget
{
    Q_OBJECT

public:
    explicit battlewindow(QWidget *parent = nullptr);
    ~battlewindow();
    void start_battle(int& pos_target,int& id_enemy);

signals:
    void stop_battletimer_event();
    void call_notices_event();
public slots:
    void on_timer_battle_triggerd();

private:
    Ui::battlewindow *ui;
    int period_battle;
    int end_battle;
    int pos_target_temp;
    int id_enemy_temp;
    QTimer *timer_battle;
};

#endif // BATTLEWINDOW_H
