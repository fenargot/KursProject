#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "resulttableform.h"

MenuWindow::MenuWindow(QString username) :
    username(username),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    List<User> *userList = new List<User>();
    File::openUser(userList, "user.txt");
    for (int i = 0; i < userList->size(); i++) {
        if (username == userList->operator[](i).getUsername()) {
            if (userList->operator[](i).getActive()) {
                ui->pushButton_3->setHidden(true);
            }
        }
    }
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_pushButton_3_clicked()
{
    PollWindow *w = new PollWindow(username);
    w->show();
    this->close();
    delete this;
}

void MenuWindow::on_pushButton_2_clicked()
{
    ResultTableForm *w = new ResultTableForm();
    w->show();
}

void MenuWindow::on_pushButton_clicked()
{
    MainWindow *w = new MainWindow;
    w->show();
    this->close();
    delete this;
}
