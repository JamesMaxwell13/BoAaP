#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    system("chcp 1251");
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
    getch();
    return 0;
}