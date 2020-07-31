#include "logics.h"

int calc_damage(int monster_id)
{
    if (data_hero.atk <= data_monster[monster_id].def)
    {
        if (data_monster[monster_id].atk > data_hero.def)
            return INVINCIBLE;
        else
            return BOTHINVINCIBLE;
    }else{
        if (data_monster[monster_id].atk > data_hero.def){
            int atk_times = (data_monster[monster_id].hp - 1) / (data_hero.atk - data_monster[monster_id].def);
            return atk_times * (data_monster[monster_id].atk - data_hero.def);
        }else{
            return 0;
        }
    }
}

int judge_interaction(int direction)
{
    int pos_target=-1;
    //old_data = -1;
    if(direction==DOWN)
    {data_hero.direction = DOWN;
        pos_target = (data_hero.pos_y + 1) * X + data_hero.pos_x;}
    else if(direction==LEFT)
    {data_hero.direction = LEFT;
        pos_target = data_hero.pos_y * X + (data_hero.pos_x - 1);}
     else if(direction==RIGHT)
    {data_hero.direction = RIGHT;
        pos_target = data_hero.pos_y * X + (data_hero.pos_x + 1);}
    else if(direction==UP)
    {data_hero.direction = UP;
        pos_target = (data_hero.pos_y - 1) * X + data_hero.pos_x;}
    //old_data = data_tower[data_hero.storey][pos_target];
    if (data_tower[data_hero.storey][pos_target] == 0)//目标位置为地面
    {
        data_hero.pos_x = pos_target % X;
        data_hero.pos_y = pos_target / X;
        return NORMAL;
    }
    else if ((data_tower[data_hero.storey][pos_target] >= 1 && data_tower[data_hero.storey][pos_target] <= 9) || data_tower[data_hero.storey][pos_target] == 41 || data_tower[data_hero.storey][pos_target] == 43)//目标位置有墙或门阻挡
    {

        return NORMAL;
    }
    else if (data_tower[data_hero.storey][pos_target] == 10)//上楼
    {
        if (data_hero.storey != TOTAL_STOREY - 1){
            data_hero.storey += 1;
            int pos_target_upper = 0;
            for (int _it = 0; _it <= X * Y - 1; _it++){
                if (data_tower[data_hero.storey][_it] == 11){
                    pos_target_upper = _it;
                    break;
                }
            }
            data_hero.pos_x = pos_target_upper % X;
            data_hero.pos_y = pos_target_upper / X;
        }
        return NORMAL;
        //return GOSTAIRS;
    }else if (data_tower[data_hero.storey][pos_target] == 11)//下楼
    {

        if (data_hero.storey != 0){
            data_hero.storey -= 1;
            int pos_target_lower = 0;
            for (int _it = 0; _it <= X * Y - 1; _it++){
                if (data_tower[data_hero.storey][_it] == 10){
                    pos_target_lower = _it;
                    break;
                }
            }
            data_hero.pos_x = pos_target_lower % X;
            data_hero.pos_y = pos_target_lower / X;
        }
        return NORMAL;
        //return GOSTAIRS;
    }else if (data_tower[data_hero.storey][pos_target] == 12)//触发结局一：离开。直接Game Over
    {
        var_global.no_end = 1;
        var_global.no_dialog = 1;
        //show_dialog();
        return END;
    }
    else if (data_tower[data_hero.storey][pos_target] == 13)//第三层被缴械
    {
        data_hero.pos_x = pos_target % X;
        data_hero.pos_y = pos_target / X;
        data_tower[2][6 * X + 5] = 61;
        data_tower[2][7 * X + 5] = 60;
        data_tower[2][8 * X + 4] = 60;
        data_tower[2][8 * X + 6] = 60;
        data_tower[2][9 * X + 5] = 60;
        var_global.cut_storey3 = true;
        return CUTINSTOREY3;
    }else if (data_tower[data_hero.storey][pos_target] == 14)//尝试进入第十一层
    {
        var_global.msg_hint = "十一层及之后未开发完成。";
        return DIALOGPAUSE;
    }
    else if (data_tower[data_hero.storey][pos_target] == 21)//尝试打开黄门
    {
        if (data_hero.ykey >= 1){
            data_hero.ykey -= 1;
            data_tower[data_hero.storey][pos_target] = 0;
        }
        return NORMAL;
        //return OPENDOOR;
    }else if (data_tower[data_hero.storey][pos_target] == 22)//尝试打开蓝门
    {

        if (data_hero.bkey >= 1){
            data_hero.bkey -= 1;
            data_tower[data_hero.storey][pos_target] = 0;
        }
        return NORMAL;
        //return OPENDOOR;
    }else if (data_tower[data_hero.storey][pos_target] == 23)//尝试打开红门
    {
        if (data_hero.rkey >= 1){
            data_hero.rkey -= 1;
            data_tower[data_hero.storey][pos_target] = 0;
        }
        return NORMAL;
        //return OPENDOOR;
    }else if (data_tower[data_hero.storey][pos_target] == 24)//尝试打开青门
    {
        if (var_global.status_storey2_door ==2){
            data_tower[data_hero.storey][pos_target] = 0;
        }
        return NORMAL;
        //return OPENDOOR;
    }else if (data_tower[data_hero.storey][pos_target] == 25)//尝试打开监狱门
    {
        if (var_global.status_storey8_door == 2){
            data_tower[data_hero.storey][pos_target] = 0;
        }
        return NORMAL;
        //return OPENDOOR;
    }else if (data_tower[data_hero.storey][pos_target] == 26)//打开暗门
    {
        data_tower[data_hero.storey][pos_target] = 0;
        return NORMAL;
        //return OPENDOOR;
    }else if (data_tower[data_hero.storey][pos_target] == 31)//获得黄钥匙
    {
        data_tower[data_hero.storey][pos_target] = 0;
        data_hero.ykey += 1;
        var_global.msg_gain_item = "获得了一把黄钥匙";
        return GAINITEM;
    }else if (data_tower[data_hero.storey][pos_target] == 32)//获得蓝钥匙
    {
        data_tower[data_hero.storey][pos_target] = 0;
        data_hero.bkey += 1;
        var_global.msg_gain_item = "获得了一把蓝钥匙";
        return GAINITEM;
    }else if (data_tower[data_hero.storey][pos_target] == 33)//获得红钥匙
    {
        data_tower[data_hero.storey][pos_target] = 0;
        data_hero.rkey += 1;
        var_global.msg_gain_item = "获得了一把红钥匙";
        return GAINITEM;
    }else if (data_tower[data_hero.storey][pos_target] == 34)//获得小血瓶
    {
        data_tower[data_hero.storey][pos_target] = 0;
        data_hero.hp += 50;
        var_global.msg_gain_item = "获得了小血瓶,生命值增加50";
        return GAINITEM;
    }else if (data_tower[data_hero.storey][pos_target] == 35)//获得大血瓶
    {
        data_tower[data_hero.storey][pos_target] = 0;
        data_hero.hp += 200;
        var_global.msg_gain_item = "获得了大血瓶 生命值增加200";
        return GAINITEM;
    }else if (data_tower[data_hero.storey][pos_target] == 36)//获得红宝石
    {
        data_tower[data_hero.storey][pos_target] = 0;
        data_hero.atk += 1;
        var_global.msg_gain_item = "攻击力增加1点";
        return GAINITEM;
    }else if (data_tower[data_hero.storey][pos_target] == 37)//获得蓝宝石
    {
        data_tower[data_hero.storey][pos_target] = 0;
        data_hero.def += 1;
        var_global.msg_gain_item = "防御力增加1点";
        return GAINITEM;
    }else if (data_tower[data_hero.storey][pos_target] == 38)//获得铁剑
    {

        data_tower[data_hero.storey][pos_target] = 0;
        data_hero.atk += 10;
        var_global.msg_gain_item = "获得了铁剑 攻击力增加10点";
        return GAINITEM;
    }else if (data_tower[data_hero.storey][pos_target] == 39)//获得铁盾
    {
        data_tower[data_hero.storey][pos_target] = 0;
        data_hero.def += 10;
        var_global.msg_gain_item = "获得了铁盾 防御力增加10点";
        return GAINITEM;
    }else if (data_tower[data_hero.storey][pos_target] == 42)//商店
    {
        var_global.no_store = 1;
        return SHOPPING;
    }else if (data_tower[data_hero.storey][pos_target] == 44)
    {
        var_global.msg_hint = "谢谢你救了我，\n为了感谢你的帮助请收下这些礼物.\n（收到1000金币）";
        data_hero.gold += 1000;
        return DIALOGPAUSE;
    }else if (data_tower[data_hero.storey][pos_target] == 45)//商人
    {
        var_global.no_store = 2;
        return SHOPPING;
    }else if (data_tower[data_hero.storey][pos_target] == 46)//盗贼
    {
        if (pos_target == 7 * X + 3)
            var_global.msg_hint = "你清醒了吗？你到监狱时还处在昏迷中，\n魔法警卫把你扔到我这个房间。但你很幸运，\n我刚完成逃跑的暗道你就醒了，我们一起越狱吧。";
        else
            var_global.msg_hint = "我们终于逃出来了。你的剑和盾被警卫拿走了，\n你必须先找到武器。我知道铁剑在5楼，铁盾在9楼，\n你最好先取得它们。我现在有事要做没法帮你，再见。";
        return DIALOGPAUSE;
    }else if (data_tower[data_hero.storey][pos_target] == 47){
        var_global.msg_hint = "有些门不能用钥匙打开。\n只有当你打败它的守卫后才会自动打开。";
        return DIALOGPAUSE;
    }else if (data_tower[data_hero.storey][pos_target] == 48){
        if (var_global.status_keypurchase_6 == true)
        {
            var_global.msg_hint = "魔塔一共50层，每10层为一个区域。\n如果不打败此区域的头目\n就不能到更高的地方";
            return DIALOGPAUSE;
        }
        else
        {
            var_global.no_store = 3;
            return SHOPPING;
        }
    }else if (data_tower[data_hero.storey][pos_target] == 49){
        var_global.msg_hint = "你购买了礼物后再与商人对话，\n他会告诉你一些重要的消息。";
        return DIALOGPAUSE;
    }else if (data_tower[data_hero.storey][pos_target] == 50)//商人
    {
        if (var_global.status_keypurchase_7 == true)
        {
            var_global.msg_hint = "在商店里你最好选择提升防御，\n只有在攻击力低于敌人的防御力时才提升攻击力。";
            return DIALOGPAUSE;
        }
        else
        {
            var_global.no_store = 4;
            return SHOPPING;
        }
    }else if (data_tower[data_hero.storey][pos_target] >= 51)//怪物
    {
        int monster_id = data_tower[data_hero.storey][pos_target] - 51;
        int damage = calc_damage(monster_id);
        if (damage == INVINCIBLE){
            //在打不过时，不进行任何处理
            var_global.msg_hint = "你还不能打败他";
            return DIALOGPAUSE;
        }else if (damage == BOTHINVINCIBLE || damage >= data_hero.hp){
            //在打不过时，不进行任何处理
            var_global.msg_hint = "你还不能打败他";
            return DIALOGPAUSE;
        }else{
            //data_hero.hp -= damage;
            //data_hero.gold += Monster[monster_id].gold;
            //data_hero.exp += Monster[monster_id].exp;
            //data_tower[data_hero.storey][pos_target] = 0;
            if (monster_id == 6)
                var_global.status_storey2_door += 1;
            if (monster_id == 7)
                var_global.status_storey8_door += 1;
            return BATTLE;
        }
    }
    return NORMAL;
}

void judge_store(int no_choice)
{
    int store_price = ((var_global.count_purchase + 1) * (var_global.count_purchase + 1) - (var_global.count_purchase + 1) + 2) * 10;
    switch(var_global.no_store)
    {
    //提升能力的商店
    case 1:
        if (no_choice == 0 && data_hero.gold >= store_price)
        {
            data_hero.gold -= store_price;
            data_hero.hp += (var_global.count_purchase + 1) * 100;
            var_global.count_purchase += 1;
        }else if (no_choice == 1 && data_hero.gold >= store_price){
            data_hero.gold -= store_price;
            data_hero.atk += 2;
            var_global.count_purchase += 1;
        }else if (no_choice == 2 && data_hero.gold >= store_price){
            data_hero.gold -= store_price;
            data_hero.def += 4;
            var_global.count_purchase += 1;
        }
        break;
    //二层的祝福魔法
    case 2:
        if (no_choice == 0)
        {
            data_hero.atk += int(data_hero.atk * 0.03);
            data_hero.def += int(data_hero.def * 0.03);
            //Tower[data_hero.floor][target_pos] = 0;
        }
        break;
        //六层的蓝钥匙
    case 3:
        if (no_choice == 0 && data_hero.gold >= 50)
        {
            data_hero.gold -= 50;
            data_hero.bkey += 1;
            var_global.status_keypurchase_6 = true;
        }
        break;
        //七层的黄钥匙
    case 4:
        if (no_choice == 0 && data_hero.gold >= 50)
        {
            data_hero.gold -= 50;
            data_hero.ykey += 5;
            var_global.status_keypurchase_7 = true;
        }
        break;
    default:
        break;
    }
}

