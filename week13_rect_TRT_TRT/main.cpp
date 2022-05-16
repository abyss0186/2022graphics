#include<GL/glut.h>
float angle=0,oldX=0;
void mouse(int button,int state,int x,int y){
    oldX=x;
}
void motion(int x,int y){
    angle+=(x-oldX);
    oldX=x;
    glutPostRedisplay();///重畫畫面 Re display

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.2);///身體
    glPushMatrix();
        glTranslatef(0.3,0.5,0);///把下面旋轉的東西掛到某處
        glRotatef(angle,0,0,1);///旋轉
        glTranslatef(-0.3,-0.4,0);///把手臂移到肚子中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.8,0.3);
        glPushMatrix();
            glTranslatef(0.8,0.4,0);///把下面旋轉的東西掛到某處
            glRotatef(angle,0,0,1);///旋轉
            glTranslatef(-0.8,-0.4,0);///把手肘移到肚子中心去
            glColor3f(0,1,0);
            glRectf(0.8,0.5,1.1,0.3);///再畫下手肘
            glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main (int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    //glutInitWindowSize(600,600);
    glutCreateWindow("week13_rect_TRT");
    //glutIdleFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
