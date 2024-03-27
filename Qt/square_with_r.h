#ifndef SQUARE_WITH_R_H
#define SQUARE_WITH_R_H

class SQUARE_WITH_R : public Square {
private:
    double R1, H, r;
public:
    SQUARE_WITH_R(Ui::MainWindow *ui) {
        bool parsed;
        this->R1 = ui->lineEdit->text().replace(",", ".").toDouble(&parsed);
        this->H = ui->lineEdit_2->text().replace(",", ".").toDouble(&parsed);
        this->r = ui->lineEdit_3->text().replace(",", ".").toDouble(&parsed);
    }
    void task(Ui::MainWindow *ui) {
            ui->label_6->setText(QString::number(3.14*H*(R1*R1-r*r)));
    }
};

#endif // SQUARE_WITH_R_H
