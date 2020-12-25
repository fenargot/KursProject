#ifndef FILE_H
#define FILE_H

#include "user.h"
#include "question.h"
#include "answer.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class File {
public:
    static void openQuestion(Question *question, string file) {
        ifstream in(file);
        while (!in.eof()) {
            string quest;
            getline(in, quest);
            if (quest == "") break;
            question = new Question(QString::fromStdString(quest));
        }
        in.close();
    }

    static void saveQuestion(Question *question, string file) {
        ofstream on(file);
        on << question->getQuestion().toStdString();
        on.close();
    }

    static void openAnswer(List<Answer> *answerList, string file) {
        ifstream in(file);
        while (!in.eof()) {
            string answer;
            int result;
            getline(in, answer);
            if (answer == "") break;
            in >> result;
            in.get();
            Answer newAnswer(QString::fromStdString(answer), result);
            answerList->pushTail(newAnswer);
        }
        in.close();
    }

    static void saveAnswer(List<Answer> *answerList, string file) {
        ofstream on(file);
        for (int i = 0; i < answerList->size(); i++) {
            on << answerList->operator[](i).getAnswer().toStdString() << endl;
            on << answerList->operator[](i).getResult() << endl;
        }
        on.close();
    }

    static void openUser(List<User> *userList, string file) {
        ifstream in(file);
        while (!in.eof()) {
            string username;
            bool active;
            getline(in, username);
            if (username == "") break;
            in >> active;
            in.get();
            User newUser(QString::fromStdString(username), active);
            userList->pushTail(newUser);
        }
        in.close();
    }

    static void saveUser(List<User> *userList, string file) {
        ofstream on(file);
        for (int i = 0; i < userList->size(); i++) {
            on << userList->operator[](i).getUsername().toStdString() << endl;
            on << userList->operator[](i).getActive() << endl;
        }
        on.close();
    }
};

#endif // FILE_H
