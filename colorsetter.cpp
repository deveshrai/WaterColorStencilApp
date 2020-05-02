#include "colorsetter.h"
#include "ui_colorsetter.h"

colorsetter::colorsetter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::colorsetter)
{
    ui->setupUi(this);
}

colorsetter::~colorsetter()
{
    delete ui;
}



void colorsetter::on_col1btn_clicked()
{
    newColor1=QColorDialog::getColor();
    ui->col1btn->setStyleSheet("background:rgb("+QString::number(newColor1.red())+","+QString::number(newColor1.green())+","+QString::number(newColor1.blue())+");border:none;");

}

void colorsetter::on_col2btn_clicked()
{
    newColor2=QColorDialog::getColor();
    ui->col2btn->setStyleSheet("background:rgb("+QString::number(newColor2.red())+","+QString::number(newColor2.green())+","+QString::number(newColor2.blue())+");border:none;");

}

void colorsetter::on_col3btn_clicked()
{
    newColor3=QColorDialog::getColor();
    ui->col3btn->setStyleSheet("background:rgb("+QString::number(newColor3.red())+","+QString::number(newColor3.green())+","+QString::number(newColor3.blue())+");border:none;");

}

void colorsetter::on_col4btn_clicked()
{
    newColor4=QColorDialog::getColor();
    ui->col4btn->setStyleSheet("background:rgb("+QString::number(newColor4.red())+","+QString::number(newColor4.green())+","+QString::number(newColor4.blue())+");border:none;");

}

void colorsetter::on_buttonBox_accepted()
{
    MainWindow *par = qobject_cast<MainWindow*> (parent());
    par->setPrimaryColors(newColor1,newColor2,newColor3,newColor4,newColor5,newColor6,newColor7);

}

void colorsetter::on_col5btn_clicked()
{
    newColor5=QColorDialog::getColor();
    ui->col5btn->setStyleSheet("background:rgb("+QString::number(newColor5.red())+","+QString::number(newColor5.green())+","+QString::number(newColor5.blue())+");border:none;");
}

void colorsetter::on_col6btn_clicked()
{
    newColor6=QColorDialog::getColor();
    ui->col6btn->setStyleSheet("background:rgb("+QString::number(newColor6.red())+","+QString::number(newColor6.green())+","+QString::number(newColor6.blue())+");border:none;");

}

void colorsetter::on_col7btn_clicked()
{
    newColor7=QColorDialog::getColor();
    ui->col7btn->setStyleSheet("background:rgb("+QString::number(newColor7.red())+","+QString::number(newColor7.green())+","+QString::number(newColor7.blue())+");border:none;");

}
