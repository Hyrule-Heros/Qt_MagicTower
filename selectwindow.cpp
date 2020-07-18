#include "selectwindow.h"
#include "ui_selectwindow.h"


selectwindow::selectwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectwindow)
{
    ui->setupUi(this);
    count_bordercolor = 0;
    num_choice =4;
    no_choose = 0;
    timer_bordercolor = new QTimer();
    connect(timer_bordercolor,SIGNAL(timeout()),this,SLOT(on_timer_bordercolor_triggerded()));
}

selectwindow::~selectwindow()
{
    delete ui;
}

void selectwindow::show_selectdialog()
{
    no_choose = 0;
    timer_bordercolor->start(100);
    move(162,112);
    show();
}

void selectwindow::on_timer_bordercolor_triggerded()
{
    if (count_bordercolor <= 4)
        count_bordercolor++;
    else
        count_bordercolor = 0;

    ui->grapic_select->setStyleSheet(QString::fromStdString("border:3px solid #") + BorderColor[count_bordercolor] + QString::fromStdString(";"));
}

void selectwindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){ //向上
        if (no_choose > 0)
        {
            no_choose -= 1;
            ui->grapic_select->move(90,260 + 40*no_choose);
        }
        else
            no_choose = 0;
    }else if (event->key() == Qt::Key_Down){ //向下
        if (no_choose <= num_choice - 2)
        {
            no_choose += 1;
            ui->grapic_select->move(90,260 + 40*no_choose);
        }
        else
            no_choose = num_choice - 1;
    }else if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter || event->key() == Qt::Key_Space){
        if (no_choose != num_choice - 1)
        {
            judge_store(no_choose);

            if (var_global.no_store == 1)
            {
                int store_price = ((var_global.count_purchase + 1) * (var_global.count_purchase + 1) - (var_global.count_purchase + 1) + 2) * 10;
                ui->label_msg->setText(QString::fromStdWString(L"你若给我 ") + QString::number(store_price) + QString::fromStdWString(L" 个金币"));
                ui->label_msg_2->setText(" ");
                ui->label_msg_3->setText(QString::fromStdWString(L"我就可以帮你"));
                ui->label_msg_4->setText(" ");
                ui->label_choice_1->setText(QString::fromStdWString(L"提升 ") + QString::number(100 * (var_global.count_purchase + 1)) + QString::fromStdWString(L" 点生命"));
                ui->label_choice_2->setText(QString::fromStdWString(L"提升 2 点攻击力"));
                ui->label_choice_3->setText(QString::fromStdWString(L"提升 4 点防御力"));
                ui->label_choice_4->setText(QString::fromStdWString(L"离开商店"));
            }
            if (var_global.no_store >= 2) //一次性的商店。买完后窗口直接关闭
            {
                this->close();
                var_global.game_status = NORMAL; //恢复主塔操作
            }
        }else{
            this->close();
            var_global.game_status = NORMAL; //恢复主塔操作
        }
    }
}

