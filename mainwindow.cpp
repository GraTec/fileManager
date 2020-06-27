#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent,fileTree *tree) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->tree=tree;
    this->setTitle();
    this->setContents(ui->listWidget);

    connect(ui->listWidget,SIGNAL(itemDoubleClicked( QListWidgetItem*)),
            this,SLOT(listWidget_itemDoubleClicked(QListWidgetItem*)));

}

void MainWindow::setTitle()
{
    this->setWindowTitle(QString::fromStdString(tree->currentDir->name));
    ui->label->setText(QString::fromStdString(tree->showAddr()));
}

void MainWindow::setContents(QListWidget *listWidget)
{
    std::list<Node*>::iterator it;
    listWidget->clear();

    const QString name=tr("..");
    QListWidgetItem *item=new QListWidgetItem(name, listWidget);
    item->setIcon(QIcon("../icon/folder.png"));

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

void MainWindow::listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int row=item->listWidget()->row(item);
    if(row==0){
        if(tree->currentDir->parent==NULL){
            return ;
        }
        tree->currentDir=tree->currentDir->parent;
    }
    else{
        std::list<Node*>::iterator it=tree->currentDir->child.begin();
        std::advance(it,row-1);
        tree->currentDir=*(it);
    }
    update(item->listWidget());
}

void MainWindow::update(QListWidget *listWidget)
{
    this->setTitle();
    this->setContents(listWidget);
}


MainWindow::~MainWindow()
{
    delete ui;
}
