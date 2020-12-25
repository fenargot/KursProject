#ifndef ANSWER_H
#define ANSWER_H

#include <QString>

class Answer {
private:
    QString answer;
    int result;
public:
    explicit Answer(QString answer = "", int result = 0) : answer(answer), result(result){}

    QString getAnswer() { return answer; }
    void setAnswer(QString answer) { this->answer = answer; }

    int getResult() { return result; }
    void setResult(int result) { this->result = result; }
};

#endif // ANSWER_H
