#include "battlewindow.h"
#include "ui_battlewindow.h"

battlewindow::battlewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::battlewindow)
{
    ui->setupUi(this);
    period_battle =0;
    end_battle = 0;
}

void battlewindow::start_battle(int& pos_target,int& id_enemy)
{
    if(period_battle==0)
    {
        ui->data_enemy_atk->setText(QString::number(data_monster[id_enemy].atk));
        ui->data_enemy_def->setText(QString::number(data_monster[id_enemy].def));
        ui->data_enemy_hp->setText(QString::number(data_monster[id_enemy].hp));
        ui->data_hero_atk->setText(QString::number(data_hero.atk));
        ui->data_hero_def->setText(QString::number(data_hero.def));
        ui->data_hero_hp->setText(QString::number(data_hero.hp));
        ui->icon_enemy->setStyleSheet(QString("border-image: img_enemys[%1];").arg(id_enemy));

        move(0,212);
        show();
        period_battle=1;
    }
    else if (period_battle % 2 == 1 && end_battle == 0)
    {
        if(data_monster[id_enemy].hp-(data_hero.atk - data_monster[id_enemy].def)*(period_battle/2+1)<=0)
        {ui->data_enemy_hp->setText(QString::number(0));end_battle =1;}
        else{
                    ui->data_enemy_hp->setText(QString::number(data_monster[id_enemy].hp - (data_hero.atk - data_monster[id_enemy].def) * (period_battle / 2 + 1)));
                    period_battle++;
                }
            }else if (period_battle % 2 == 0 && end_battle == 0)
            {
                if (data_monster[id_enemy].atk > data_hero.def)
                {
                    ui->data_hero_hp->setText(QString::number(data_hero.hp - (data_monster[id_enemy].atk - data_hero.def) * (period_battle / 2)));
                }
                period_battle++;
            }else{
                if (end_battle == 1){
                    //ui->label_26->show();
                    end_battle++;
                }
                else if(end_battle == 2){
                    //结算战斗结果
                    int damage = calc_damage(id_enemy);
                    data_hero.hp -= damage;
                    data_hero.gold += data_monster[id_enemy].gold;
                    data_hero.exp += data_monster[id_enemy].exp;
                    data_tower[data_hero.storey][pos_target] = 0;
                    //隐藏战斗界面
                    hide();
                    emit call_notices_event();
                    //ui->label_34->setText(QString::fromWCharArray(L"获得经验值 ") + QString::number(data_monster[id_enemy].exp) + QString::fromWCharArray(L" 金币 ") + QString::number(data_monster[id_enemy].gold));
                    //ui->label_34->show();
                    //DisplayData();

                    end_battle++;
                }
                //else if (end_battle <= 5)
                //{
                    //end_battle++}
                    else{
                    emit stop_battletimer_event();
                    //ui->label_34->hide();
                    end_battle = 0;
                    period_battle = 0;
                    id_enemy = 0;
                    var_global.game_status = 0;
                }
            }
}

battlewindow::~battlewindow()
{
    delete ui;
}
