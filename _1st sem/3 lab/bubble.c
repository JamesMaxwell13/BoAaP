#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
int main()
{
	int arr[100];
    int n=0;
    srand(time(NULL));
    while(n>=0)
    {
        printf("Enter the number of array elements: ");
        scanf("%d",&n);
        for (int i = 0; i < n; i++) 
        {
            arr[i] = rand() % 100;
            printf("%d  ", arr[i]);
        }

        int add;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    add=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=add;
                }
            }
        }
        // for(int i=0;i<n-1;i++)
        // {
        //     for(int j=0;j<n-i-1;j++)
        //     {
        //         if(arr[j]>arr[j+1])
        //         {
        //             add=arr[j];
        //             arr[j]=arr[j+1];
        //             arr[j+1]=add;
        //         }
        //     }
        // }
        printf("\n");

        for (int i = 0; i < n; i++) 
        {
            printf("%d  ", arr[i]);
        }
    }
    getch();
	return 0;
}
