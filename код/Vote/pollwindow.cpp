#include "pollwindow.h"
#include "ui_pollwindow.h"

PollWindow::PollWindow(QString username) :
    username(username),
    ui(new Ui::PollWindow)
{
    ui->setupUi(this);
    Question *question = new Question;
    File::openQuestion(question, "question.txt");
    ui->label_2->setText(question->getQuestion());
    List<Answer> *answerList = new List<Answer>();
    File::openAnswer(answerList, "answer.txt");
    for (int i = 0; i < answerList->size(); i++) {
        ui->listWidget->addItem(QString::number(i + 1) + ". " + answerList->operator[](i).getAnswer());
    }
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(answerList->size());
}

PollWindow::~PollWindow()
{
    delete ui;
}

void PollWindow::on_pushButton_clicked()
{
    MenuWindow* w = new MenuWindow(username);
    w->show();
    this->close();
    delete this;
}

void PollWindow::on_pushButton_2_clicked()
{
    List<Answer> *answerList = new List<Answer>();
    File::openAnswer(answerList, "answer.txt");
    int number = ui->spinBox->text().toInt() - 1;
    answerList->operator[](number).setResult(answerList->operator[](number).getResult() + 1);
    List<User> *userList = new List<User>();
    File::openUser(userList, "user.txt");
    for (int i = 0; i < userList->size(); i++) {
        if (username == userList->operator[](i).getUsername()) {
            userList->operator[](i).setActive(true);
        }
    }
    File::saveUser(userList, "user.txt");
    File::saveAnswer(answerList, "answer.txt");
    MenuWindow* w = new MenuWindow(username);
    w->show();
    this->close();
    delete this;
}
