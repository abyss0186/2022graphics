
#include<windows.h>
#include<stdio.h>
int main()
{
    printf("now play sound() before\n");
    PlaySound("chicken.wav", NULL , SND_ASYNC);
    printf("now play sound() after\n");
    int n;
    scanf("%d",&n);///等你輸入數字
}
