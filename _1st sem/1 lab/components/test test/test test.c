#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define pi 3.1415926535
int main()
{ 
    system("chcp 1251 > nul");  
    char time[6];
    printf("������� ����� ����: ");
    scanf("%s", time);
    switch(time[0])
    {
    case '�':
    printf("��� ���� ���� ������� �� ����, ���� � �������");
    break;
    case '�':
    printf("��� ���� ���� ������� �� ��������, ������� � ������");
    break;
    case '�':
    printf("��� ���� ���� ������� �� �������, ������ � �������");
    break;
    case '�':
    printf("��� ���� ���� ������� �� �����, ������ � ���");
    break;
    defoult:
    printf("�� ����� ��� �� �� ��, ������� ���� ���� �������� ���������: ");
    }
    
    /* if(time[0]=='�')   //� ����������� �� ������� �������� ������� ���������� ����� ���� � ������� ������
    printf("��� ���� ���� ������� �� ����, ���� � �������");
        if(time[0]=='�')
        printf("��� ���� ���� ������� �� ��������, ������� � ������");
            if(time[0] =='�')
            printf("��� ���� ���� ������� �� �������, ������ � �������");
                if(time[0] =='�')
                printf("��� ���� ���� ������� �� �����, ������ � ���");
                else     
                printf("�� ����� ��� �� �� ��, ������� ���� ���� �������� ���������: ");*/
    getch();
    return 0;
}

