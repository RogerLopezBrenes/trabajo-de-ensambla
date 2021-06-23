#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_number_0_clicked();

    void on_number_1_clicked();

    void on_number_2_clicked();

    void on_number_3_clicked();

    void on_number_4_clicked();

    void on_number_5_clicked();

    void on_number_6_clicked();

    void on_number_7_clicked();

    void on_number_8_clicked();

    void on_number_9_clicked();

    void on_button_equal_clicked();

    void on_button_Clear_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
