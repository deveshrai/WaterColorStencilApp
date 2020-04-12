#ifndef COLORSETTER_H
#define COLORSETTER_H

#include <QDialog>
#include <QColorDialog>

#include <mainwindow.h>
namespace Ui {
class colorsetter;
}

class colorsetter : public QDialog
{
    Q_OBJECT

public:
    explicit colorsetter(QWidget *parent = nullptr);
    ~colorsetter();

private slots:
    void on_pushButton_clicked();

    void on_col1btn_clicked();

    void on_col2btn_clicked();

    void on_col3btn_clicked();

    void on_col4btn_clicked();

    void on_buttonBox_accepted();

private:
    Ui::colorsetter *ui;
    QColor newColor1,newColor2,newColor3,newColor4;

};

#endif // COLORSETTER_H
