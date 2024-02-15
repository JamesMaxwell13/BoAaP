#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main() 
{
    system("chcp 1251 > nul");
    int k ;
    printf("Введите k ");
    if(scanf("%d",&k)!=0)
    {
        if(k%2 == 0)
        {
        printf("Четное\n");
        }
        else
        {
        printf("Нечетное\n");
        }
    }
    else
    {
    printf("Некорректный ввод, попытайтесь ввести данные заново");    
    }
    getch();
    return 0;
}