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
    /*printf("Enter size of matrix n@m ");
    scanf("%d%d", &n, &m);
    a=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    {
        a[i]=(int*)malloc(m*sizeof(int));
    }*/
    //for(int l=0,l<n-1,l++)
    for(int l=0;l<2;l++)
    {
        //for(int k=0,k<m-1,k++)
        for(int k=0;k<2;k++)
        {
            a[l][k]=rand()%10;
            printf("%d ",a[l][k]);
        }
        printf("\n");
    }
    summin(a);
    printf("%d",smin);
    getch();
    return 0;
}