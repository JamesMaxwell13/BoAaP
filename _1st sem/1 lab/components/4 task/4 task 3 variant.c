#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    system("chcp 1251");
    char time[6];
    printf("¬ведите врем€ года: ");
    scanf("%s", time);
    if(time[0]=='л')
        printf("Ёта пора года состоит из июн€, июл€ и августа");
            if(time[0]=='о')
                printf("Ёта пора года состоит из сент€бр€, окт€бр€ и но€бр€");
                if(time[0] =='з')
                    printf("Ёта пора года состоит из декабр€, €нвар€ и феврал€");
                        if(time[0] =='в')
                            printf("Ёта пора года состоит из марта, апрел€ и ма€");
        else 
        printf("¬ы ввели что то не то, введите пору года русскими символами: ");
    getch();
    return 0;
}