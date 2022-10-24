#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"

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
    void on_start_button_clicked();
    void on_button_1_clicked();
    void on_button_2_clicked();
    void on_button_3_clicked();
    void signals_returner(int buttonID);
    void on_button_4_clicked();
    void on_button_5_clicked();
    void on_button_6_clicked();
    void on_button_7_clicked();
    void on_button_8_clicked();
    void on_button_9_clicked();
    void on_quit_button_clicked();

signals:
    void signals_from_key(int buttonID);
private:
    Game game = Game();
    QPushButton **button;
    int cur_button;
    int circle;
    Ui::MainWindow *ui;
    void fill_field();
    void send_message(QString *arr);
    void exit_window(int flag);
};
#endif // MAINWINDOW_H
