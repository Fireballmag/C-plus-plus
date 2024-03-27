#ifndef SQUARE_H
#define SQUARE_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

class Square {
protected:
    double R1, H;
public:
    Square(Ui::MainWindow *ui) {
        bool parsed;
        this->R1 = ui->lineEdit->text().replace(",", ".").toDouble(&parsed);
        this->H = ui->lineEdit_2->text().replace(",", ".").toDouble(&parsed);
    }
    void task(Ui::MainWindow *ui) {
            ui->label_6->setText(QString::number(3.14*H*R1*R1));
    }
};

class SQUARE_WITH_R : public Square {
private:
    double r;
public:
    SQUARE_WITH_R(Ui::MainWindow *ui, double obj_r)
        :Square(ui)
    {
        this->r = obj_r;
    }
    void task(Ui::MainWindow *ui) {
            ui->label_6->setText(QString::number(3.14*H*(R1*R1-r*r)));
    }
};

#endif // SQUARE_H
