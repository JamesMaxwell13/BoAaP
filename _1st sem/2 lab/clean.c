#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void task_1()
{
    
    float price=20;
    for(int i=1;i<2022-1626;i++)
    price*=1.04;
    printf("Price of island is %.2f dolars\n",price);
}

        int money(int p)
        {
            if(p==0)
            return 1;
            if(p<0)
            return 0;
            return money(p-50)+money(p-20)+money(p-5)+money(p-2);
        }

void task_2()
{
    printf("Number of ways to compose 1 ruble %d\n",money(8));
}

    int pos_lf()
        {
        int scn=0;
        double num=0;
        do 
        {
            scn=scanf("%lf",&num);
            while (getchar() != '\n');
            if(scn!=1 || num<=0)
                printf("Wrong input\n");
        }
        while(num<=0 || scn!=1);
        return num;
        }

void task_3()
{
    double a=0,b=0;
    int n=0;
    while(a==0 || b==0)
    {
    printf("Enter number A: ");
    a=pos_lf();
    printf("Enter number B: ");
    b=pos_lf();
    if(a<=b)
    {
        a=0;
        b=0;    
        printf("Wrong input\n");
        getch();
        system("cls");
    }
    }
        while(a>=b)
        {
            a-=b;
            n++;
        }
    printf("Number of segments B which can fit in segment A %d\n",n);
}

int main()
{
    int task=0; 
    while(task!=-1)
    {
    printf("Choose number of task(enter -1 for exit): ");
    scanf("%d",&task);
    {
        switch (task)
        {
        case 1:
        {
            task_1();
            break;
        }
        case 2:
        {
            task_2();
            break;
        }
        case 3:
        {
            task_3();
            break;
        }
        case -1:
        {
            exit(0);
        }
        default:
        printf("Incorrect input number of task, try again");
        }
        getch();
        system("cls");
    }
    }
    getch();
    return 0;
}