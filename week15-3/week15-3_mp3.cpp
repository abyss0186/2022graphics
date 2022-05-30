#include "CMP3_MCI.h"
#include<stdio.h>
CMP3_MCI mp3;
int main()
{
    mp3.Load("door_chime0.mp3");
    mp3.Play();
    printf("door bell\n");
    int N;
    scanf("%d",&N);
}
