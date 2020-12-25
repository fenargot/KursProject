#include "resulttableform.h"
#include "ui_resulttableform.h"

ResultTableForm::ResultTableForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultTableForm)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    Question *question = new Question;
    File::openQuestion(question, "question.txt");
    ui->label_2->setText(question->getQuestion());
    List<Answer> *answerList = new List<Answer>();
    File::openAnswer(answerList, "answer.txt");
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Вариант ответа"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Количество голосов"));
    for (int i = 0; i < answerList->size(); i++) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(answerList->operator[](i).getAnswer()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(answerList->operator[](i).getResult())));
    }
    ui->tableWidget->resizeColumnsToContents();
}

ResultTableForm::~ResultTableForm()
{
    delete ui;
}

void ResultTableForm::on_pushButton_clicked()
{
    this->close();
    delete this;
}
