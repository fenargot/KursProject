#ifndef POLLWINDOW_H
#define POLLWINDOW_H

#include <QMainWindow>
#include "menuwindow.h"
#include "mainwindow.h"

namespace Ui {
class PollWindow;
}

class PollWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PollWindow(QString username = nullptr);
    ~PollWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PollWindow *ui;
    QString username;
};

#endif // POLLWINDOW_H
