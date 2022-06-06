#include<GL/glut.h>
static void resize(int width, int height)
{///aspect ratio
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);///投影，把3D投影到2D
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    ///3D經過轉換到你最後的攝影機

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
void motion(int x,int y)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt((x-150)/15.0,(y-150)/15.0,3,
              0,0,0,
              0,1,0);
    glutPostRedisplay();
}
 void reshape(int w, int h)
{///aspect ratio
    const float ar = (float) w / (float) h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);///投影，把3D投影到2D
    glLoadIdentity();
    gluPerspective(60,ar,0.1,100);
    //glFrustum(, ar, -1.0, 1.0, 2.0, 100.0);
    ///3D經過轉換到你最後的攝影機

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    gluLookAt(0,0,3,0,0,0,0,1,0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glColor3f(1,1,0);
    glutSolidTeapot(1);
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
glutCreateWindow("week16 camera lookat");



glutReshapeFunc(reshape);
glutDisplayFunc(display);
glutMotionFunc(motion);



glutMainLoop();
}
