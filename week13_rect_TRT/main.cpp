
#include<GL/glut.h>
float angle=45,oldX=0;
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
    glRectf(0.5,0.5,-0.5,-0.5);
    glPushMatrix();
        glTranslatef(0.5,0.5,0);///把下面旋轉的東西掛到某處
        glRotatef(angle,0,0,1);///旋轉
        glTranslatef(-0.5,-0.4,0);///把把手移到肚子中心
        glColor3f(1,0,0);
        glRectf(0.5,0.5,1.0,0.3);
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








