#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent,fileTree *tree) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    this->tree=tree;
    this->setTitle();
    this->setContents();

    connect(ui->listWidget,SIGNAL(itemDoubleClicked( QListWidgetItem*)),
            this,SLOT(listWidget_itemDoubleClicked(QListWidgetItem*)));
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(QPoint)),
            this, SLOT(showContextMenu(QPoint)));
}

void MainWindow::setTitle()
{
    this->setWindowTitle(tree->currentDir->name);
    ui->label->setText(tree->showAddr());
}

void MainWindow::setContents()
{
    std::list<Node*>::iterator it;
    ui->listWidget->clear();

    const QString name=tr("..");
    QListWidgetItem *item=new QListWidgetItem(name, ui->listWidget);
    item->setIcon(QIcon(":/icon/folder.png"));

    for(it=tree->currentDir->child.begin();it!=tree->currentDir->child.end();it++){
        const QString name = (*it)->name;
        bool dir=(*it)->dir;
        QListWidgetItem *item=new QListWidgetItem(name, ui->listWidget);
        if(dir){
            item->setIcon(QIcon(":/icon/folder.png"));
        }
        else{
            item->setIcon(QIcon(":/icon/file.png"));
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
    update();
}

void MainWindow::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->listWidget->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;
    myMenu.addAction("Create Directory", this, SLOT(addDir()));
    myMenu.addAction("Create File",  this, SLOT(addFile()));
    myMenu.addAction("Delete", this, SLOT(deleteItem()));

    // Show context menu at handling position
    myMenu.exec(globalPos);
}

void MainWindow::update()
{
    this->setTitle();
    this->setContents();
}

void MainWindow::deleteItem()
{
    int row=ui->listWidget->currentRow();
    std::list<Node*>::iterator it=tree->currentDir->child.begin();
    std::advance(it,row-1);
    tree->rm(*it);
    update();
}

void MainWindow::addFile()
{
    bool ok;
    auto text = QInputDialog::getText(this, tr("Create a File"),
                                      tr("File name:"), QLineEdit::Normal,
                                      tr("Untitiled"), &ok);
    if (ok && !text.isEmpty()) {
        tree->createFile(text, tree->currentDir);
        update();
    }
}

void MainWindow::addDir()
{
    bool ok;
    auto text = QInputDialog::getText(this, tr("Create a Directory"),
                                      tr("Directory name:"), QLineEdit::Normal,
                                      tr("Untitiled"), &ok);
    if (ok && !text.isEmpty()) {
        tree->mkdir(text, tree->currentDir);
        update();
    }
}

MainWindow::~MainWindow()
{
//    delete ui;
}
