#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_mainwindow.h"
#include "square.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_4->hide();
    ui->label_9->hide();
    ui->label_12->hide();
    ui->lineEdit_3->hide();

    ui->pushButton->setStyleSheet("background-color: #00FF7F; border-width: 0.5%; border-radius: 10px;   padding: 6px;");
    ui->pushButton_2->setStyleSheet("background-color: #FFA07A; border-width: 0.5%; border-radius: 10px;   padding: 6px;");

    ui->lineEdit->setStyleSheet("border-style: solid; border-width: 1%; border-radius: 10px;");
    ui->lineEdit_2->setStyleSheet("border-style: solid; border-width: 1%; border-radius: 10px;");
    ui->lineEdit_3->setStyleSheet("border-style: solid; border-width: 1%; border-radius: 10px;");

    connect(this, &MainWindow::signal, this, &MainWindow::on_lineEdit_textChanged);
    connect(this, &MainWindow::signal_2, this, &MainWindow::on_lineEdit_2_textChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e -> key() == Qt::Key_Escape)
    {
        this -> close();
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->label_4->hide();
    ui->lineEdit_3->hide();
    ui->label_9->hide();
    ui->label_12->hide();
    ui->pushButton->setStyleSheet("background-color: #00FF7F; border-width: 0.5%; border-radius: 10px;   padding: 6px;");
    ui->pushButton_2->setStyleSheet("background-color: #FFA07A; border-width: 0.5%; border-radius: 10px;   padding: 6px;");
    ui->lineEdit_3->setText("");
    signal();
    signal_2();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->label_4->show();
    ui->lineEdit_3->show();
    ui->label_9->show();
    ui->label_12->show();
    ui->pushButton_2->setStyleSheet("background-color: #00FF7F; border-width: 0.5%; border-radius: 10px;   padding: 6px;");
    ui->pushButton->setStyleSheet("background-color: #FFA07A; border-width: 0.5%; border-radius: 10px;   padding: 6px;");
}

void MainWindow::on_lineEdit_textChanged()
{
    ui->lineEdit->setStyleSheet("border-style: solid; border-width: 1%; border-radius: 10px;");

    bool parsed, parsed_2, parsed_3;
    double lenght_R1 = ui->lineEdit->text().replace(",", ".").toDouble(&parsed);
    double lenght_H = ui->lineEdit_2->text().replace(",", ".").toDouble(&parsed_2);
    double lenght_r = ui->lineEdit_3->text().replace(",", ".").toDouble(&parsed_3);

    if(lenght_R1 <= 0 or !parsed){
        ui->lineEdit->setStyleSheet("border-color: #FF0000; border-style: solid; border-width: 1%; border-radius: 10px;");
        return;
    }
    if(lenght_R1 > lenght_r) {
        ui->lineEdit_3->setStyleSheet("border-style: solid; border-width: 1%; border-radius: 10px;");
    }
    if(lenght_R1 <= lenght_r) {
        ui->lineEdit->setStyleSheet("border-color: #FF0000; border-style: solid; border-width: 1%; border-radius: 10px;");
        ui->lineEdit_3->setStyleSheet("border-color: #FF0000; border-style: solid; border-width: 1%; border-radius: 10px;");
        return;
    }
    if(lenght_H <=0 or lenght_r < 0) {
        return;
    }
    else{
        if(lenght_r <= 0 or !parsed){
            Square my_obj(ui);
            my_obj.task(ui);
        }
        else{
            SQUARE_WITH_R my_obj_with_r(ui, lenght_r);
            my_obj_with_r.task(ui);
        }
    }
}

void MainWindow::on_lineEdit_2_textChanged()
{
    ui->lineEdit_2->setStyleSheet("border-style: solid; border-width: 1%; border-radius: 10px;");

    bool parsed, parsed_2, parsed_3;
    double lenght_R1 = ui->lineEdit->text().replace(",", ".").toDouble(&parsed);
    double lenght_H = ui->lineEdit_2->text().replace(",", ".").toDouble(&parsed_2);
    double lenght_r = ui->lineEdit_3->text().replace(",", ".").toDouble(&parsed_3);

    if(lenght_H <= 0 or !parsed){
        ui->lineEdit_2->setStyleSheet("border-color: #FF0000; border-style: solid; border-width: 1%; border-radius: 10px;");
        return;
    }
    if(lenght_R1 <=0 or lenght_r < 0) {
        return;
    }
    else{
        if(lenght_r <= 0 or !parsed){
            Square my_obj(ui);
            my_obj.task(ui);
        }
        else{
            SQUARE_WITH_R my_obj_with_r(ui, lenght_r);
            my_obj_with_r.task(ui);
        }
    }
}

void MainWindow::on_lineEdit_3_textChanged()
{
    ui->lineEdit_3->setStyleSheet("border-style: solid; border-width: 1%; border-radius: 10px;");

    bool parsed, parsed_2, parsed_3;
    double lenght_R1 = ui->lineEdit->text().replace(",", ".").toDouble(&parsed);
    double lenght_H = ui->lineEdit_2->text().replace(",", ".").toDouble(&parsed_2);
    double lenght_r = ui->lineEdit_3->text().replace(",", ".").toDouble(&parsed_3);

    if(!parsed or lenght_r <= 0) {
        ui->lineEdit_3->setStyleSheet("border-color: #FF0000; border-style: solid; border-width: 1%; border-radius: 10px;");
        return;
    }
    if(lenght_R1 <=0 or lenght_H <= 0) {
        return;
    }
    if(lenght_R1 <= lenght_r) {
        ui->lineEdit_3->setStyleSheet("border-color: #FF0000; border-style: solid; border-width: 1%; border-radius: 10px;");
        ui->lineEdit->setStyleSheet("border-color: #FF0000; border-style: solid; border-width: 1%; border-radius: 10px;");
        return;
    }
    else{
        ui->lineEdit->setStyleSheet("border-style: solid; border-width: 1%; border-radius: 10px;");
        ui->lineEdit_3->setStyleSheet("border-style: solid; border-width: 1%; border-radius: 10px;");
        SQUARE_WITH_R my_obj_with_r(ui, lenght_r);
        my_obj_with_r.task(ui);
    }
}




