#ifndef QUESTION_H
#define QUESTION_H

#include <QString>

class Question {
private:
    QString question;
public:
    explicit Question(QString question = "") : question(question) {}

    QString getQuestion() { return question; }
    void setQuestion(QString question) { this->question = question; }
};

#endif // QUESTION_H
