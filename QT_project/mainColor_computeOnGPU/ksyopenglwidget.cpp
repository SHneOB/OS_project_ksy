#include "ksyopenglwidget.h"
#include<QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QDebug>
#include <QImage>
#include <QOpenGLBuffer>
KSYOpenGLWidget::KSYOpenGLWidget(QWidget *parent):QOpenGLWidget(parent) {}
void KSYOpenGLWidget::initializeGL()//设置OpenGL资源和状态，第一次调用resizeGL/paintGL时调用
{
    //初始化OpenGL函数，将这些OpenGL的函数指针（即Qt中用于调用OpenGL函数的指针）指向显卡驱动提供的具体函数实现
    initializeOpenGLFunctions();
    // 加载并编译着色器
    if (!shaderProgram.addShaderFromSourceFile(QOpenGLShader::Compute, ":/compute_shader.comp")) {
        qWarning() << "Fail complie:" << shaderProgram.log();
        return;
    }
    // 连接着色器
    if (!shaderProgram.link()) {
        qWarning() << "fail link:" << shaderProgram.log();
        return;
    }
}

void KSYOpenGLWidget::resizeGL(int w, int h)//设置OpenGL视口，投影等，Widget调整大小(或首次显示)时调用
{
    glViewport(0, 0, 1, 1);
}

void KSYOpenGLWidget::paintGL()//渲染OpenGL场景，Widget需要更新时会调用
{

}

void KSYOpenGLWidget::DrawTriangle()
{
    isDraw=true;//需要绘制图形
    DrawType = GL_TRIANGLES;//绘制三角形
    update();//刷新
}

void KSYOpenGLWidget::clearDraw()
{
    isDraw = false;
    update();
}

void KSYOpenGLWidget::setglPolygonMode(bool isWire)
{
    makeCurrent();//使当前上下文生效
    if(isWire){
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);//设置线框模式
    }else
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);//设置线框模式
    doneCurrent();//取消上下文生效
    update();
}

void KSYOpenGLWidget::computeMainColor(){
    //加载图片
    QImage image=CsImage;
    if(image.isNull())qDebug()<<"图片加载失败";
    else qDebug()<<"图片加载成功:"<<image;
    // 创建一个 QOpenGLTexture 对象
    GLuint uTexture[2];
    // 将 QImage 转换为 OpenGL 纹理
    glGenTextures(1, &uTexture[0]);
    glBindTexture(GL_TEXTURE_2D, uTexture[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // 上传图像数据到纹理
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
    glBindImageTexture(0, uTexture[0], 0, GL_FALSE, 0, GL_READ_ONLY, GL_RGBA8);

    //创建缓冲区指针SSBO
    QOpenGLBuffer ssbo;
    ssbo.create();
    ssbo.bind();
    ssbo.allocate(256 * 3 * sizeof(GLuint)); // 为 RGB 直方图分配空间
    // 准备要写入缓冲区的数据
    std::vector<GLuint> initialData(256 * 3, 0); // 初始化所有值为0的向量
    // 将空数据写入缓冲区 否则再次对缓冲区数据进行访问时 数据会积累
    ssbo.write(0, initialData.data(), initialData.size() * sizeof(GLuint));
    // 绑定 SSBO 到正确的绑定点 binding=1(.comp)
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, ssbo.bufferId());

    //绑定着色器并启用纹理
    shaderProgram.bind();
    //glActiveTexture(GL_TEXTURE0); // 使纹理GL_TEXTURE0激活 好像不用加

    // 设置工作区大小 越大 进行采样越多
    int workGroupsX = image.width()/1; //全局工作区大小为 图片尺寸/局部工作区大小
    int workGroupsY = image.height()/1;
    glDispatchCompute(workGroupsX, workGroupsY, 1);
    //确保计算完成
    glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

    // 从缓冲区读回直方图数据
    ssbo.bind();
    GLuint *histogramData = static_cast<GLuint*>(ssbo.map(QOpenGLBuffer::ReadOnly));
    GLuint redCount = 0;
    GLuint greenCount = 0;
    GLuint blueCount =  0;
    GLuint A=0;
    GLuint totalCount = 0;
    if (histogramData) {
        qDebug()<<"读取直方图成功";
        // 找到R、G、B通道的主色调
        redCount = histogramData[0];
        greenCount =histogramData[1];
        blueCount = histogramData[2];
        A = histogramData[3];
        totalCount = histogramData[4];
    }
    qDebug()<<"redCount"<<redCount<<"greenCount"<<greenCount<<"blueCount"<<blueCount<<"A"<<A<<"totalCount:"<<totalCount;
    uint r=redCount;uint g = greenCount;uint b = blueCount;uint a = A;uint t = totalCount;//必须设置uint 否则爆数
    qDebug()<<"R"<<r<<"G"<<g<<"B"<<b<<"A"<<a<<"t:"<<t;
    QColor mainColor;
    // 假设 b, g, r, a 是你的原始颜色分量（0-255），t 是某个缩放因子
    int b_scaled = static_cast<int>((1.2 * b) / t); // 确保结果是一个整数
    int g_scaled = static_cast<int>((1.2 * g) / t);
    int r_scaled = static_cast<int>((1.2 * r) / t);
    int a_scaled = static_cast<int>((1.2 * a) / t);
    // 确保每个分量都在 0 到 255 之间
    b_scaled = qBound(0, b_scaled, 255);
    g_scaled = qBound(0, g_scaled, 255);
    r_scaled = qBound(0, r_scaled, 255);
    a_scaled = qBound(0, a_scaled, 255);
    // 使用 QRgb 来组合颜色分量 (r_scaled和b_scaled互换位置)
    QRgb rgba = qRgba(b_scaled, g_scaled, r_scaled, a_scaled);
    //设置颜色
    mainColor.setRgba(rgba);
    qDebug()<<"mainColor"<<mainColor;
    CsColor = mainColor;

    // 清理工作
    ssbo.unmap(); // 确保在销毁SSBO之前已经解映射
    shaderProgram.release(); // 解绑着色器程序
    glDeleteTextures(1, uTexture); // 删除纹理对象
}
/*
    //从GPU获取RGB竟然是倒着的 以BGR的顺序传回 此处b=r r=b;
    mainColor.setRgb((1.2*b/t)>255?255:(1.2*b/t),
                     (1.2*g/t)>255?255:(1.2*g/t),
                     (1.2*r/t)>255?255:(1.2*r/t));
    */
