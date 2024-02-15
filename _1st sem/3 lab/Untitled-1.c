#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

float real_f()
{
    int scn=0;
    float num=0;
    do
    {
        scn=scanf("%f",&num);
        while (getchar() != '\n');
        if(scn!=1)
            printf("Wrong input\n");
    }
    while(scn!=1);
    return num;
}

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

void init_f(float arr[100],int n)
{
    int choose=0;
    srand(time(NULL));
    while(1)
    {
            printf("Choose way of array filling(1-for user input, 2-for random filling): ");
            choose = pos_int();
                if (choose == 1) {
                    for (int i = 0; i < n; i++) {
                        arr[i] = real_f();
                    }
                    break;
                }

                    if (choose == 2)
                    {

                        for (int i = 0; i < n; i++) {
                            arr[i] = (float) (rand() % 100000)/ 100-100;
                            printf("%.2f ", arr[i]);
                        }
                        break;
                    }

                    else
                    {
                        printf("Wrong input\n");
                        system("cls");
                    }
    }
}


//В одномерном массиве, состоящем из n вещественных элементов, вычислить:
//- максимальный элемент массива;
//- сумму элементов массива, расположенных до последнего положительного элемента.

void task_1()
{
    float arr[100];
    int n;
    printf("Enter the number of array elements: ");
    n=pos_int();
    init_f(arr,n);
    printf("\n");

        //finding max element of array
        float max=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>max)
                max=arr[i];
        }
        printf("Maximum member of array is %.2f\n",max);

            //finding amount of members up to last positive
            int pos=-1;
            float sum=0;
            for(int i=n-1;i>=0;i--) {
                if (arr[i]>0 && pos==-1)
                    pos=i;
                if(pos!=-1)
                    sum+=arr[i];
            }
            if(sum==0 && pos==-1)
                printf("Sorry, there is no such element\n");
            printf("Amount of members up to last positive element: %.2f\n",sum);
}


//В массиве из n элементов после каждого отрицательного элемента добавить его копию

void task_2()
{
    float arr[100];
    int n;
    printf("Enter the number of array elements: ");
    n=pos_int();
    init_f(arr,n);
    printf("\n");

    int i=0;
    float buff;
    while(i<n)
    {
        if(arr[i]<0)
        {
            n++;
            for(int j=n-1;j>i;j--)
            {   
                arr[j]=arr[j-1];
            }      
        i++;
        }
        i++;    
    }
    for(int i=0;i<n;i++)
    {
        printf("%.2f ",arr[i]);
    }
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

//

void task_3()
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
    printf("The third array: \n");

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
}

int main()
{
    int task=0;
    while(task!=-1)
    {
    printf("Choose number of task(enter -1 for exit): ");
    scanf("%d",&task);
    {
        switch (task)
        {
        case 1:
        {
            task_1();
            break;
        }
        case 2:
        {
            task_2();
            break;
        }
        case 3:
        {
            task_3();
            break;
        }
        case -1:
        {
            exit(0);
        }
        default:
        printf("Incorrect input number of task, try again");
        }
        getch();
        system("cls");
    }
    }
    getch();
    return 0;
    }