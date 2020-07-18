#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QtGui>

namespace Ui {
class mainmenu;
}

class mainmenu : public QWidget
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();


private slots:
    void on_quit_button_clicked();
    void on_start_button_clicked();
signals:
    void init_game_event();
private:
    Ui::mainmenu *ui;

    QPixmap* mainmenubg;
    QPixmap* title_zh;
    QPixmap* title_en;
};

#endif // MAINMENU_H
