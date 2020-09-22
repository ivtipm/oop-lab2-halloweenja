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

private:
    Ui::MainWindow *ui;

private slots:
    void digits_number();
    void on_pushButton_float_clicked();
    void operations();
    void on_Button_Clean_clicked();
    void math_operations();
    void on_Button_result_clicked();
};
#endif // MAINWINDOW_H
