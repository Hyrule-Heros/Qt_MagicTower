#ifndef HEROSTATUS_H
#define HEROSTATUS_H

#include <QWidget>

namespace Ui {
class herostatus;
}

class herostatus : public QWidget
{
    Q_OBJECT

public:
    explicit herostatus(QWidget *parent = nullptr);
    ~herostatus();

private:
    Ui::herostatus *ui;
};

#endif // HEROSTATUS_H
