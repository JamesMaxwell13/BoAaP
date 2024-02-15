#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
int k;
    printf("Enter number members of array ");
    scanf("%d",&k);
    float *arr; 
    float b=0, z;
    arr=(float*)malloc(k*sizeof(float));

    for(int i=0;i<k;i++)
    {
        scanf("%f",&z);
        arr[i]=z;
    }

    /*for(int i=0;i<k;i++)
    {
        while(arr[i]>1) 
        {
            arr[i]=arr[i]/10;   нормальзация(a[i]<=1)
        }
        printf("%.2f ",arr[i]);
    }*/

    for(int i=k-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                b=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=b;
            }
        }
    }

    for(int i=0;i<k;i++)
    printf("%.2f ",arr[i]);

    getch();
    return 0;
}