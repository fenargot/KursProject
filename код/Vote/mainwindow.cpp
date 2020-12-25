#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_authorization_clicked()
{
    QString username = ui->lineEdit->text();
    List<User> *userList = new List<User>();
    File::openUser(userList, "user.txt");
    bool flag = false;
    for (int i = 0; i < userList->size(); i++) {
        if (username == userList->operator[](i).getUsername()) {
            flag = true;
        }
    }
    if (!flag) {
        User newUser(username, false);
        userList->pushTail(newUser);
        File::saveUser(userList, "user.txt");
    }
    MenuWindow *w = new MenuWindow(username);
    w->show();
    this->close();
    delete this;
}

void MainWindow::on_exit_clicked()
{
    QApplication::exit(0);
}
