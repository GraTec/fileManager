#ifndef REUSLTWINDOW_H
#define REUSLTWINDOW_H

#include <QDialog>
#include <QList>

namespace Ui {
    class ResultWindow;
}

class ResultWindow: public QDialog
{
    Q_OBJECT
public:
    ResultWindow(QWidget* parent, const QList<QString>& result_list);
    ~ResultWindow();

private:
    Ui::ResultWindow *ui;
//    QList<QString>* result_list;

};

#endif // REUSLTWINDOW_H
