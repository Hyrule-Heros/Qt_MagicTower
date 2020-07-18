#ifndef NOTICEDIALOG_H
#define NOTICEDIALOG_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class noticedialog;
}

class noticedialog : public QDialog
{
    Q_OBJECT

public:
    explicit noticedialog(QWidget *parent = nullptr);
    ~noticedialog();

private:
    Ui::noticedialog *ui;
};

#endif // NOTICEDIALOG_H
