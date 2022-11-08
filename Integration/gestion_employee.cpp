#include "gestion_employee.h"
#include "ui_gestion_employee.h"

gestion_employee::gestion_employee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_employee)
{
    ui->setupUi(this);
}

gestion_employee::~gestion_employee()
{
    delete ui;
}
