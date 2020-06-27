#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filetree.h"
#include <QListWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, fileTree *tree=nullptr);
    ~MainWindow();

    void setTitle(fileTree *tree);//Set the title of the window.
    void setContents(fileTree *tree, QListWidget *listWidget);//Set the information of files and dir's.

    void update(fileTree *tree);//Used for update the window.

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
