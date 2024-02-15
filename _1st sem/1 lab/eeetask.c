#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i=0,j=0;
int s=0,smin=-1;

void summin(int a[2][2])
{
    s=s+a[i][j];
    printf("%d ",a[i][j]);
    if(i==2 && j==2)
    {
        printf("\n");
        if(s<smin || smin==-1)
            smin=s;
    }
    else
    {
        if(i<2)
        {
            i++;
            summin(a);
            i--;
        }
        if(j<2)
        {
            j++;
            summin(a);
            j--;
        }
    }
    s=s-a[i][j];
}

int main()
{
    srand(time(NULL));
    int a[2][2];
    for(int l=0;l<=2;l++)
    {
        for(int k=0;k<=2;k++)
        {
            a[l][k]=rand()%10;
        }
    }
    for(int l=0;l<=2;l++)
    {
        for(int k=0;k<=2;k++)
        {
            printf("%d ",a[l][k]);
        }
        printf("\n");
    }
    printf("\n%d\n", a[2][2]);
    printf("\n%d\n\n", a[0][0]);
    summin(a);
    printf("%d",smin);
    getch();
    return 0;
}