#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openGLWidget = new KSYOpenGLWidget(parent);//该指针(openGLWidget)已挂载到QT的对象树上 会自动回收
    //setCentralWidget(openGLWidget);//将自定义的openGLWidegt设置为CentralWidget
    openGLWidget->showMinimized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_selectPicture_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("Images (*.jpg *.bmp *.png)")); // 修改文件过滤器
    qDebug() << "filename:" << filename;
    QImage image(filename); // 图片初始化
    if(image.isNull())qDebug()<<"图片加载失败";
    else{
        qDebug()<<"图片加载成功:"<<image;
        openGLWidget->CsImage = image;//赋给全局图片
        ui->selectedPicture->setPixmap(QPixmap::fromImage(image));
    }
}


void MainWindow::on_btn_computeInGPU_clicked()
{
    openGLWidget->computeMainColor();//调用主色调计算函数
    // 设置 QLabel 的背景色
    QColor mainColor = openGLWidget->CsColor;
    QString styleSheet = QString("QLabel { background-color: rgb(%1, %2, %3); }")
                             .arg(mainColor.red())
                             .arg(mainColor.green())
                             .arg(mainColor.blue());
    ui->mainColor->setStyleSheet(styleSheet);//显示主色调颜色
    QString ColorInfo = mainColor.name();
    ui->MainColor_info->setText(ColorInfo);
    ui->menubar->setStyleSheet(styleSheet);
}

