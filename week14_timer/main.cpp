#include<GL/glut.h>
#include<stdio.h>
#include<mmsystem.h>
void timer(int t)
{
    ///1000�N��@��
    printf("�x��%d,�ڰ_�ɤF\n",t);
    printf("�]�w�U�@�Ӿx��\n");
    PlaySound("chicken.wav",NULL,SND_ASYNC);
    printf("�]�w�n�x���A�b�^�h��\n");
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
