#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTableWidgetItem>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawTableTokens(vector<Token> &listTokens)
{
    QStringList headers;
    ui->tableWidget->clear();
    headers << "Token" << "lexema";
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(listTokens.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    for (size_t index = 0 ;index < listTokens.size() ; ++index) {
        Token & token = listTokens[index];
        QString tokenString = QString::fromStdString(token.getToken());
        QString lexema = QString::fromStdString(token.getLexema());
        auto *iToken=new QTableWidgetItem(tokenString);
        auto *iLexema=new QTableWidgetItem(lexema);
        ui->tableWidget->setItem(index,0,iToken);
        ui->tableWidget->setItem(index,1,iLexema);
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void MainWindow::on_pushButton_clicked()
{
    QString name;
    name = QFileDialog::getOpenFileName(this, "Select file", "", "PTC file (*.ptc)");
    if(name.size() > 0){
        vector<Token> listTokensFinded;
        ui->stackedWidget->setCurrentIndex(1);
        string nameFile = name.toStdString();
        AnalizerLexical analizerLexical = AnalizerLexical();
        analizerLexical.startScan(nameFile);
        analizerLexical.setListTokenOutClass(listTokensFinded);
        if(listTokensFinded.size() > 0){
            QMessageBox message;
            message.setText("Fase de analisis léxico realizado correctamente");
            message.setIcon(QMessageBox::Information);
            message.exec();
        }
        drawTableTokens(listTokensFinded);
    }
}

void MainWindow::on_gotToCompilePB_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    //ui->gotToCompilePB->setVisible(false);
}
