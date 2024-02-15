#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

double inputDouble()
{
	int scn=0;
    double num=0;
	char temp;
    do
    {
		rewind(stdin);
        scn=scanf("%lf",&num);
		while (temp=getchar() != '\n')
		{
			if(scn!=1 || ((temp>'9' || temp<'0') && temp!='.'))
			{
				printf("Wrong input\n");
				scn=0;
				break;
			}
		}
	}
    while(scn!=1);
    return num;
}

int inputPosInt()
{
	int scn=0;
    int num=0;
	char temp;
    do
    {
		rewind(stdin);
        scn=scanf("%d",&num);

		if(scn!=1 || num<=0)
		{
            printf("Wrong input\n");
			scn=0;
			continue;
		}

        while (temp=getchar()!='\n')
        if(temp>'9' || temp<'0')
		{
            printf("Wrong input\n");
			scn=0;
			break;
		}
    }
    while(num<=0 || scn!=1);
    return num;
}

int inputInt()
{
	int scn=0;
    int num=0;
	char temp;
    do
    {
		rewind(stdin);
        scn=scanf("%d",&num);
        while (temp=getchar()!='\n')
        if(scn!=1 || temp>'9' || temp<'0')
		{
            printf("Wrong input");
			scn=0;
			break;
		}
    }
    while(scn!=1);
    return num;
}

void fillMatrix(int **arr,int size1,int size2)
{
    int choose=0;
    srand(time(NULL));
    while(1)
    {
            printf("Choose way of array filling(1-for user input, 2-for random filling): ");
            choose = inputPosInt();
                if (choose == 1) {
                    for(int i=0;i<size1;i++)
                    {
                        printf("Enter %d row of array: ",i+1);
                        for(int j=0;j<size2;j++)
                        {
                            arr[i][j]=inputInt();
                        }
                    }
                    break;
                }

                    if (choose == 2)
                    {
                        for(int i=0;i<size1;i++)
                        {
                            for(int j=0;j<size2;j++)
                            {
                                arr[i][j]=rand()%201-100;
                                printf("%5d",arr[i][j]);
                            }
                            printf("\n");
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

// Заполнить одномерный массив чётными натуральными числами 
// до 99. Удалить все числа, не принадлежащие отрезку [a;b].

void task_1()
{
	int size=99;
	int *arr;
	arr=(int*)malloc(size*sizeof(int));

    //filling array
	for(int i=0;i<size;i++)
	{
        arr[i]=i+1;
        printf("%d ",arr[i]);
    }
    printf("\n");

	int a,b;
	printf("Enter the lower limit a of the gap [a,b]: ");
	a=inputPosInt();
	printf("Enter the higher limit b of the gap [a,b]: ");
	b=inputPosInt();
	
    //realloc array
	for(int i=0;i<=b-a;i++)
		arr[i]=arr[i+a-1];
	arr=(int*)realloc(arr,(b-a+1)*sizeof(int));	

    //printing array
	for(int i=0;i<=b-a;i++)
		printf("%d ",arr[i]);	
    free(arr);
}

// Двумерный массив заполнить натуральными числами, следующими по 
// порядку. Количество чисел в строке может быть различным, последнее число - 0.

void task_2()
{
    int size;   //количество строк
    int **arr;  

    //make array with $size rows
    printf("Enter the number of rows: ");
	size=inputPosInt(); //количество строк

    //make array
    int rowsize = 1;
    arr=(int**)malloc(size*sizeof(int*));
    for(int i=0;i<size;i++)
        arr[i]=(int*)malloc(rowsize*sizeof(int)); //изначально в каждой строке по 1 элементу, т.е. столбец один
    printf("\n");

    for(int i=0;i<size;i++)
    {
        int j=0;
        rowsize = 1;
        printf("Enter %d row of array: \n",i+1);
        while(1)
        {
            
            arr[i][j]=inputInt();
            if(arr[i][j]==0)
            {
                break;  //если элемент=0 то переходим на след строку
            }
            else
            {
                arr[i]=(int*)realloc(arr[i],(++rowsize)*sizeof(int));            
            } 
            j++;   
        }
        //rowsize-количество элементов в i-той строке
    }
    printf("\n");
    for(int i=0;i<size;i++)
    {
        int j=0;
        do
        {
            printf("%d   ",arr[i][j]);   //выводим i-тую строку
        } 
        while(arr[i][j++]!=0);
        printf("\n"); 
    }
}

// Найти минимальное число под главной диагональю квадратного массива.

void task_3()
{
    int size1,size2;
    int **arr;

    printf("Enter the height of square matrix: ");
	size1=inputPosInt();

    printf("Enter the width of square matrix: ");
	size2=inputPosInt();

    //making and filling array
    arr=(int**)malloc(size1*sizeof(int*));
    for(int i=0;i<size1;i++)
        arr[i]=(int*)malloc(size2*sizeof(int));
    fillMatrix(arr,size1,size2);
    
    int min=arr[1][0];
    
    int sizediag;
    if(size1>size2)
        sizediag=size2;
    else
        sizediag=size1;

    int k;

    for(int i=1;i<size1;i++)
    {
        if(i>=sizediag)
            k=size2;
        else
            k=i;

        for(int j=0;j<k;j++)
        {
            if(min>arr[i][j])
            min=arr[i][j];
        }
    }
    printf("The minimal number under the main diagonal of matrix is: %d",min);
    free(arr);
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
            printf("\nFill a one-dimensional array with even natural numbers up to 99. Delete\n\
all numbers that do not belong to the segment [a;b].\n\n");
            task_1();
            break;
        }
        case 2:
        {
            printf("\nFill a two-dimensional array with natural numbers, following in order.\n\
The number of numbers in a line can be different, the last number is 0.\n\n");
            task_2();
            break;
        }
        case 3:
        {
            printf("\nFind the minimum number under the main diagonal of a square array.\n\n");
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
