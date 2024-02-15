#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int n,m,i=0,j=0;
int s=0,smin=-1;

void summin(int a[2][2])
{
    s=s+a[i][j];
    if(i==2 && j==2)
    {
        if(s<smin || smin==-1)
            smin=s;
    }
    else
    {
        if(j<2)
        {
            j++;
            summin(a);
            j--;
        }
        if(i<2)
        {
            i++;
            summin(a);
            i--;
        }
    }
    s=s-a[i][j];
}

int main()
{

    int a[2][2];
   
    for(int l=0;l<3;l++)
    {
        for(int k=0;k<3;k++)
        {
            a[l][k]=rand()%10;
            printf("%d ",a[l][k]);
        }
        printf("\n");
    }
    printf("\n%d\n", a[2][2]);
    summin(a);
    printf("%d",smin);
    getch();
    return 0;
}