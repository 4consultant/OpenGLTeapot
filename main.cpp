#include "widget.h"

#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    Widget w;
//    w.show();
//    return a.exec();
//}
#include <QOpenGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class TeapotWidget : public QOpenGLWidget {
public:
    void initializeGL() override {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    void resizeGL(int w, int h) override {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0, (float)w / h, 0.1, 100.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    void paintGL() override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glutSolidTeapot(1.0);
    }
};

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    QApplication app(argc, argv);
    TeapotWidget widget;
    widget.show();
    return app.exec();
}
