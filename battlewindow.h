#ifndef BATTLEWINDOW_H
#define BATTLEWINDOW_H

#include <QWidget>
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
signals:
    void stop_battletimer_event();
    void call_notices_event();
public slots:
    void start_battle(int& pos_target,int& id_enemy);

private:
    Ui::battlewindow *ui;
    int period_battle;
    int end_battle;
};

#endif // BATTLEWINDOW_H
