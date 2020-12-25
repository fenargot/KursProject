#ifndef USER_H
#define USER_H

#include <QString>

class User {
private:
    QString username;
    bool active;
public:
    explicit User(QString username = "", bool active = false) : username(username), active(active) {}

    QString getUsername() { return username; }
    bool getActive() { return active; }

    void setUsername(QString username) { this->username = username; }
    void setActive(bool active) { this->active = active; }
};

#endif // USER_H
