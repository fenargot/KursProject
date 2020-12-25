#ifndef RESULTTABLEFORM_H
#define RESULTTABLEFORM_H

#include <QWidget>
#include "menuwindow.h"

namespace Ui {
class ResultTableForm;
}

class ResultTableForm : public QWidget
{
    Q_OBJECT

public:
    explicit ResultTableForm(QWidget *parent = nullptr);
    ~ResultTableForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ResultTableForm *ui;
};

#endif // RESULTTABLEFORM_H
