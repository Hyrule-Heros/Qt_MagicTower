#ifndef NOTICEWINDOW_H
#define NOTICEWINDOW_H

#include <QWidget>
#include <QString>
#include <QTimer>
#include "variables.h"
#include"enum.h"

namespace Ui {
class noticewindow;
}

class noticewindow : public QWidget
{
    Q_OBJECT

public:
    explicit noticewindow(QWidget *parent = nullptr);
    ~noticewindow();
    void display_info(QString info);

private:
    Ui::noticewindow *ui;
    QTimer* timer_close;

private slots:
    void on_timer_close();
};

#endif // NOTICEWINDOW_H
