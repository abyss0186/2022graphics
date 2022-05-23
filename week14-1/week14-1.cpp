///week14-1.cpp step01-1
///Ωm≤ﬂ∂}¿…√ˆ¿…

#include<stdio.h>
int main()
{
    FILE *fout = fopen ("file.txt","w+");
    printf("hello world\n");
    fprintf(fout,"hello world\n");

    fclose(fout);
}
