#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <iostream>
#include "filetree.h"

int main(int argc, char *argv[])
{
    fileTree *tree=new fileTree();

    // Used for test.
    tree->test();
    // Used for test.
    QApplication a(argc, argv);
    MainWindow w(NULL, tree);
    w.show();

    return a.exec();
}
