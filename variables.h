#ifndef VARIABLES_H
#define VARIABLES_H

#include<QString>
typedef int Storey[169];
struct ENEMY
{
    int hp; //血量
    int atk; //攻击力
    int def; //防御力
    int attrib; //怪物属性，如中毒/先攻等
    int exp; //经验值
    int gold; //金币
    bool boss; //是否为boss
    QString name; //怪物名称
    QString img;
};

class HERO
{
public:
    int status; //状态
    int level; //等级
    int hp; //血量
    int atk; //攻击力
    int def; //防御力
    int pos_x; //当前x位置
    int pos_y; //当前y位置
    int storey; //当前层数
    int exp; //经验值
    int gold; //金币
    int ykey; //钥匙1
    int bkey; //钥匙2
    int rkey; //钥匙3
    int direction; //朝向
    HERO();
};

class VARIABLES
{
public:
    int no_end; //结局编号
    int no_dialog; //对话编号
    int no_store; //商店编号
    QString msg_gain_item; //获得物品时显示内容
    QString msg_hint; //提示内容
    int game_status; //操作状态。0为正常游戏中，1为对话框状态，2为游戏结束状态
    int status_storey2_door; //2层和8层的门需要打败一定数量的卫兵才能打开
    int status_storey8_door;
    int count_purchase; //商店买的次数
    bool status_keypurchase_6; //是否在六层买过蓝钥匙
    bool status_keypurchase_7; //是否在七层买过黄钥匙
    bool cut_storey3; //3层被打的转场
    VARIABLES();
};

extern HERO data_hero; //勇者的信息
extern ENEMY data_monster[11]; //怪物的信息
extern Storey data_tower[10];
extern VARIABLES var_global; //一些关键的全局变量

void init_enemy(); //初始化全局变量
void init_tower();

#endif // VARIABLES_H
