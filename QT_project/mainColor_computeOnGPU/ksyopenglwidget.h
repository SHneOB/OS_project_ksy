#ifndef KSYOPENGLWIDGET_H
#define KSYOPENGLWIDGET_H
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include<QOpenGLFunctions_4_5_Core> //另外引入的Function
class KSYOpenGLWidget : public QOpenGLWidget,QOpenGLFunctions_4_5_Core//继承多个
{
    Q_OBJECT
public:
    explicit KSYOpenGLWidget(QWidget *parent = nullptr);//explicit 防止构造函数被用于隐式类型转换
    //在cpp文件中重载3个QOpenGLWidget中的虚函数，可以重载，用于实现典型的OpneGL任务
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

    void computeMainColor();
    void DrawTriangle();//绘制三角形
    void clearDraw();//清空图形
    void setglPolygonMode(bool isWire);//设置线框模式
    QOpenGLShaderProgram shaderProgram;//头文件定义封装类 shaderProgram
    QColor CsColor;
    QImage CsImage;
private:
    bool isDraw=false;//是否绘制
    int DrawType=GL_TRIANGLES;//绘制图形的样式
};

#endif // KSYOPENGLWIDGET_H
