#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    system("chcp 1251 > nul");
    float a, b, c;
    int i=0;
    printf("������� a, b � �: ");
    if (scanf("%f %f %f", &a, &b, &c)==3)
        {
        if(a*b==1)
        i+=1;
        if(b*c==1)
        i+=1;
        if(a*c==1)
        i+=1;
        printf("���������� ������� �������� ���: %d",i);
        }
        else
        { 
        printf("������������ ����, ����������� ������ ������ ������");
        }
    getch();
    return 0;
}