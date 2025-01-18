#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ksyopenglwidget.h"
#include<QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QDebug>
#include <QImage>
#include <QOpenGLBuffer>
#include <QOpenGLWidget>
#include<QOpenGLFunctions_4_5_Core>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    KSYOpenGLWidget *openGLWidget;
private slots:
    void on_btn_selectPicture_clicked();
    void on_btn_computeInGPU_clicked();
};
#endif // MAINWINDOW_H
