#ifndef DATADISPLAY_H
#define DATADISPLAY_H

#include <QWidget>
#include <QLabel>
#include<QString>
#include<QTimer>
#include"variables.h"
namespace Ui {
class datadisplay;
}

class datadisplay : public QWidget
{
    Q_OBJECT

public:
    explicit datadisplay(QWidget *parent = nullptr);
    ~datadisplay();
    void init_datadisplay();
public slots:
    void update_datadisplay();     //更新数据显示

private:
    Ui::datadisplay *ui;
    QTimer *timer_update;
};

#endif // DATADISPLAY_H
