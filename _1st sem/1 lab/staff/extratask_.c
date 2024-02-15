#include <stdio.h>  
#include <stdlib.h>
#include <conio.h>
#include <math.h>
void task1()
{
    int a;
    printf("Enter a=");
    scanf("%d",&a);
    a=a>>5;
    printf("%d",a);
}

void task2()
{
    int k;
    printf("Enter number members of array ");
    scanf("%d",&k);
    float *arr; 
    float s=0, z;
    arr=(float*)malloc(k*sizeof(float));
    for(int i=0;i<k;i++)
    {
        scanf("%f",&z);
        arr[i]=z;
        s=s+arr[i];
    }
    printf("%.2f",s/k);
}

void task3()
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
    
    printf("Normalization: ");
     for(int i=0;i<k;i++)
    {
        //printf("%.2f ",arr[i]);
        while(fabsf(arr[i])>1) 
        {
            arr[i]=arr[i]/10;
            printf("%.2f ",arr[i]);
        }
    }
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

    printf("Solution: ");
    for(int i=0;i<k;i++)
    {
        printf("%.2f ",arr[i]);
    }
}

int main()
{
    int n=0;
    while(n!=-1)
    {
    printf("Enter number of extra task ");
    scanf("%d",&n);
    switch(n)
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
    case -1:
    printf("bye bye");
    break;
    default: printf("Error");
    break;
    }
    }
    getch();
    return 0;
}