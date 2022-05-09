#include<GL/glut.h>
#include<iostream>
#include<opencv/highgui.h>
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel=NULL;//�@�ӫ���G������������
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
	return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



        if(pmodel==NULL){
            pmodel=glmReadOBJ("data/Gundam.obj");//Ū�J�ҫ�
            glmUnitize(pmodel);//��ҫ��զ����j�p.-1..+1
            glmFacetNormals(pmodel);//��Facet���� �k�V�qNomals��X��
            glmVertexNormals(pmodel,90);//��Vertex���k�V�q�έ�������X��
        }
    glPushMatrix();
        glRotatef(angle,0,1,0);
        glmDraw(pmodel,GLM_MATERIAL|GLM_TEXTURE);
    glPopMatrix();
    glutSwapBuffers();
    angle++;
}

int main (int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(300,300);
    glutCreateWindow("week11_gundam");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);//�}��3D�\��

    glutMainLoop();
}