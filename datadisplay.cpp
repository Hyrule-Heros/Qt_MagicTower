#include "datadisplay.h"
#include "ui_datadisplay.h"

datadisplay::datadisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::datadisplay)
{
    ui->setupUi(this);
    timer_update = new QTimer (this);
    connect(timer_update,SIGNAL(timeout()),this,SLOT(update_datadisplay()));
}

datadisplay::~datadisplay()
{
    delete ui;
}

void datadisplay::update_datadisplay()
{
    ui->data_atk->setText(QString::number(data_hero.atk));
    ui->data_defence->setText(QString::number(data_hero.def));
    ui->data_heal->setText(QString::number(data_hero.hp));
    ui->data_exp->setText(QString::number(data_hero.exp));
    ui->data_ykey->setText(QString::number(data_hero.ykey));
    ui->data_rkey->setText(QString::number(data_hero.rkey));
    ui->data_coin->setText(QString::number(data_hero.gold));
    ui->data_bkey->setText(QString::number(data_hero.bkey));
    switch (data_hero.storey)
    {
        case(0):
        ui->data_storey->setText(QString("第一层"));
        case(1):
        ui->data_storey->setText(QString("第二层"));
        case(2):
        ui->data_storey->setText(QString("第三层"));
        case(3):
        ui->data_storey->setText(QString("第四层"));
        case(4):
        ui->data_storey->setText(QString("第五层"));
        case(5):
        ui->data_storey->setText(QString("第六层"));
        case(6):
        ui->data_storey->setText(QString("第七层"));
        case(7):
        ui->data_storey->setText(QString("第八层"));
        case(8):
        ui->data_storey->setText(QString("第九层"));
        case(9):
        ui->data_storey->setText(QString("第十层"));
    default:
        ui->data_storey->setText(QString("第一层"));
    }
}

void datadisplay::init_datadisplay()
{

    timer_update->start(100);
}
