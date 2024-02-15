#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define pi 3.1415926535
int main()
{
    system("chcp 1251 > nul");
    float r, s, v;
    int i;
    printf("Введите радиус фигуры ");
        do
        {
        i=scanf("%f", &r);
        if (i==1 && r>0) 
        {          
        s=4*pi*r*r;  
        printf("Площадь сферы: %.2f\n", s);
        v=4*pi*r*r*r/3;
        printf("Объем шара: %.2f\n", v);
        }
        else
        { 
        printf("Некорректный ввод, попытайтесь ввести данные заново");
        }
        }
        while(i==1);
    getch();
    return 0;
}