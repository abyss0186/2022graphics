#include<GL/glut.h>
#include<stdio.h>
#include<mmsystem.h>
void timer(int t)
{
    ///1000代表一秒
    printf("鬧鐘%d,我起床了\n",t);
    printf("設定下一個鬧鐘\n");
    PlaySound("chicken.wav",NULL,SND_ASYNC);
    printf("設定好鬧鐘，在回去睡\n");
    glutTimerFunc(2000,timer,t+1);
}
void display()
{

}
int main (int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14_timer");
    glutTimerFunc(3000,timer,0);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
