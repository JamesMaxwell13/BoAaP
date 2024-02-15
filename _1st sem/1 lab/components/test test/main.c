#include <stdio.h>
#include <stdlib.h>  
/*библиотека для изменения кодировки консоли*/
#include <conio.h>
#define pi 3.1415926535

void task1()
{
    float r, s, v;
    printf("Введите радиус фигуры: ");
    scanf("%f", &r); 
    s=4*pi*r*r;  
    printf("Площадь сферы: %.2f\n", s);
    v=4*pi*r*r*r/3;
    printf("Объем шара: %.2f\n", v);
}

void task2()
{
    int k ;
    printf("Введите число k ");
    scanf("%d",&k);
    if(k%2 == 0)
        printf("Четное\n");
    else
        printf("Нечетное\n");
}

void task3()
{
    float a, b, c;
    int i=0;
    printf("Введите числа a, b и с: ");
    scanf("%f %f %f", &a, &b, &c);
    if(a*b==1)
    {
        i+=1;
    }
    if(b*c==1)
    {
        i+=1;
    }
    if(a*c==1)
    {
        i+=1;
    }
    printf("Количество взаимно обратных пар: %d",i);
}

void task4()
{
    char time[6];
    printf("Введите время года: ");
    scanf("%s", time);
    if(time[0]=='л')
    printf("Эта пора года состоит из июня, июля и августа");
        if(time[0]=='о')
        printf("Эта пора года состоит из сентября, октября и ноября");
            if(time[0] =='з')
            printf("Эта пора года состоит из декабря, января и февраля");
                if(time[0] =='в')
                printf("Эта пора года состоит из марта, апреля и мая");
                else     
                printf("Вы ввели что то не то, введите пору года русскими символами: ");
}
int main()
{ 
    system("chcp 1251 > nul");  
    /*меняем раскладку консольного 
    окна для корректного ввода и вывода*/
    int num;
    printf("Введите номер задания от 1 до 4:");
    scanf("%d",&num);  /*считываем номер задания для оператора switch*/
    switch(num)
        {
        case 1: 
            task1();
        break;  
        case 2:
            task2();
        break;
        case 3:
            task3();
        break;          
        case 4:
            task4();
        break;
        default: printf("Нет такого задания");
        break;
        }
    getch();
    return 0;
}


