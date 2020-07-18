#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::call_mainmenu()
{
    MainMenu = new mainmenu(this);
    connect(MainMenu,SIGNAL(init_game_event()),this,SLOT(init_game()));
    MainMenu->show();
}

void MainWindow::init_game()
{
    init_tower();
    init_enemy();
    data_hero=HERO();
    var_global=VARIABLES();
    DataDisplay = new datadisplay(this);
    DataDisplay->move(626,72);
    DataDisplay->init_datadisplay();
    DataDisplay->show();
    GameGrapic = new gamegrapic(this);
    GameGrapic->move(1,72);
    GameGrapic->init_grapic();
    GameGrapic->show();

}


