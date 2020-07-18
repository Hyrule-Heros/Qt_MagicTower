#include "herostatus.h"
#include "ui_herostatus.h"

herostatus::herostatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::herostatus)
{
    ui->setupUi(this);
}

herostatus::~herostatus()
{
    delete ui;
}
