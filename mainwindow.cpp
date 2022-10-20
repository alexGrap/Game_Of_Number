#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    tmr = new QTimer();
    tmr->setInterval(10000);
    circle = 1;
    ui->setupUi(this);
    button = new QPushButton*();
    button[0] = ui->button_1;
    button[1] = ui->button_2;
    button[2] = ui->button_3;
    button[3] = ui->button_4;
    button[4] = ui->button_5;
    button[5] = ui->button_6;
    button[6] = ui->button_7;
    button[7] = ui->button_8;
    button[8] = ui->button_9;
    for (int i = 0; i < 9; i++) {button[i]->hide();}
    ui->start_button->setStyleSheet("font: bold;background-color: green;font-size: 48px;height: 48px;width: 120px;");
    ui->quit_button->setStyleSheet("font: bold;background-color: red;font-size: 36px;height: 48px;width: 120px;");
    ui->quit_button->hide();
    QObject::connect(this, SIGNAL(signals_from_key(int)), this, SLOT(signals_returner(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_button_clicked()
{
    QMessageBox mes, mes_1;
    ui->start_button->hide();
    ui->quit_button->show();
    for (int i = 0; i < 9; i++)
    {
        button[i]->show();
    }
    fill_field();
    QEventLoop loop;
    QObject::connect(this, SIGNAL(signals_from_key(int)), &loop, SLOT(quit()));
    cur_button = -100;
    int touched = 0;
    while (touched < circle) {
        loop.exec();
        touched++;
        if (!game.game_compare(cur_button))
        {
            exit_window(1);
        }
    }
    circle++;

    if (circle == 6)
    {
       exit_window(2);
    }
    on_start_button_clicked();
}

void MainWindow::fill_field(){
    QString *number_array;
    number_array = game.generate_number();

    for (int i = 0; i < 9; i++)
    {
        button[i]->setText(number_array[i]);
        button[i]->setStyleSheet("font: bold;background-color: white;font-size: 36px;height: 48px;width: 120px;");
    }
    send_message(number_array);
}

void MainWindow::send_message(QString *arr) {
    QMessageBox message;
    QString str = "";
    game.generate_order(circle);
    for (int i = 0; i < circle; i++) {
        str += arr[game.order[i] - 1];
        str += " ";
    }
    message.setText(str);
    message.exec();
}

void MainWindow::exit_window(int flag)
{
    QMessageBox mes;
    QString message;
    if (flag == 1) {
        message = "You lose!";
    }
    else if (flag == 2) {
        message = "You win!";
    }
    mes.setText(message);
    QAbstractButton* pButtonYes = mes.addButton(tr("Quit"), QMessageBox::YesRole);
    mes.addButton(tr("Restart"), QMessageBox::NoRole);
    mes.exec();
    if (mes.clickedButton()==pButtonYes) {
        exit(0);
    }
    else {
        circle = 1;
        on_start_button_clicked();
    }
}

void MainWindow::signals_returner(int buttonID)
{
    cur_button = buttonID;
}


void MainWindow::on_button_1_clicked()
{
    emit signals_from_key(1);
}


void MainWindow::on_button_2_clicked()
{
    emit signals_from_key(2);
}


void MainWindow::on_button_3_clicked()
{
    emit signals_from_key(3);
}


void MainWindow::on_button_4_clicked()
{
    emit signals_from_key(4);
}


void MainWindow::on_button_5_clicked()
{
    emit signals_from_key(5);
}


void MainWindow::on_button_6_clicked()
{
    emit signals_from_key(6);
}


void MainWindow::on_button_7_clicked()
{
    emit signals_from_key(7);
}


void MainWindow::on_button_8_clicked()
{
    emit signals_from_key(8);
}


void MainWindow::on_button_9_clicked()
{
    emit signals_from_key(9);
}


void MainWindow::on_quit_button_clicked()
{
    exit(0);
}

