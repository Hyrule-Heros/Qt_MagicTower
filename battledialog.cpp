#include "battledialog.h"
#include "ui_battledialog.h"

battledialog::battledialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::battledialog)
{
    ui->setupUi(this);
}

battledialog::~battledialog()
{
    delete ui;
}
