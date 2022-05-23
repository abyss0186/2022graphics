#include<GL/glut.h>
#include<stdio.h>
float angle[20]={},oldX=0;
int angleID=0;///0:�Ĥ@�����`
FILE *fout=NULL;
void myWrite()
{
    if(fout==NULL)
        fout=fopen("file.txt","w+");
    for(int i=0;i<20;i++)
    {
        printf(      " %.2f",angle[i]);
        fprintf(fout,"%.2f",angle[i]);
    }
    printf("\n");
    fprintf(fout,"\n");
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0')angleID=0;
    if(key=='1')angleID=1;
    if(key=='2')angleID=2;
    if(key=='3')angleID=3;
}
void mouse(int button,int state,int x,int y){
    oldX=x;
}
void motion(int x,int y){
    angle[angleID]+=(x-oldX);
    myWrite();
    oldX=x;
    glutPostRedisplay();///���e�e�� Re display

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.2);///����
    glPushMatrix();
        glTranslatef(0.3,0.5,0);///��U�����઺�F�豾��Y�B
        glRotatef(angle[0],0,0,1);///����
        glTranslatef(-0.3,-0.4,0);///����u����{�l����
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.8,0.3);
        glPushMatrix();
            glTranslatef(0.8,0.4,0);///��U�����઺�F�豾��Y�B
            glRotatef(angle[1],0,0,1);///����
            glTranslatef(-0.8,-0.4,0);///���y����{�l���ߥh
            glColor3f(0,1,0);
            glRectf(0.8,0.5,1.1,0.3);///�A�e�U��y
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0.5,0);///��U�����઺�F�豾��Y�B
        glRotatef(angle[2],0,0,1);///����
        glTranslatef(0.3,-0.4,0);///����u����{�l����
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.8,0.3);
        glPushMatrix();
            glTranslatef(-0.8,0.4,0);///��U�����઺�F�豾��Y�B
            glRotatef(angle[3],0,0,1);///����
            glTranslatef(0.8,-0.4,0);///���y����{�l���ߥh
            glColor3f(0,1,0);
            glRectf(-0.8,0.5,-1.1,0.3);///�A�e�U��y
            glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main (int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13_rect_TRT");
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}