#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define pi 3.1415926535
int main()
{
    system("chcp 1251 > nul");
    float r, s, v;
    int i;
    printf("������� ������ ������ ");
        do
        {
        i=scanf("%f", &r);
        if (i==1 && r>0) 
        {          
        s=4*pi*r*r;  
        printf("������� �����: %.2f\n", s);
        v=4*pi*r*r*r/3;
        printf("����� ����: %.2f\n", v);
        }
        else
        { 
        printf("������������ ����, ����������� ������ ������ ������");
        }
        }
        while(i==1);
    getch();
    return 0;
}