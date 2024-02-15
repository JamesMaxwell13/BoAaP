#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

                                    /*int input()
                                    {
                                        int res=0;
                                        int chs=0;
                                        do 
                                        {
                                            res=scanf("%d",&chs);
                                            while(getchar() != '\n')
                                            if(!res || chs<0)
                                                printf("Wrong input\n");
                                        }
                                        while(chs<0 || res!=1);
                                        return chs;
                                    }*/

int pos_int()
{
    int scn=0;
    int num=0;
    do 
    {
        scn=scanf("%d",&num);
        if(scn!=1 || num<0)
            printf("Wrong input\n");
    }
    while(num<0 || scn!=1);
    return num;
}

int main()
{
    int a,b,n=0;
    printf("Enter number A: ");
    a=pos_int();
    system("cls");
    printf("Enter number B: ");
    b=pos_int();
        while(a>=b)
        {
            a-=b;
            n++;
        }
    printf("Number of segments B which can fit in segment %d",n);
    getch();
    return 0;
}