#include "selectdialog.h"
#include "ui_selectdialog.h"

selectdialog::selectdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectdialog)
{
    ui->setupUi(this);
    count_bordercolor = 0;
    num_chioce =4;
    no_choose = 0;
    timer_bordercolor = new QTimer();
    connect(timer_bordercolor,SIGNAL(timeout()),this,SLOT(on_timer_bordercolor_triggerded()));
}

selectdialog::~selectdialog()
{
    delete ui;
}

void selectdialog::show_selectdialog()
{
    no_choose = 0;
    timer_bordercolor->start(100);
    ui->label_msg->move();
}
