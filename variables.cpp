#include "variables.h"
#include "enum.h"

HERO data_hero;
ENEMY data_monster[11];
Storey data_tower[10];
VARIABLES var_global;

void init_enemy()
{
    data_monster[0].name = "绿色史莱姆";
    data_monster[0].hp = 35;
    data_monster[0].atk = 18;
    data_monster[0].def = 1;
    data_monster[0].boss = false;
    data_monster[0].attrib = 0;
    data_monster[0].gold = 1;
    data_monster[0].exp = 1;
    data_monster[0].img = ":/enemy/res/enemy/geernslime.png";

    data_monster[1].name = "红色史莱姆";
    data_monster[1].hp = 45;
    data_monster[1].atk = 20;
    data_monster[1].def = 2;
    data_monster[1].boss = false;
    data_monster[1].attrib = 0;
    data_monster[1].gold = 2;
    data_monster[1].exp = 1;
    data_monster[1].img = ":/enemy/res/enemy/redslime.png";

    data_monster[2].name = "骷髅士兵";
    data_monster[2].hp = 55;
    data_monster[2].atk = 52;
    data_monster[2].def = 12;
    data_monster[2].boss = false;
    data_monster[2].attrib = 0;
    data_monster[2].gold = 8;
    data_monster[2].exp = 2;
    data_monster[2].img = ":/enemy/res/enemy/skeletonwarrior.png";

    data_monster[3].name = "木乃伊";
    data_monster[3].hp = 50;
    data_monster[3].atk = 42;
    data_monster[3].def = 6;
    data_monster[3].boss = false;
    data_monster[3].attrib = 0;
    data_monster[3].gold = 6;
    data_monster[3].exp = 1;
    data_monster[3].img = ":/enemy/res/enemy/mummy.png";

    data_monster[4].name = "小蝙蝠";
    data_monster[4].hp = 35;
    data_monster[4].atk = 38;
    data_monster[4].def = 3;
    data_monster[4].boss = false;
    data_monster[4].attrib = 0;
    data_monster[4].gold = 3;
    data_monster[4].exp = 1;
    data_monster[4].img = ":/enemy/res/enemy/bat.png";

    data_monster[5].name = "初级法师";
    data_monster[5].hp = 60;
    data_monster[5].atk = 32;
    data_monster[5].def = 8;
    data_monster[5].boss = false;
    data_monster[5].attrib = 0;
    data_monster[5].gold = 5;
    data_monster[5].exp = 1;
    data_monster[5].img = ":/enemy/res/enemy/wizard.png";

    data_monster[6].name = "中级卫兵";
    data_monster[6].hp = 100;
    data_monster[6].atk = 180;
    data_monster[6].def = 110;
    data_monster[6].boss = false;
    data_monster[6].attrib = 0;
    data_monster[6].gold = 50;
    data_monster[6].exp = 7;
    data_monster[6].img = ":/enemy/res/enemy/eitleguard.png";

    data_monster[7].name = "初级卫兵";
    data_monster[7].hp = 50;
    data_monster[7].atk = 48;
    data_monster[7].def = 22;
    data_monster[7].boss = false;
    data_monster[7].attrib = 0;
    data_monster[7].gold = 12;
    data_monster[7].exp = 1;
    data_monster[7].img = ":/enemy/res/enemy/normalguard.png";

    data_monster[8].name = "骷髅队长";
    data_monster[8].hp = 100;
    data_monster[8].atk = 65;
    data_monster[8].def = 15;
    data_monster[8].boss = false;
    data_monster[8].attrib = 0;
    data_monster[8].gold = 30;
    data_monster[8].exp = 3;
    data_monster[8].img = ":/enemy/res/enemy/skeletonleader.png";

    data_monster[9].name = "魔法警卫";
    data_monster[9].hp = 230;
    data_monster[9].atk = 450;
    data_monster[9].def = 100;
    data_monster[9].boss = false;
    data_monster[9].attrib = 0;
    data_monster[9].gold = 100;
    data_monster[9].exp = 5;
    data_monster[9].img = ":/enemy/res/enemy/wizardguard.png";

    data_monster[10].name = "假魔王";
    data_monster[10].hp = 5000;
    data_monster[10].atk = 1580;
    data_monster[10].def = 190;
    data_monster[10].boss = false;
    data_monster[10].attrib = 0;
    data_monster[10].gold = 0;
    data_monster[10].exp = 9;
    data_monster[10].img = ":/enemy/res/enemy/boss.png";
}

void init_tower()
{
    Storey tmpfloor_1 = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,10, 0, 51, 52, 51, 0, 0, 0, 0, 0, 0,1,
        1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,1,
        1,34, 0, 0, 21, 0, 1, 36, 31, 0, 1, 0,1,
        1,0, 54, 0, 1, 0, 1, 37, 34, 0, 1, 0,1,
        1,1, 21, 1, 1, 0, 1, 1, 1, 21, 1, 0,1,
        1,31, 0, 0, 1, 0, 21, 55, 56, 55, 1, 0,1,
        1,0, 53, 0, 1, 0, 1, 1, 1, 1, 1, 0,1,
        1,1, 21, 1, 1, 0, 0, 0, 0, 0, 0, 0,1,
        1,0, 0, 0, 1, 1, 21, 1, 1, 1, 21, 1,1,
        1,34, 0, 31, 1, 31, 0, 0, 1, 0, 55, 0,1,
        1,34, 0, 31, 1, 0, 0, 0, 1, 31, 35, 31,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,
    };
    memcpy(data_tower[0], tmpfloor_1, sizeof(int) * X * Y);

    Storey tmpfloor_2 = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,11, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0,1,
        1,0, 0, 1, 1, 0, 57, 0, 57, 0, 1, 1,1,
        1,0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,1,
        1,0, 1, 31, 31, 1, 0, 0, 0, 1, 0, 44,1,
        1,0, 1, 31, 0, 25, 0, 0, 0, 25, 0, 0,1,
        1,0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,1,
        1,0, 1, 46, 0, 1, 0, 0, 0, 1, 0, 45,1,
       1, 0, 1, 0, 0, 25, 0, 0, 0, 25, 0, 0,1,
        1,0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,1,
        1,0, 1, 35, 35, 1, 0, 0, 0, 1, 0, 0,1,
        1,10, 1, 35, 0, 25, 0, 0, 0, 25, 0, 0,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,
    };
    memcpy(data_tower[1], tmpfloor_2, sizeof(int) * X * Y);

    Storey tmpfloor_3 = {
            1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,31, 37, 1, 31, 35, 31, 1, 0, 1, 0, 35,1,
            1,0, 34, 1, 35, 31, 35, 1, 0, 21, 55, 0,1,
            1,56, 0, 1, 31, 32, 31, 1, 0, 1, 1, 1,1,
            1,21, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0,1,
            1,0, 0, 55, 0, 0, 0, 51, 0, 0, 0, 0,1,
            1,21, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1,1,
            1,54, 0, 1, 1, 0, 1, 1, 0, 1, 0, 34,1,
            1,0, 31, 1, 0, 0, 0, 1, 0, 21, 56, 31,1,
            1,34, 36, 1, 0, 0, 0, 1, 0, 1, 1, 1,1,
            1,1, 1, 1, 1, 0, 1, 1, 52, 1, 0, 0,1,
            1,11, 0, 0, 0, 0, 0, 1, 0, 21, 0, 10,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,
        };
    memcpy(data_tower[2], tmpfloor_3, sizeof(int) * X * Y);
    /*Storey tmpfloor_3 = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,31, 37, 1, 31, 35, 31, 1, 0, 1, 0, 35,1,
        1,0, 34, 1, 35, 31, 35, 1, 0, 21, 55, 0,1,
        1,56, 0, 1, 31, 32, 31, 1, 0, 1, 1, 1,1,
        1,21, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0,1,
        1,0, 0, 55, 0, 0, 0, 51, 0, 0, 0, 0,1,
        1,21, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1,1,
        1,54, 0, 1, 1, 0, 1, 1, 0, 1, 0, 34,1,
        1,0, 31, 1, 0, 0, 0, 1, 0, 21, 56, 31,1,
        1,34, 36, 1, 0, 13, 0, 1, 0, 1, 1, 1,1,
        1,1, 1, 1, 1, 0, 1, 1, 52, 1, 0, 0,1,
        1,11, 0, 0, 0, 0, 0, 1, 0, 21, 0, 10,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,
    };
    memcpy(data_tower[2], tmpfloor_3, sizeof(int) * X * Y);*/

    Storey tmpfloor_4 = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0, 32, 0, 1, 41, 42, 43, 1, 0, 47, 0,1,
        1,34, 0, 31, 1, 0, 0, 0, 1, 31, 0, 35,1,
        1,0, 0, 0, 1, 0, 0, 0, 1, 0, 53, 0,1,
        1,1, 21, 1, 1, 1, 22, 1, 1, 1, 21, 1,1,
        1,0, 55, 0, 21, 0, 52, 0, 0, 54, 0, 0,1,
        1,0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,1,
        1,52, 0, 51, 0, 0, 0, 0, 0, 0, 0, 0,1,
        1,21, 1, 1, 21, 1, 1, 1, 21, 1, 1, 21,1,
        1,0, 1, 0, 55, 0, 1, 0, 56, 0, 1, 0,1,
        1,0, 1, 51, 0, 31, 1, 36, 0, 34, 1, 0,1,
        1,10, 1, 31, 51, 31, 1, 0, 51, 0, 1, 11,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,
    };
    memcpy(data_tower[3], tmpfloor_4, sizeof(int) * X * Y);

    Storey tmpfloor_5 = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,10, 1, 0, 52, 21, 0, 1, 0, 0, 21, 0,1,
        1,0, 1, 0, 0, 1, 31, 1, 51, 51, 1, 52,1,
        1,0, 21, 55, 0, 1, 0, 1, 31, 31, 1, 0,1,
        1,1, 1, 1, 21, 1, 55, 1, 31, 31, 1, 0,1,
        1,31, 0, 56, 0, 1, 0, 1, 1, 1, 1, 0,1,
        1,31, 0, 0, 55, 1, 0, 51, 0, 0, 0, 0,1,
        1,1, 53, 1, 1, 1, 0, 1, 1, 1, 1, 52,1,
        1,0, 0, 0, 0, 1, 51, 1, 0, 0, 0, 0,1,
        1,37, 31, 34, 0, 1, 0, 1, 21, 0, 0, 0,1,
        1,1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0,1,
        1,11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 38,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,
    };
    memcpy(data_tower[4], tmpfloor_5, sizeof(int) * X * Y);

    Storey tmpfloor_6 = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,11, 1, 31, 31, 1, 0, 56, 0, 31, 51, 0,1,
        1,0, 1, 31, 31, 1, 0, 1, 1, 1, 1, 21,1,
        1,0, 1, 1, 52, 1, 0, 1, 34, 0, 54, 0,1,
        1,0, 21, 21, 0, 21, 0, 1, 48, 0, 0, 55,1,
        1,0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,1,
        1,0, 0, 52, 56, 0, 0, 0, 54, 53, 0, 0,1,
        1,1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0,1,
        1,56, 0, 0, 49, 1, 0, 21, 21, 0, 21, 0,1,
       1, 0, 55, 0, 37, 1, 0, 1, 1, 52, 1, 52,1,
        1,21, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0,1,
        1,0, 51, 0, 0, 54, 0, 1, 34, 34, 1, 10,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,
    };
    memcpy(data_tower[5], tmpfloor_6, sizeof(int) * X * Y);

    Storey tmpfloor_7 = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,10, 1, 36, 1, 0, 50, 0, 1, 31, 1, 51,1,
        1,0, 1, 34, 1, 0, 0, 0, 1, 31, 1, 52,1,
        1,0, 1, 55, 1, 52, 1, 53, 1, 34, 1, 51,1,
        1,0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,1,
        1,21, 1, 21, 1, 22, 1, 21, 1, 54, 1, 21,1,
        1,0, 53, 0, 56, 0, 0, 0, 0, 0, 0, 0,1,
        1,21, 1, 21, 1, 21, 1, 21, 1, 53, 1, 21,1,
        1,0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,1,
        1,0, 1, 0, 1, 55, 1, 52, 1, 35, 1, 0,1,
        1,51, 1, 51, 1, 31, 1, 56, 1, 31, 1, 0,1,
        1,0, 52, 0, 1, 31, 1, 35, 1, 31, 1, 11,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,
    };
    memcpy(data_tower[6], tmpfloor_7, sizeof(int) * X * Y);

    Storey tmpfloor_8 = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,11, 0, 21, 21, 0, 10, 0, 1, 31, 0, 31,1,
        1,0, 0, 1, 1, 0, 0, 51, 1, 0, 33, 0,1,
        1,21, 1, 1, 1, 1, 21, 1, 1, 35, 0, 34,1,
        1,0, 1, 31, 31, 31, 0, 0, 1, 1, 24, 1,1,
        1,34, 1, 1, 1, 1, 1, 56, 1, 58, 0, 58,1,
        1,0, 52, 51, 52, 0, 1, 0, 1, 0, 0, 0,1,
        1,1, 1, 1, 1, 21, 1, 55, 1, 1, 21, 1,1,
        1,0, 0, 0, 55, 0, 54, 0, 56, 0, 0, 0,1,
        1,21, 1, 1, 1, 1, 1, 1, 1, 1, 1, 21,1,
        1,51, 0, 1, 36, 31, 1, 32, 34, 1, 0, 54,1,
        1,0, 55, 22, 31, 37, 1, 31, 0, 21, 53, 0,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,
    };
    memcpy(data_tower[7], tmpfloor_8, sizeof(int) * X * Y);

    Storey tmpfloor_9 = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0, 0, 54, 21, 0, 11, 0, 21, 51, 0, 34,1,
        1,0, 31, 0, 1, 0, 0, 0, 1, 0, 51, 0,1,
        1,53, 1, 1, 1, 1, 22, 1, 1, 1, 1, 0,1,
        1,0, 31, 0, 1, 31, 0, 31, 21, 21, 0, 0,1,
        1,37, 0, 55, 21, 0, 36, 0, 1, 1, 26, 1,1,
        1,1, 1, 1, 1, 1, 1, 52, 1, 0, 0, 53,1,
        1,31, 0, 21, 53, 31, 1, 0, 1, 39, 1, 0,1,
        1,53, 0, 1, 0, 0, 1, 0, 1, 1, 1, 21,1,
        1,21, 1, 1, 1, 21, 1, 0, 1, 31, 0, 56,1,
        1,0, 34, 1, 0, 54, 1, 55, 1, 0, 54, 0,1,
        1,10, 0, 22, 0, 0, 21, 0, 21, 56, 0, 34,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,
    };
    memcpy(data_tower[8], tmpfloor_9, sizeof(int) * X * Y);

    Storey tmpfloor_10 = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,1,
       1,1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,1,
        1,54, 54, 54, 1, 1, 0, 1, 1, 54, 54, 54,1,
        1,0, 53, 0, 24, 0, 59, 0, 24, 0, 53, 0,1,
        1,1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,1,
        1,54, 37, 54, 1, 1, 0, 1, 1, 54, 36, 54,1,
        1,0, 53, 0, 1, 1, 0, 1, 1, 0, 53, 0,1,
        1,0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0,1,
        1,21, 1, 21, 1, 1, 23, 1, 1, 21, 1, 21,1,
        1,0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0,1,
        1,11, 1, 0, 56, 0, 14, 0, 56, 0, 1, 35,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,
    };
    memcpy(data_tower[9], tmpfloor_10, sizeof(int) * X * Y);
}

HERO::HERO()
{
    status=0;
    level=1;
    hp=1000;
    atk=10;
    def=10;
    pos_x=6;
    pos_y=11;
    storey=0;
    exp=0;
    gold=0;
    ykey=0;
    bkey=0;
    rkey=0;
    direction=DOWN;
}

VARIABLES::VARIABLES()
{
    no_end=0;
    no_dialog=0;
    no_store=1;
    game_status=NORMAL;
    status_storey2_door=0;
    status_storey8_door=0;
    count_purchase=0;
    status_keypurchase_6=false;
    status_keypurchase_7=false;
    cut_storey3=false;
}
