#ifndef BATTLEDIALOG_H
#define BATTLEDIALOG_H

#include <QDialog>

namespace Ui {
class battledialog;
}

class battledialog : public QDialog
{
    Q_OBJECT

public:
    explicit battledialog(QWidget *parent = nullptr);
    ~battledialog();

private:
    Ui::battledialog *ui;
};

#endif // BATTLEDIALOG_H
