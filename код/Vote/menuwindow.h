#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "pollwindow.h"

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QString username = nullptr);
    ~MenuWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MenuWindow *ui;
    QString username;
};

#endif // MENUWINDOW_H
