#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define pi 3.1415926535
int main()
{ 
    system("chcp 1251 > nul");
    float r, s, v;
    //int k;
    scanf("%f",&r);
    //while (k<0)
    //{
    if (scanf("%f", &r)!=0 && r>0) 
    {
    s=4*pi*r*r;  
    printf("������� �����: %.2f\n", s);
    v=4*pi*r*r*r/3;
    printf("����� ����: %.2f\n", v);
    //break;
    //k++;
    }
    else
    { 
    printf("������������ ����, ����������� ������ ������ ������");
    }
    //}
    getch();
    return 0;
}


