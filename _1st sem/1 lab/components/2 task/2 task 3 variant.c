#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main() 
{
    system("chcp 1251 > nul");
    int k ;
    printf("������� k ");
    if(scanf("%d",&k)!=0)
    {
        if(k%2 == 0)
        {
        printf("������\n");
        }
        else
        {
        printf("��������\n");
        }
    }
    else
    {
    printf("������������ ����, ����������� ������ ������ ������");    
    }
    getch();
    return 0;
}