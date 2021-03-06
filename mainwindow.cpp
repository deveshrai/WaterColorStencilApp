#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->colors.append(qRgb(18,41,74));//qRgb(71,133,168)); //Blue
    this->colors.append(qRgb(220,36,28)); //Dark Red
    this->colors.append(qRgb(240,219,41)); //Yellow
    this->colors.append(qRgb(0,125,92)); //Dark Green
    this->colors.append(qRgb(0,221,212)); //Dark Green
    this->colors.append(qRgb(242,180,53)); //Dark Green
    this->colors.append(qRgb(25,25,25)); //Black
    //this->colors.append(qRgb(255,255,255)); //White


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPrimaryColors(QColor newColor1,QColor newColor2,QColor newColor3,QColor newColor4,QColor newColor5, QColor newColor6, QColor newColor7)
{
    ui->Color5Button->setStyleSheet("background:rgb("+QString::number(newColor5.red())+","+QString::number(newColor5.green())+","+QString::number(newColor5.blue())+");border:none;");
    ui->Color4Button->setStyleSheet("background:rgb("+QString::number(newColor4.red())+","+QString::number(newColor4.green())+","+QString::number(newColor4.blue())+");border:none;");
    ui->Color3Button->setStyleSheet("background:rgb("+QString::number(newColor3.red())+","+QString::number(newColor3.green())+","+QString::number(newColor3.blue())+");border:none;");
    ui->Color2Button->setStyleSheet("background:rgb("+QString::number(newColor2.red())+","+QString::number(newColor2.green())+","+QString::number(newColor2.blue())+");border:none;");
    ui->Color1Button->setStyleSheet("background:rgb("+QString::number(newColor1.red())+","+QString::number(newColor1.green())+","+QString::number(newColor1.blue())+");border:none;");
    ui->Color6Button->setStyleSheet("background:rgb("+QString::number(newColor6.red())+","+QString::number(newColor6.green())+","+QString::number(newColor6.blue())+");border:none;");
    ui->Color7Button->setStyleSheet("background:rgb("+QString::number(newColor7.red())+","+QString::number(newColor7.green())+","+QString::number(newColor7.blue())+");border:none;");

    this->colors.clear();
    colors.append(qRgb(newColor1.red(),newColor1.green(),newColor1.blue()));
    colors.append(qRgb(newColor2.red(),newColor2.green(),newColor2.blue()));
    colors.append(qRgb(newColor3.red(),newColor3.green(),newColor3.blue()));
    colors.append(qRgb(newColor4.red(),newColor4.green(),newColor4.blue()));
    colors.append(qRgb(newColor5.red(),newColor5.green(),newColor5.blue()));
    colors.append(qRgb(newColor6.red(),newColor6.green(),newColor6.blue()));
    colors.append(qRgb(newColor7.red(),newColor7.green(),newColor7.blue()));

}

void MainWindow::on_actionOpen_triggered()
{
    QString Filename = QFileDialog::getOpenFileName(this,"Open Image","~",tr("Image Files (*.png *.jpg *.bmp)"));
    if(Filename.length()>3)
    {
        img=QImage(Filename);
        std::vector <int> x;
        std::vector <int> y;
        //img=img.scaledToWidth(1280);
        img=img.scaledToHeight(900);

        coloredImage=img.convertToFormat(QImage::Format_Indexed8,
                                                 colors,
                                                 Qt::OrderedDither|Qt::MonoOnly);
        //ui->ImageLabel->setPixmap(QPixmap::fromImage(coloredImage));
        nI=coloredImage.convertToFormat(QImage::Format_ARGB32);
        bI = nI;
        cI = nI;
        iC1=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
        iC2=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
        iC3=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
        iC4=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
        iC5=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
        iC6=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
        iC7=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
        kI = QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
        for(int i=0;i<nI.width()-1;i++)
        {
            //vector<unsigned char> row;
            for(int j=0;j<nI.height()-1;j++)
            {

                if(nI.pixelColor(i,j)==QColor::fromRgb(colors[0]))
                    iC1.setPixelColor(i,j,QColor::fromRgb(colors[0]));
                else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[1]))
                    iC2.setPixelColor(i,j,QColor::fromRgb(colors[1]));
                else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[2]))
                    iC3.setPixelColor(i,j,QColor::fromRgb(colors[2]));
                else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[3]))
                    iC4.setPixelColor(i,j,QColor::fromRgb(colors[3]));
                else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[4]))
                    iC5.setPixelColor(i,j,QColor::fromRgb(colors[4]));
                else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[5]))
                    iC6.setPixelColor(i,j,QColor::fromRgb(colors[5]));
                else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[6]))
                {
                    iC7.setPixelColor(i,j,QColor::fromRgb(colors[6]));
                    kI.setPixelColor(i,j,QColor::fromRgb(colors[6]));
                }
//        kI=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
//        for(int i=0;i<nI.width()-1;i++)
//        {

//            //vector<unsigned char> row;
//            for(int j=0;j<nI.height()-1;j++)
//            {
//                if(nI.pixelColor(i,j)==QColor::fromRgb(colors[0]))//Blue
//                    iC1.setPixelColor(i,j,QColor::fromRgb(colors[0]));
//                else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[1]))//Red
//                    iC2.setPixelColor(i,j,QColor::fromRgb(colors[1]));
//                else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[2]))//yellow
//                    iC3.setPixelColor(i,j,QColor::fromRgb(colors[2]));
//                else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[3]))//green
//                    iC4.setPixelColor(i,j,QColor::fromRgb(colors[3]));
//                else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[4]))
//                {
//                    iC5.setPixelColor(i,j,QColor::fromRgb(colors[4]));
//                    kI.setPixelColor(i,j,QColor::fromRgb(colors[4]));
//                }
                //row.push_back(img.pixelColor(__tempCnt1,__tempCnt2).blackF());


                if(nI.pixelColor(i,j)!=nI.pixel(i,j+1)||nI.pixelColor(i,j)!=nI.pixel(i+1,j))
                {

                    cI.setPixelColor(i,j,nI.pixelColor(i,j));
                    nI.setPixelColor(i,j,QColor::fromRgb(qRgb(25,25,25)));
                    bI.setPixelColor(i,j,QColor::fromRgb(qRgb(25,25,25)));
                    kI.setPixelColor(i,j,bI.pixelColor(i,j));

                }
                else
                {
                    bI.setPixelColor(i,j,QColor::fromRgb(qRgb(255,255,255)));
                    cI.setPixelColor(i,j,QColor::fromRgb(qRgb(255,255,255)));
                }
            }
        }

        ui->ImageLabel->setPixmap(QPixmap::fromImage(coloredImage));
    }
}

void MainWindow::on_Color5Button_clicked()
{
    if(colorMode==0)
    {
        colorMode=1;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(iC5));
    }
    else
    {
        colorMode=0;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(coloredImage));
    }

}

void MainWindow::on_Color4Button_clicked()
{
    if(colorMode==0)
    {
        colorMode=1;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(iC4));
    }
    else
    {
        colorMode=0;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(coloredImage));
    }
}

void MainWindow::on_Color3Button_clicked()
{
    if(colorMode==0)
    {
        colorMode=1;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(iC3));
    }
    else
    {
        colorMode=0;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(coloredImage));
    }
}

void MainWindow::on_Color2Button_clicked()
{
    if(colorMode==0)
    {
        colorMode=1;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(iC2));
    }
    else
    {
        colorMode=0;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(coloredImage));
    }
}

void MainWindow::on_Color1Button_clicked()
{
    if(colorMode==0)
    {
        colorMode=1;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(iC1));
    }
    else
    {
        colorMode=0;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(coloredImage));
    }
}

void MainWindow::on_actionChoose_Colours_triggered()
{
    colorsetter *cs = new colorsetter(this);
    cs->exec();
}

void MainWindow::on_actionReloadColors_triggered()
{
    nI = QImage(img.width(),img.height(),QImage::Format_ARGB32);
    bI = QImage(img.width(),img.height(),QImage::Format_ARGB32);
    cI= QImage(img.width(),img.height(),QImage::Format_ARGB32);
    coloredImage=img.convertToFormat(QImage::Format_Indexed8,
                                             colors,
                                             Qt::OrderedDither|Qt::MonoOnly);
    //ui->ImageLabel->setPixmap(QPixmap::fromImage(coloredImage));
    nI=coloredImage.convertToFormat(QImage::Format_ARGB32);
    bI = nI;
    cI = nI;
    iC1=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
    iC2=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
    iC3=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
    iC4=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
    iC5=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
    iC6=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
    iC7=QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
    kI = QImage(nI.width(),nI.height(),QImage::Format_ARGB32);
    for(int i=0;i<nI.width()-1;i++)
    {
        //vector<unsigned char> row;
        for(int j=0;j<nI.height()-1;j++)
        {

            if(nI.pixelColor(i,j)==QColor::fromRgb(colors[0]))
                iC1.setPixelColor(i,j,QColor::fromRgb(colors[0]));
            else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[1]))
                iC2.setPixelColor(i,j,QColor::fromRgb(colors[1]));
            else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[2]))
                iC3.setPixelColor(i,j,QColor::fromRgb(colors[2]));
            else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[3]))
                iC4.setPixelColor(i,j,QColor::fromRgb(colors[3]));
            else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[4]))
                iC5.setPixelColor(i,j,QColor::fromRgb(colors[4]));
            else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[5]))
                iC6.setPixelColor(i,j,QColor::fromRgb(colors[5]));
            else if(nI.pixelColor(i,j)==QColor::fromRgb(colors[6]))
            {
                iC7.setPixelColor(i,j,QColor::fromRgb(colors[6]));
                kI.setPixelColor(i,j,QColor::fromRgb(colors[4]));
            }
            //row.push_back(img.pixelColor(__tempCnt1,__tempCnt2).blackF());
            if(nI.pixelColor(i,j)!=nI.pixel(i,j+1)||nI.pixelColor(i,j)!=nI.pixel(i+1,j))
            {
                cI.setPixelColor(i,j,nI.pixelColor(i,j));
                nI.setPixelColor(i,j,QColor::fromRgb(qRgb(25,25,25)));
                bI.setPixelColor(i,j,QColor::fromRgb(qRgb(25,25,25)));
                kI.setPixelColor(i,j,bI.pixelColor(i,j));

            }
            else
            {
                bI.setPixelColor(i,j,QColor::fromRgb(qRgb(255,255,255)));
                cI.setPixelColor(i,j,QColor::fromRgb(qRgb(255,255,255)));

            }


        }
    }
    ui->ImageLabel->setPixmap(QPixmap::fromImage(coloredImage));
}

void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,"Save Image",tr("~"),tr("Image Files (*.png *.jpg *.bmp)"));
    if(filename >3)
    {
        switch (colorMode)
        {
        case 0:
            coloredImage.save(filename);
            break;
        case 1:
            nI.save(filename);
            break;
        case 2:
            bI.save(filename);
            break;
        case 3:
            cI.save(filename);
            break;
        }

    }
}

void MainWindow::on_actionNew_triggered()
{
    ui->ImageLabel->setPixmap(QPixmap());
    img=QImage();


}

void MainWindow::on_Color6Button_clicked()
{
    if(colorMode==0)
    {
        colorMode=1;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(iC6));
    }
    else
    {
        colorMode=0;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(coloredImage));
    }
}

void MainWindow::on_Color7Button_clicked()
{
    if(colorMode==0)
    {
        colorMode=1;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(nI));
    }
    else if(colorMode==1)
    {
        colorMode=2;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(bI));
    }
    else if(colorMode==2)
    {
        colorMode=3;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(cI));
    }
    else if(colorMode==3)
    {
        colorMode=4;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(iC7));
    }
    else if(colorMode==4)
    {
        colorMode=5;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(kI));
    }
    else
    {
        colorMode=0;
        ui->ImageLabel->setPixmap(QPixmap::fromImage(coloredImage));
    }
}
