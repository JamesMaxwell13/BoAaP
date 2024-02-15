#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int pos_int()
{
    int scn=0;
    int num=0;
    do
    {
        scn=scanf("%d",&num);
        while (getchar() != '\n');
        if(scn!=1 || num<=0)
            printf("Wrong input\n");
    }
    while(num<=0 || scn!=1);
    return num;
}

void init_int(int arr[100],int n,int diff)
{
    int choose=0;
    srand(time(NULL));
    while(1)
    {
            printf("Choose way of array filling(1-for user input, 2-for random filling): ");
            choose = pos_int();
                if (choose == 1) {
                    for (int i = 0; i < n; i++) {
                        arr[i] = pos_int();
                    }
					for(int i=0;i<n;i++)
					{
						if(diff<0)
						arr[i]*=diff;
					}
                    int add;
                    for(int i=0; i<n ;i++)
                    {
                        for(int j=0;j<n-i-1;j++)
                        {
                            if(arr[j]>arr[j+1])
                            {
                                add=arr[j];
                                arr[j]=arr[j+1];                                    
                                arr[j+1]=add;
                            }
                        }
                    }

					for(int i=0;i<n;i++)
					{
						if(diff<0)
						arr[i]*=diff;
					}

                    printf("\n");
                    break;
                }

                    if (choose == 2)
                    {
                        arr[0] = rand() % 1000;
                        printf("%d  ", arr[0]);
                        int term;
                        for (int i = 1; i <n; i++) 
                        {
                            term=diff*rand() % 100;
                            arr[i]=arr[i-1]+term;
                            printf("%d  ", arr[i]);
                        }
                        printf("\n");
                        break;
                    }

                    else
                    {
                        printf("Wrong input\n");
                        system("cls");
                    }
    }
}

//Имеется два массива целых чисел: первый заполнен по возрастанию, второй -
//по убыванию. Объединить массивы в третий массив в порядке возрастания.

int main()
{
	int arr1[100],arr2[100],arr3[200];
    int n1, n2, diff;

	diff=1;
    printf("Enter the number of first array elements: ");
    n1=pos_int();
    init_int(arr1,n1,diff);

	diff=-1;
	printf("Enter the number of second array elements: ");
    n2=pos_int();
    init_int(arr2,n2,diff);
    printf("\n");

    int k=0,i=0,j=n2-1;
    while(k<n1+n2)
	{
		if(arr1[i]<=arr2[j])
		{
            if(i<n1)
            {
                arr3[k]=arr1[i];
                k++;
                i++;
            }
            else
            {
                arr3[k]=arr2[j];
                k++;
                j++;
                continue;
            }
		}

		if(arr1[i]>arr2[j])
		{
            if(j>=0)
            {
                arr3[k]=arr2[j];
                k++;
                j--;
            }
            else
            {
            arr3[k]=arr1[i];
            k++;
            i++;
            continue;
            }
		}
	}
    for(int i=0;i<n1+n2;i++)
        printf("%d ",arr3[i]);
	getch();
	return 0;
}