#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "filetree.h"
#include "node.h"
#include <QMainWindow>
#include <QListWidget>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, fileTree *tree=nullptr);
    ~MainWindow();

    void setTitle();//Set the title of the window.
    void setContents();//Set the information of files and dir's.

    void update();//Used for update the window.

private:
    Ui::MainWindow *ui;
    fileTree *tree;
    Node* buffer = nullptr;
    bool is_cut = false;
    QList<QString> result_list;

public slots:
    void listWidget_itemDoubleClicked(QListWidgetItem *item);
    void showContextMenu(const QPoint &pos);
    void addDir();
    void addFile();
    void deleteItem();

    void copy();
    void cut();
    void paste();
    void rename();
    void paste_for_copy();
    void paste_for_cut();
    void search();
};

#endif // MAINWINDOW_H
