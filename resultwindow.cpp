#include "resultwindow.h"
#include "ui_resultwindow.h"

#include <algorithm>
#include <QListWidgetItem>
#include <QDebug>

ResultWindow::ResultWindow(QWidget* parent, const QList<QString>& result_list):
    QDialog(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);

//    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
//    setWindowModality(Qt::WindowModal);

    this->setFixedSize(600, 500);

    std::for_each(result_list.begin(), result_list.end(), [this](const QString& s) {
        new QListWidgetItem(s, ui->listWidget);
    });

    connect(ui->pushButton, &QPushButton::clicked, [this](){this->close();});
}

ResultWindow::~ResultWindow() {
    delete ui;
}
