#include "noticewindow.h"
#include "ui_noticewindow.h"

noticewindow::noticewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::noticewindow)
{
    ui->setupUi(this);
    timer_close = new QTimer(this);
}

noticewindow::~noticewindow()
{
    delete ui;
}

void noticewindow::display_info(QString info)
{
    ui->label->setText(info);
    move(123,240);
    show();
    timer_close->start(1000);
}

void noticewindow::on_timer_close()
{
    timer_close->stop();
    hide();
}
