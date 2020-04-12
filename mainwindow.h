#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <vector>

#include "colorsetter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setPrimaryColors(QColor newColor1,QColor newColor2,QColor newColor3,QColor newColor4);

private slots:
    void on_actionOpen_triggered();

    void on_Color5Button_clicked();

    void on_Color4Button_clicked();

    void on_Color3Button_clicked();

    void on_Color2Button_clicked();

    void on_Color1Button_clicked();

    void on_actionChoose_Colours_triggered();

    void on_actionReloadColors_triggered();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    QVector <QRgb> colors;
    QImage coloredImage;
    int colorMode=0;
    QImage bI;
    QImage nI, iC1,iC2,iC3,iC4;
    QImage img;


};

#endif // MAINWINDOW_H
