#include <stdio.h>
#include <stdlib.h>  
/*���������� ��� ��������� ��������� �������*/
#include <conio.h>
#define pi 3.1415926535

void task1()
{
    float r, s, v;
    printf("������� ������ ������: ");
    scanf("%f", &r); 
    s=4*pi*r*r;  
    printf("������� �����: %.2f\n", s);
    v=4*pi*r*r*r/3;
    printf("����� ����: %.2f\n", v);
}

void task2()
{
    int k ;
    printf("������� ����� k ");
    scanf("%d",&k);
    if(k%2 == 0)
        printf("������\n");
    else
        printf("��������\n");
}

void task3()
{
    float a, b, c;
    int i=0;
    printf("������� ����� a, b � �: ");
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
    printf("���������� ������� �������� ���: %d",i);
}

void task4()
{
    char time[6];
    printf("������� ����� ����: ");
    scanf("%s", time);
    if(time[0]=='�')
    printf("��� ���� ���� ������� �� ����, ���� � �������");
        if(time[0]=='�')
        printf("��� ���� ���� ������� �� ��������, ������� � ������");
            if(time[0] =='�')
            printf("��� ���� ���� ������� �� �������, ������ � �������");
                if(time[0] =='�')
                printf("��� ���� ���� ������� �� �����, ������ � ���");
                else     
                printf("�� ����� ��� �� �� ��, ������� ���� ���� �������� ���������: ");
}
int main()
{ 
    system("chcp 1251 > nul");  
    /*������ ��������� ����������� 
    ���� ��� ����������� ����� � ������*/
    int num;
    printf("������� ����� ������� �� 1 �� 4:");
    scanf("%d",&num);  /*��������� ����� ������� ��� ��������� switch*/
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
        default: printf("��� ������ �������");
        break;
        }
    getch();
    return 0;
}


