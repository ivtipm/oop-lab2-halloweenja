#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_ferst;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_number()));                 //пример работы сигналов и слотов(В слот сигнала клик я помешаю метод digits_number
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_number()));                 //пример работы сигналов и слотов(В слот сигнала клик я помешаю метод digits_number
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_number()));                 //пример работы сигналов и слотов(В слот сигнала клик я помешаю метод digits_number
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_number()));                 //пример работы сигналов и слотов(В слот сигнала клик я помешаю метод digits_number
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->Button_inf,SIGNAL(clicked()),this,SLOT(operations()));                      //пример работы сигналов и слотов(В слот сигнала клик я помешаю метод operations
    connect(ui->Button_Persent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->Button_plus,SIGNAL(clicked()),this,SLOT(math_operations()));                //пример работы сигналов и слотов(В слот сигнала клик я помешаю метод math_operations
    connect(ui->Button_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->Button_multiplication,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->Button_division,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->Button_minus->setCheckable(true);
    ui->Button_plus->setCheckable(true);
    ui->Button_multiplication->setCheckable(true);
    ui->Button_division->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_number()
{
 QPushButton *button = (QPushButton *)sender();

 double numbers;
 QString label;

 if (ui->show_result->text().contains(".")&&button->text()== "0")
 {
     label=ui->show_result->text()+button->text();
 }
 else
 {
 numbers = (ui->show_result->text()+button->text()).toDouble();
 label = QString::number(numbers,'g',16);
 }
 ui->show_result->setText(label);

}

void MainWindow::on_pushButton_float_clicked()
{
    if(!(ui->show_result->text().contains('.')))
   ui->show_result->setText(ui->show_result->text()+("."));
}

void MainWindow::operations()
{
 QPushButton *button = (QPushButton *)sender();
 double numbers;
 QString label;

 if (button->text() == "+/-")
 {
    numbers = (ui->show_result->text()).toDouble();
    numbers = numbers * -1;
    label = QString::number(numbers,'g',16);

    ui->show_result->setText(label);
 }
 else if (button->text() == "%")
 {
     numbers = (ui->show_result->text()).toDouble();
     numbers = numbers * 0.01;
     label = QString::number(numbers,'g',16);

     ui->show_result->setText(label);
 }
}

void MainWindow::on_Button_Clean_clicked()
{
    ui->Button_plus->setChecked(false);
    ui->Button_minus->setChecked(false);
    ui->Button_division->setChecked(false);
    ui->Button_multiplication->setChecked(false);

    ui->show_result->setText("0");
}

void MainWindow::on_Button_result_clicked()
{
    double lable_Number,num_second;
    QString label;

    num_second=ui->show_result->text().toDouble();

    if (ui->Button_plus->isChecked())
    {
       lable_Number=num_ferst+num_second;
       label = QString::number(lable_Number,'g',16);

       ui->show_result->setText(label);
       ui->Button_plus->setChecked(false);
    }
    else if (ui->Button_minus->isChecked())
    {
        lable_Number=num_ferst-num_second;
        label = QString::number(lable_Number,'g',16);

        ui->show_result->setText(label);
        ui->Button_minus->setChecked(false);
    }
    else if (ui->Button_multiplication->isChecked())
    {
        lable_Number=num_ferst*num_second;
        label = QString::number(lable_Number,'g',16);

        ui->show_result->setText(label);
        ui->Button_multiplication->setChecked(false);
    }
    else if (ui->Button_division->isChecked())
    {
        if (num_second == 0)
        {
            ui->show_result->setText("0");
        }
        else
        {
        lable_Number=num_ferst/num_second;
        label = QString::number(lable_Number,'g',16);

        ui->show_result->setText(label);
        }
        ui->Button_division->setChecked(false);
    }
}

void MainWindow::math_operations()
{
 QPushButton *button = (QPushButton *)sender();
 num_ferst=ui->show_result->text().toDouble();
 ui->show_result->setText("");
 button->setChecked(true);


}
