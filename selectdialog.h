#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H

#include <QDialog>
#include <QKeyEvent>
#include <QTimer>
#include <QString>

namespace Ui {
class selectdialog;
}

class selectdialog : public QDialog
{
    Q_OBJECT

public:
    explicit selectdialog(QWidget *parent = nullptr);
    ~selectdialog();
    void show_selectdialog();
    int num_chioce;
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::selectdialog *ui;
    int num_choice;
    int count_bordercolor;
    int no_choose; //选择了第几项

    const QString BorderColor[6] = {"FFFFFF", "CCCCCC", "999999", "666666", "999999", "CCCCCC"};
    QTimer* timer_bordercolor;

private slots:
    void on_timer_bordercolor_triggerded();
};

#endif // SELECTDIALOG_H
