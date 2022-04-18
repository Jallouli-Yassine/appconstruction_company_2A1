#ifndef GESTION_EMPLOYEE_H
#define GESTION_EMPLOYEE_H

#include <QMainWindow>

namespace Ui {
class gestion_employee;
}

class gestion_employee : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_employee(QWidget *parent = nullptr);
    ~gestion_employee();

private:
    Ui::gestion_employee *ui;
};

#endif // GESTION_EMPLOYEE_H
