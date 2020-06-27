#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent,fileTree *tree) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setTitle(tree);
    this->setContents(tree, ui->listWidget);

}

void MainWindow::setTitle(fileTree *tree)
{
    this->setWindowTitle(QString::fromStdString(tree->currentDir->name));
    ui->label->setText(QString::fromStdString(tree->showAddr()));
}

void MainWindow::setContents(fileTree *tree, QListWidget *listWidget)
{
    std::list<Node*>::iterator it;
    for(it=tree->currentDir->child.begin();it!=tree->currentDir->child.end();it++){
        const QString name=QString::fromStdString((*it)->name);
        bool dir=(*it)->dir;
        QListWidgetItem *item=new QListWidgetItem(name, listWidget);
        if(dir){
            item->setIcon(QIcon("../icon/folder.png"));
        }
        else{
            item->setIcon(QIcon("../icon/file.png"));
        }
    }
}

void MainWindow::update(fileTree *tree)
{
    this->setTitle(tree);
}


MainWindow::~MainWindow()
{
    delete ui;
}
