#include <stdio.h>  
#include <stdlib.h>
/*?????????? ??? ????????? ????????? ???????*/
#include <conio.h>
#define pi 3.1415926535

void task1()
{
    float r, s, v;
    printf("??????? ?????? ??????: ");
    int sc;
    do
    {
    sc=scanf("%f", &r);    
    if (sc==1 && r>0) 
        {      
        s=4*pi*r*r;  /*??????? ? ??????? ??????? ?????*/
        printf("??????? ?????: %.2f\n", s);
        v=4*pi*r*r*r/3; /*??????? ? ??????? ????? ????*/
        printf("????? ????: %.2f\n", v);
        break;
        }
    else
        { 
        printf("???????????? ????, ??????????? ?????? ?????? ??????");
        }
    }
    while(sc==1);    
}

void task2()
{
    int k,sc;
    printf("??????? ????? k ");
    do
    {
    sc=scanf("%d", &k); 
    if(sc==1)
        {
        if(k%2 == 0)    /*?????????? ???????? ? ??????? ??????? ? ???????? ?? 2*/
            printf("??????\n");
        else
            printf("????????\n");
        break;
        }
    else
        {
        printf("???????????? ????, ??????????? ?????? ?????? ??????");    
        }
    }
    while(sc==1);
}

void task3()
{
    float a, b, c;
    int i=0,sc;
    printf("??????? ????? a, b ? ?: ");
    do
    {
    sc=scanf("%f %f %f", &a, &b, &c); 
    if (sc==3)
        {
        if(a*b==1)  /*????????????? ????????? ????????? ?????????? ? ??????? ?????????? ?????????????? ???*/
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
        printf("?????????? ??????? ???????? ???: %d",i);
        break;
        }
    else
        { 
        printf("???????????? ????, ??????????? ?????? ?????? ??????");
        }
    }
    while(sc==3);
}

void task4()
{
    char time[10];
    printf("??????? ????? ????: ");
    scanf("%s", time);
    switch(time[0])
    {
    case '?':
    printf("??? ???? ???? ??????? ?? ????, ???? ? ???????");
    break;
    case '?':
    printf("??? ???? ???? ??????? ?? ????????, ??????? ? ??????");
    break;
    case '?':
    printf("??? ???? ???? ??????? ?? ???????, ?????? ? ???????");
    break;
    case '?':
    printf("??? ???? ???? ??????? ?? ?????, ?????? ? ???");
    break;
    default:
    printf("?? ????? ??? ?? ?? ??, ??????? ???? ???? ???????? ?????????: ");
    }
        /* ??????? 2
        if(time[0]=='?')    //? ??????????? ?? ??????? ???????? ??????? ?????????? ????? ???? ? ??????? ??????
        {   
        printf("??? ???? ???? ??????? ?? ????, ???? ? ???????");
            if(time[0]=='?')
                printf("??? ???? ???? ??????? ?? ????????, ??????? ? ??????");
                if(time[0] =='?')
                    printf("??? ???? ???? ??????? ?? ???????, ?????? ? ???????");
                        if(time[0] =='?')
                        printf("??? ???? ???? ??????? ?? ?????, ?????? ? ???");
        }
        else     
        printf("?? ????? ??? ?? ?? ??, ??????? ???? ???? ???????? ?????????: ");*/
}
int main()
{ 
    system("chcp 1251 > nul");  
    /*?????? ????????? ??????????? 
    ???? ??? ??????????? ????? ? ??????*/
    int num=0;
    while(num!=-1)
    {
    printf("??????? ????? ??????? ?? 1 ?? 4:");
    scanf("%d",&num);  /*????????? ????? ??????? ??? ????????? switch*/
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
        default: printf("??? ?????? ???????");
        break;
        }
    }
    getch();
    return 0;
}