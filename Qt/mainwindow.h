#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *e);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_lineEdit_3_textChanged();
signals:
    void signal();
    void signal_2();
public slots:
    void on_lineEdit_textChanged();
    void on_lineEdit_2_textChanged();

private:
    Ui::MainWindow *ui;};
#endif // MAINWINDOW_H
