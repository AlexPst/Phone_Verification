#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString currentText)
    {
        QRegularExpression exp("^\\+\\d{1,1}\\(\\d{3,3}\\)\\d{3,3}\\-\\d{2,2}\\-\\d{2,2}$");
        if(exp.match(currentText).hasMatch())
        {
            setOkLabel();
        }else
        {
            setNotOkLabel();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkLabel()
{
    ui->label->setText("OK");
    ui->label->setStyleSheet("QLabel{color:green;}");
}

void MainWindow::setNotOkLabel()
{
    ui->label->setText("FAIL");
    ui->label->setStyleSheet("QLabel{color:red;}");
}

