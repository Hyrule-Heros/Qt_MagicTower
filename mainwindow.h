#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mainmenu.h"
#include "gamegrapic.h"
#include "datadisplay.h"
#include"variables.h"
#include "logics.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend mainmenu;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void call_mainmenu();     //生成主菜单

protected:
    //void keyPressEvent(QKeyEvent *event);
    mainmenu *MainMenu;     //主菜单
    datadisplay *DataDisplay;       //英雄状态窗口
    gamegrapic *GameGrapic;     //游戏画面窗口
public slots:
    void init_game();       //初始化游戏

private:
    Ui::MainWindow *ui;




};
#endif // MAINWINDOW_H
