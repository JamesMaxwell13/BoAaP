#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
            printf("Wrong input\n");
			scn=0;
			break;
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

int max_i(int **arr,int i)
{
	int j=0;
	int max=arr[i][j];
	while(arr[i][j]!=0)
	{
		if(arr[i][j]>max)
			max=arr[i][j];
		j++;
	}
	return max;
}

void task_1()
{
	int size;   //количество строк
    int **arr;  

    //make array with $size rows
    printf("Enter the number of rows: ");
	size=inputInt(); //количество строк

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
            do
			{
            	arr[i][j]=inputInt();
				if(arr[i][j]>0)
					printf("Wrong input\n");
			}
			while(arr[i][j]>0);

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


	//начало алгоса
	size++;
	arr=(int**)realloc(arr,size*sizeof(int*));
	*(arr+size-1)=(int*)malloc(size*sizeof(int));

	for(int j=0;j<size-1;j++)
		arr[size-1][j]=max_i(arr,j);

	arr[size-1][size-1]=0;
	
	//вывод массива
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

int main()
{
    int task=0;
    while(task!=-1)
    {
    printf("Proceed?(enter -1 for exit, 1 to do task): ");
    scanf("%d",&task);
        {
            switch (task)
            {
            case 1:
            {
                task_1();
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


// int max_i(int **arr,int i)
// {
// 	int j=0;
// 	int max=arr[i][j];
// 	while(arr[i][j]!=0)
// 	{
// 		if(arr[i][j]>max)
// 			max=arr[i][j];
// 		j++;
// 	}
// 	return max;
// }

// void func(int **arr,int size)
// {
// 	//начало алгоса
// 	size++;
// 	arr=(int**)realloc(arr,size*sizeof(int*));
// 	*(arr+size-1)=(int*)malloc(size*sizeof(int));
// 	for(int j=0;j<size-1;j++)
// 		arr[size-1][j]=max_i(arr,j);
// 	arr[size-1][size-1]=0;
// }
