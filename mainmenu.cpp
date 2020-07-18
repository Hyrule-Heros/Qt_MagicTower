#include "mainmenu.h"
#include "ui_mainmenu.h"

mainmenu::mainmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainmenu)
{
    ui->setupUi(this);
    /*QPalette pal(this->palette());
    mainmenubg = new QPixmap(":/background/res/background/mainmenu.png");
    pal.setBrush(QPalette::Background, QBrush(mainmenubg->scaled(size(), Qt::IgnoreAspectRatio,
                            Qt::SmoothTransformation)));
    this->setPalette(pal);
    //setMask(mainmenubg->mask());     //显示透明色*/

}

mainmenu::~mainmenu()
{
    delete ui;
}



void mainmenu::on_quit_button_clicked()
{
    QApplication::quit();
}

void mainmenu::on_start_button_clicked()
{
    emit init_game_event();
    this->close();
}

