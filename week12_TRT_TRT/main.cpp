#include<GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot(0.3);//大茶壺
    glPushMatrix();
        glTranslatef(0.3,0,0);//把下面旋轉的東西掛到某處
        glRotatef(angle,0,0,1);//旋轉
        glTranslatef(0.2,0,0);//把把手移到某處
        glColor3f(1,0,0);
        glutSolidTeapot(0.2);//小茶壺
        glPushMatrix();
            glTranslatef(0.3,0,0);//把下面旋轉的東西掛到某處
            glRotatef(angle,0,0,1);//旋轉
            glTranslatef(0.2,0,0);//把把手移到某處
            glColor3f(1,0,0);
            glutSolidTeapot(0.2);//小茶壺
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.1;
}
int main (int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12_TRT_TRT");
    glutIdleFunc(display);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
