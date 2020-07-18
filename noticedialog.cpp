#include "noticedialog.h"
#include "ui_noticedialog.h"

noticedialog::noticedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::noticedialog)
{
    ui->setupUi(this);
}

noticedialog::~noticedialog()
{
    delete ui;
}
