#ifndef SELECTWINDOW_H
#define SELECTWINDOW_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QString>
#include "variables.h"
#include "logics.h"

namespace Ui {
class selectwindow;
}
class gamegrapic;

class selectwindow : public QWidget
{
    Q_OBJECT

public:
    explicit selectwindow(QWidget *parent = nullptr);
    ~selectwindow();
    void show_selectdialog();
    void profile_change_male();
    void profile_change_female();
    Ui::selectwindow *ui;
    int num_choice;
    int count_bordercolor;
    int no_choose; //选择了第几项

    const QString BorderColor[6] = {"FFFFFF", "CCCCCC", "999999", "666666", "999999", "CCCCCC"};
    QTimer* timer_bordercolor;
protected:
    void keyPressEvent(QKeyEvent *event);
private:

private slots:
    void on_timer_bordercolor_triggerded();



};

#endif // SELECTWINDOW_H
