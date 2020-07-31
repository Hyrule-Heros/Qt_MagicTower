#include "gamegrapic.h"
#include "ui_gamegrapic.h"

gamegrapic::gamegrapic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamegrapic)
{
    ui->setupUi(this);

    id_temp_enemy = 0;
    pos_battle = -1;
    count_keyup = 20;
    leftright_step = false;

    timer_update = new QTimer(this);
    timer_cut = new QTimer(this);
    //timer_battle = new QTimer(this);
    timer_pickupitem = new QTimer(this);
    timer_notice = new QTimer(this);

    NoticeWindow=new noticewindow(this);
    SelectWindow=new selectwindow(this);
    BattleWindow=new battlewindow(this);

    NoticeWindow->hide();
    SelectWindow->hide();
    BattleWindow->hide();

    scene_storey = new QGraphicsScene;
    pixmap_items = new QGraphicsPixmapItem*[X*Y];

    connect(timer_update,SIGNAL(timeout()),this,SLOT(on_timer_update_triggered()));
    //connect(BattleWindow,SIGNAL(stop_battletimer_event()),this,SLOT(stop_battle_timer()));
    connect(BattleWindow,SIGNAL(call_notices_event()),this,SLOT(notice_after_battle()));
    //connect(timer_cut,SIGNAL(timeout()),this,SLOT(on_timer_cut_triggered()));
    //connect(timer_battle,SIGNAL(timeout()),BattleWindow,SLOT(start_battle()));
    //connect(timer_notice,SIGNAL(timeout()),this,SLOT(on_timer_notice_triggered()));
    //connect(timer_pickupitem,SIGNAL(timeout()),this,SLOT(on_timer_pickupitem_triggered();));

    this->grabKeyboard();
}

gamegrapic::~gamegrapic()
{
    delete ui;
}

void gamegrapic::stop_battle_timer()
{
    timer_battle->stop();
}

void gamegrapic::notice_after_battle()
{
    NoticeWindow->display_info(QString::fromWCharArray(L"获得经验值 ") + QString::number(data_monster[id_temp_enemy].exp) + QString::fromWCharArray(L" 金币 ") + QString::number(data_monster[id_temp_enemy].gold));
}

void gamegrapic::init_grapic()
{
    img_floor = QImage (":/map/res/map/floor.png");
    img_wall[0] = QImage (":/map/res/map/wall.png");
    img_wall[1] = QImage (":/map/res/map/roof1.png");
    img_wall[2] = QImage (":/map/res/map/roof.png");
    img_upstairs = QImage (":/map/res/map/upstairs.png");
    img_downstairs = QImage (":/map/res/map/downstairs.png");
    img_yellowdoor = QImage (":/map/res/map/yellowdoor.png");
    img_bluedoor = QImage (":/map/res/map/bluedoor.png");
    img_reddoor = QImage (":/map/res/map/reddoor.png");
    img_jaildoor = QImage (":/map/res/map/jaildoor.png");
    img_cyandoor = QImage (":/map/res/map/cyandoor.png");
    for(int i = 0;i < 10; i++)
    img_enemy[i] = QImage (data_monster[i].img);
    for (int t = 0; t <4 ;t++)
    {img_hero[t][0] = QImage (":/character/res/characters/hero.png").copy(0,48*t,32,48);
    img_hero[t][1] = QImage (":/character/res/characters/hero.png").copy(32,48*t,32,48);
    img_hero[t][2] = QImage (":/character/res/characters/hero.png").copy(64,48*t,32,48);
    img_hero[t][3] = QImage (":/character/res/characters/hero.png").copy(96,48*t,32,48);}
    img_store[0] = QImage(":/map/res/map/shopleft.png");
    img_store[1] = QImage(":/character/res/characters/fixedshop.png");
    img_store[2] = QImage(":/map/res/map/shopright.png");
    img_yellowkey = QImage(":/item/res/item/yelllowkey.png");
    img_bluewkey= QImage(":/item/res/item/bluekey.png");
    img_redkey= QImage(":/item/res/item/redkey.png");
    img_redbottle= QImage(":/item/res/item/redpotion.png");
    img_bluebottle= QImage(":/item/res/item/bluepotion.png");
    img_redgem= QImage(":/item/res/item/redgem.png");
    img_bluegem= QImage(":/item/res/item/greengem.png");
    img_ironsword= QImage(":/item/res/item/sword.png");
    img_ironshied= QImage(":/item/res/item/shield.png");
    img_oldnpc= QImage(":/character/res/characters/witcher.png");
    img_tradernpc= QImage(":/character/res/characters/shopkeeper.png");
    img_thiefnpc= QImage(":/character/res/characters/thief.png");
    timer_update->start(100);
}

void gamegrapic::update_grapic()
{
    int count_item = 0;
    scene_storey->clear();
    for(int y=0;y<Y;y++)
        for(int x=0;x<X;x++)
        {
            if(data_tower[data_hero.storey][y*X+x]!=1)
            {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_floor));
                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                scene_storey->addItem(pixmap_items[count_item]);
                count_item++;
            }
            if(y<Y-1){
            if(data_tower[data_hero.storey][y*X+x]==1&&data_tower[data_hero.storey][(y+1)*X+x]!=1/*&&data_tower[data_hero.storey][(y+1)*X+x]!=21
                    &&data_tower[data_hero.storey][(y+1)*X+x]!=23&&data_tower[data_hero.storey][(y+1)*X+x]!=25*/)
            {pixmap_items[count_item] = new QGraphicsPixmapItem;
                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_wall[0]));
                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                scene_storey->addItem(pixmap_items[count_item]);
                count_item++;}

            else if (data_tower[data_hero.storey][y*X+x]==1&&!(data_tower[data_hero.storey][(y+1)*X+x]!=1/*&&data_tower[data_hero.storey][(y+1)*X+x]!=21&&data_tower[data_hero.storey][(y+1)*X+x]!=23&&data_tower[data_hero.storey][(y+1)*X+x]!=25*/))
            {
                    pixmap_items[count_item] = new QGraphicsPixmapItem;
                        pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_wall[1]));
                        pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                        scene_storey->addItem(pixmap_items[count_item]);

            }
            }
            if(data_tower[data_hero.storey][y*X+x]==YKEY)
             {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_yellowkey));
                                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                scene_storey->addItem(pixmap_items[count_item]);
                                count_item++;
            }
            else if(data_tower[data_hero.storey][y*X+x]==BKEY)
            {
               pixmap_items[count_item] = new QGraphicsPixmapItem;
                               pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_bluewkey));
                               pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                               scene_storey->addItem(pixmap_items[count_item]);
                               count_item++;
           }
            else if(data_tower[data_hero.storey][y*X+x]==RKEY)
            {
               pixmap_items[count_item] = new QGraphicsPixmapItem;
                               pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_redkey));
                               pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                               scene_storey->addItem(pixmap_items[count_item]);
                               count_item++;
           }
            else if(data_tower[data_hero.storey][y*X+x]==RPOTION)
             {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_redbottle));
                                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                scene_storey->addItem(pixmap_items[count_item]);
                                count_item++;
            }
            else if(data_tower[data_hero.storey][y*X+x]==BPOTION)
             {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_bluebottle));
                                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                scene_storey->addItem(pixmap_items[count_item]);
                                count_item++;
            }
            else if(data_tower[data_hero.storey][y*X+x]==RGEM)
             {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_redgem));
                                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                scene_storey->addItem(pixmap_items[count_item]);
                                count_item++;
            }
            else if(data_tower[data_hero.storey][y*X+x]==BGEM)
             {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_bluegem));
                                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                scene_storey->addItem(pixmap_items[count_item]);
                                count_item++;
            }
            else if(data_tower[data_hero.storey][y*X+x]==ISWORD)
             {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_ironsword));
                                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                scene_storey->addItem(pixmap_items[count_item]);
                                count_item++;
            }
            else if(data_tower[data_hero.storey][y*X+x]==ISHIED)
             {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_ironshied));
                                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                scene_storey->addItem(pixmap_items[count_item]);
                                count_item++;
            }
            if(data_tower[data_hero.storey][y*X+x]==DOWNSTAIRS)
             {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_downstairs));
                                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                scene_storey->addItem(pixmap_items[count_item]);
                                count_item++;
            }
            else if(data_tower[data_hero.storey][y*X+x]==UPSTAIRS)
             {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_upstairs));
                                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                scene_storey->addItem(pixmap_items[count_item]);
                                count_item++;
            }
            else if(data_tower[data_hero.storey][y*X+x]==YDOOR)
             {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_yellowdoor));
                                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                scene_storey->addItem(pixmap_items[count_item]);
                                count_item++;
            }
            else if(data_tower[data_hero.storey][y*X+x]==BDOOR)
             {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_bluedoor));
                                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                scene_storey->addItem(pixmap_items[count_item]);
                                count_item++;
            }
            else if(data_tower[data_hero.storey][y*X+x]==RDOOR)
             {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_reddoor));
                                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                scene_storey->addItem(pixmap_items[count_item]);
                                count_item++;
            }
            else if(data_tower[data_hero.storey][y*X+x]==CYANDOOR)
             {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_cyandoor));
                                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                scene_storey->addItem(pixmap_items[count_item]);
                                count_item++;
            }
            else if(data_tower[data_hero.storey][y*X+x]==JAILDOOR)
             {
                pixmap_items[count_item] = new QGraphicsPixmapItem;
                                pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_jaildoor));
                                pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                scene_storey->addItem(pixmap_items[count_item]);
                                count_item++;
            }
            else if(data_tower[data_hero.storey][y*X+x]==SHOPLEFT)
                         {
                            pixmap_items[count_item] = new QGraphicsPixmapItem;
                                            pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_store[0]));
                                            pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                            scene_storey->addItem(pixmap_items[count_item]);
                                            count_item++;
                        }
            else if(data_tower[data_hero.storey][y*X+x]==SHOPMIDDLE)
                         {
                            pixmap_items[count_item] = new QGraphicsPixmapItem;
                                            pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_store[1]));
                                            pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                            scene_storey->addItem(pixmap_items[count_item]);
                                            count_item++;
                        }
            else if(data_tower[data_hero.storey][y*X+x]==SHOPRIGHT)
                         {
                            pixmap_items[count_item] = new QGraphicsPixmapItem;
                                            pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_store[2]));
                                            pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                            scene_storey->addItem(pixmap_items[count_item]);
                                            count_item++;
                        }
            if(data_tower[data_hero.storey][y*X+x]==45||data_tower[data_hero.storey][y*X+x]==48||data_tower[data_hero.storey][y*X+x]==50)
                         {
                            pixmap_items[count_item] = new QGraphicsPixmapItem;
                                            pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_tradernpc));
                                            pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                            scene_storey->addItem(pixmap_items[count_item]);
                                            count_item++;
                        }
            else if(data_tower[data_hero.storey][y*X+x]==46)
                         {
                            pixmap_items[count_item] = new QGraphicsPixmapItem;
                                            pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_thiefnpc));
                                            pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                            scene_storey->addItem(pixmap_items[count_item]);
                                            count_item++;
                        }
            else if(data_tower[data_hero.storey][y*X+x]==44||data_tower[data_hero.storey][y*X+x]==47||data_tower[data_hero.storey][y*X+x]==49)
                         {
                            pixmap_items[count_item] = new QGraphicsPixmapItem;
                                            pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_oldnpc));
                                            pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                            scene_storey->addItem(pixmap_items[count_item]);
                                            count_item++;
                        }
            else if(data_tower[data_hero.storey][y*X+x]>=51&&data_tower[data_hero.storey][y*X+x]<=50+TOTAL_enemy)
                         {
                            pixmap_items[count_item] = new QGraphicsPixmapItem;
                                            pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_enemy[data_tower[data_hero.storey][y*X+x]-51]));
                                            pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * y));
                                            scene_storey->addItem(pixmap_items[count_item]);
                                            count_item++;
                        }
            if(x==data_hero.pos_x&&y==data_hero.pos_y)
            {
                 pixmap_items[count_item] = new QGraphicsPixmapItem;
                 if(count_keyup<=3)
                 {if(leftright_step==false)
                        {pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_hero[data_hero.direction][1]));leftright_step = true;}
                  else {pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_hero[data_hero.direction][3]));leftright_step = false;}}
                 else pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_hero[data_hero.direction][0]));
            pixmap_items[count_item]->setPos(QPointF(48 * x + 8, 48 * y));
            scene_storey->addItem(pixmap_items[count_item]);


            }
                if(y>0)
                    if(data_tower[data_hero.storey][y*X+x]==1&&data_tower[data_hero.storey][(y-1)*X+x]!=1/*&&data_tower[data_hero.storey][(y-1)*X+x]!=21&&data_tower[data_hero.storey][(y-1)*X+x]!=23&&data_tower[data_hero.storey][(y-1)*X+x]!=25*/)
                    {
                        pixmap_items[count_item] = new QGraphicsPixmapItem;
                                        pixmap_items[count_item]->setPixmap(QPixmap::fromImage(img_wall[2]));
                                        pixmap_items[count_item]->setPos(QPointF(PIXEL * x, PIXEL * (y-1)));
                                        scene_storey->addItem(pixmap_items[count_item]);
                                        count_item++;
                    }
                ui->graphics_view->setScene(scene_storey);
                ui->graphics_view->show();
    }
}

/*void gamegrapic::on_timer_cut_triggered()
{
    if (var_global.cut_storey3 == false)
    {
        if (count_stairs <= 3)
        {
            count_stairs += 1;
            ui->gr_cut->setStyleSheet("background-color:rgba(0,0,0," + QString::number(count_stairs * 64) + ");");
            //DisplayFloor(OldFloor);
        }else if (count_stairs <= 7){
            count_stairs += 1;
            ui->gr_cut->setStyleSheet("background-color:rgba(0,0,0," + QString::number((8 - count_stairs) * 64) + ");");
            //DisplayFloor(data_hero.floor);
        }else {
            count_stairs = 0;
            var_global.game_status = 0;
            timer_cut->stop();
            ui->gr_cut->setStyleSheet("background-color:rgba(0,0,0,0);");
            //DisplayFloor(data_hero.floor);
            timer_update->start(200);
        }
    }else{
        if (count_stairs <= 3)
        {
            count_stairs += 1;
            ui->gr_cut->setStyleSheet("background-color:rgba(0,0,0," + QString::number(count_stairs * 64) + ");");
        }
        else if (count_stairs <= 7){
            count_stairs += 1;
        }else if (count_stairs == 8){
            timer_cut->stop();
            NoticeWindow->display_info(QString("醒醒"));
            data_tower[2][7 * X + 5] = 0;
            data_tower[2][8 * X + 5] = 0;
            data_tower[2][9 * X + 4] = 0;
            data_tower[2][9 * X + 5] = 0;
            data_tower[2][9 * X + 6] = 0;
            data_tower[2][10 * X + 5] = 0;
            data_hero.storey = 1;
            data_hero.pos_x = 3;
            data_hero.pos_y = 8;
            timer_cut->start();
            count_stairs += 1;
        }else if (count_stairs <= 12){
            count_stairs += 1;
            ui->gr_cut->setStyleSheet("background-color:rgba(0,0,0," + QString::number((13 - count_stairs) * 64) + ");");
            //DisplayFloor(data_hero.floor);
        }else {
            count_stairs = 0;
            var_global.game_status = 0;
            timer_cut->stop();
            ui->gr_cut->setStyleSheet("background-color:rgba(0,0,0,0);");
            //DisplayFloor(data_hero.stroey);
            var_global.cut_storey3 = false;
            timer_update->start(200);
        }
    }
}*/


void gamegrapic::on_timer_update_triggered()
{
    count_keyup +=1;
    update_grapic();
}

void gamegrapic::keyPressEvent(QKeyEvent *event)
{
    int pos_target = -1;
    if (var_global.game_status == 0)
    {
        //OldFloor = data_hero.floor;
        if(event->key() == Qt::Key_Up){ //向上
            count_keyup = 0;
            var_global.game_status = judge_interaction(UP);
            pos_target = (data_hero.pos_y - 1) * X + data_hero.pos_x;
        }
        if(event->key() == Qt::Key_Down){ //向下
            count_keyup = 0;
            var_global.game_status = judge_interaction(DOWN);
            pos_target = (data_hero.pos_y + 1) * X + data_hero.pos_x;
        }
        if(event->key() == Qt::Key_Left){ //向左
            count_keyup = 0;
            var_global.game_status = judge_interaction(LEFT);
            pos_target = data_hero.pos_y * X + (data_hero.pos_x - 1);
        }
        if(event->key() == Qt::Key_Right){ //向右
            count_keyup = 0;
            var_global.game_status = judge_interaction(RIGHT);
            pos_target = data_hero.pos_y * X + (data_hero.pos_x + 1);
        }
    if (var_global.game_status == NORMAL)
    {
        update_grapic();
    }else if (var_global.game_status == DIALOGPAUSE)
    {
        NoticeWindow->display_info(var_global.msg_hint);
        if (data_tower[data_hero.storey][pos_target] == 47 || data_tower[data_hero.storey][pos_target] == 49 || data_tower[data_hero.storey][pos_target] == 44 || data_tower[data_hero.storey][pos_target] == 48 || data_tower[data_hero.storey][pos_target] == 50) //对话之后立即消失的npc放在这里
            data_tower[data_hero.storey][pos_target] = 0;
        if (data_tower[data_hero.storey][pos_target] == 46 && pos_target == 7 * X + 3)
        {
            data_tower[data_hero.storey][pos_target] = 0;
            data_tower[1][7 * X + 2] = 0;
            data_tower[data_hero.storey][8 * X] = 46;
        }
        if (data_tower[data_hero.storey][pos_target] == 46 && pos_target == 9 * X)
        {
            data_tower[data_hero.storey][pos_target] = 0;
        }
        var_global.game_status = 0;
}
    /*else if (var_global.game_status == GOSTAIRS)
    {
        // 上下楼转场
        timer_update->stop();
        timer_cut->start(100);
    }*/
    else if (var_global.game_status == BATTLE)
    {
        // 开始进入战斗状态
        id_temp_enemy=data_tower[data_hero.storey][pos_target]-51;
        pos_battle=pos_target;
        BattleWindow->start_battle(pos_battle,id_temp_enemy);
    }else if (var_global.game_status == GAINITEM)
    {
        //获得物品时显示内容
        NoticeWindow->display_info(var_global.msg_gain_item);
    }/*else if (var_global.game_status == SHOPPING)
    {
        //商店处理
        int store_price = ((var_global.count_purchase + 1) * (var_global.count_purchase + 1) - (var_global.count_purchase + 1) + 2) * 10;
        switch(var_global.no_store)
        {
        case 1:

            SelectWindow->ui->grapic_select->setStyleSheet("background:transparent;border:none;");
            SelectWindow->ui->label->setText(QString::fromStdWString(L"你若给我 ") + QString::number(store_price) + QString::fromStdWString(L" 个金币"));
            SelectWindow->ui->label_2->setText(" ");
            SelectWindow->ui->label_7->setText(QString::fromStdWString(L"我就可以帮你"));
            SelectWindow->ui->label_8->setText(" ");
            SelectWindow->ui->label_3->setText(QString::fromStdWString(L"提升 ") + QString::number(100 * (var_global.BuyTimes + 1)) + QString::fromStdWString(L" 点生命"));
            SelectWindow->ui->label_4->setText(QString::fromStdWString(L"提升 2 点攻击力"));
            SelectWindow->ui->label_5->setText(QString::fromStdWString(L"提升 4 点防御力"));
            SelectWindow->ui->label_6->setText(QString::fromStdWString(L"离开商店"));
            SelectWindow->num_choice = 4;
            //SelectWindow->pos_target = pos_target;
            SelectWindow->show_selectdialog();;
            break;
        case 2:

            //SelectWindow->ui->grapic_select->setScene(scene_store);
            SelectWindow->ui->grapic_select->setStyleSheet("background:transparent;border:none;");
            SelectWindow->ui->label->setText(QString::fromStdWString(L"谢谢你救了我，"));
            SelectWindow->ui->label_2->setText(QString::fromStdWString(L"我能用祝福魔法提升你3%"));
            SelectWindow->ui->label_3->setText(QString::fromStdWString(L"我太需要了"));
            SelectWindow->ui->label_4->setText(QString::fromStdWString(L"下次再说"));
            SelectWindow->ui->label_5->setText(" ");
            SelectWindow->ui->label_6->setText(" ");
            SelectWindow->ui->label_7->setText(QString::fromStdWString(L"的攻击力和防御力"));
            SelectWindow->ui->label_8->setText(QString::fromStdWString(L"，现在就提升吗？"));
            SelectWindow->choice_num = 2;
            //SelectWindow->pos_target = pos_target;
            SelectWindow->OpenStore();
            SelectWindow->show_selectdialog();;
            break;
        case 3:
            //scene_store = new QGraphicsScene;
            //scene_store->addPixmap(QPixmap::fromImage(ImgNpcRed[0]));
            //SelectWindow->ui->grapic_select->setScene(scene_store);
            //SelectWindow->ui->grapic_select->setStyleSheet("background:transparent;border:none;");
            SelectWindow->ui->label->setText(QString::fromStdWString(L"我有一把蓝钥匙"));
            SelectWindow->ui->label_2->setText(QString::fromStdWString(L"你出50个金币"));
            SelectWindow->ui->label_7->setText(QString::fromStdWString(L"就卖给你"));
            SelectWindow->ui->label_8->setText(" ");
            SelectWindow->ui->label_3->setText(QString::fromStdWString(L"我太需要了"));
            SelectWindow->ui->label_4->setText(QString::fromStdWString(L"下次再说"));
            SelectWindow->ui->label_5->setText(" ");
            SelectWindow->ui->label_6->setText(" ");
            SelectWindow->choice_num = 2;
            //SelectWindow->pos_target = pos_target;
            SelectWindow->OpenStore();
            SelectWindow->show_selectdialog();;
            break;
        case 4:
            //scene_store = new QGraphicsScene;
            //scene_store->addPixmap(QPixmap::fromImage(ImgNpcRed[0]));
            SelectWindow->ui->grapic_select->setScene(scene_store);
            SelectWindow->ui->grapic_select->setStyleSheet("background:transparent;border:none;");
            SelectWindow->ui->label->setText(QString::fromStdWString(L"我有五把黄钥匙"));
            SelectWindow->ui->label_2->setText(QString::fromStdWString(L"你出50个金币"));
            SelectWindow->ui->label_7->setText(QString::fromStdWString(L"就卖给你"));
            SelectWindow->ui->label_8->setText(" ");
            SelectWindow->ui->label_3->setText(QString::fromStdWString(L"我太需要了"));
            SelectWindow->ui->label_4->setText(QString::fromStdWString(L"下次再说"));
            SelectWindow->ui->label_5->setText(" ");
            SelectWindow->ui->label_6->setText(" ");
            SelectWindow->num_choice = 2;
            //SelectWindow->pos_target = pos_target;
            SelectWindow->show_selectdialog();;
            break;
        default:
            break;
        }
    }*/
    else if (var_global.game_status == CUTINSTOREY3)
    {
        NoticeWindow->display_info(QString::fromStdWString(L"魔王Zero说：“欢迎来到魔塔，你是第一百位挑战者。\n你若能打败我所有的手下，我就与你一对一的决斗。\n现在你必须接受我的安排。"));
        NoticeWindow->display_info(QString::fromStdWString(L"什么？"));
        timer_update->stop();
        timer_cut->start(100);
    }
}



}
