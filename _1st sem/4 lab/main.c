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
				printf("\aWrong input\n");
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
            printf("Wrong input\n");
			scn=0;
			break;
		}
    }
    while(scn!=1);
    return num;
}

void initMatrix(int arr[100][100],int size1,int size2)
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
                                printf("%4.d",arr[i][j]);
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

// Двумерный массив, содержащий равное число строк и столбцов, 
// называется магическим квадратом, если суммы чисел, записанных в каждой строке, 
// каждом столбце и каждой из двух больших диагоналей, равны одному и тому же числу. 
// Определить, является ли данный массив А из n строк и n столбцов магическим квадратом.

void task_1()
{
    int arr[100][100];
    int size;
    
    do
    {
        printf("Enter size of two-dimensional array: ");
        size=inputPosInt();
        if(size>100)
        printf("Wrong input");
    }
    while (size>100);

    initMatrix(arr,size,size);

    int rowsum[100]={0};
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        rowsum[i]+=arr[i][j];
    }

    int columsum[100]={0};
    for(int j=0;j<size;j++)
    {
        for(int i=0;i<size;i++)
        columsum[j]+=arr[i][j];
    }

    int mainsum=0; //main diagonal
    for(int i=0;i<size;i++)
        mainsum+=arr[i][i];

    int secsum=0,k=0; //secondary diagonal
    for(int i=size-1;i>=0;i--)
    {
        secsum+=arr[i][k];
        k++;
    }

    int rowflag=0;
    for(int i=0;i<size;i++)
    {
        if(rowsum[0]!=rowsum[i])
        {
            rowflag=1;
            printf("This is not magic squire\n");
            break;
        }
    }

    int columflag=0;
    for(int i=0;i<size;i++)
    {
        if(rowflag==1)
        break;

        if(columsum[0]!=columsum[i])
        {
            columflag=1;
            
            printf("This is NOT magic square\n");
            break;
        }
    }

    if(columflag==0 && rowflag==0 && columsum[0]==rowsum[0] && mainsum==columsum[0] && mainsum==secsum)
    {
        printf("This IS magic square\n");
    }
}

// Найти в матрице первую строку, все элементы которой положительны, 
// и сумму этих элементов. Уменьшить все элементы матрицы на эту сумму.

void task_2()
{
    int arr[100][100];
    int size1,size2;
    
    do
    {
        printf("Enter height of matrix: ");
        size1=inputPosInt();
        if(size1>100)
        printf("Wrong input");
    } 
    while (size1>100);
    
    do
    {
        printf("Enter width of matrix: ");
        size2=inputPosInt();
        if(size2>100)
        printf("Wrong input");
    } 
    while (size2>100);
    
    initMatrix(arr,size1,size2);

    int sum=0;
    int positive=0;
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
        {
            if(arr[i][j]>=0)
            positive++;
            else
            continue;
        }

        if(positive==size2)
        {
            printf("The number of row with all positive elements is %d\n",i+1);
            for(int j=0;j<size2;j++)
            sum+=arr[i][j];
            break;
        }
        positive=0;
    }

    if(positive==0)
    printf("There is NOT row with all positive elements\n");
    else
    {
        for(int i=0;i<size1;i++)
        {
            for(int j=0;j<size2;j++)
            {
                arr[i][j]-=sum;
                printf("%4.d", arr[i][j]);
            }
            printf("\n");
        }
    }
}

//В квадратной матрице размером NxN найти сумму элементов в 1-ой области(верхняя центральная)

void task_3()
{
    int arr[100][100];
    int size;
    
    do
    {
        printf("Enter size of two-dimensional array: ");
        size=inputPosInt();
        if(size>100)
        printf("Wrong input\n");
    } 
    while (size>100);
    
    initMatrix(arr,size,size);

    int sum=0;
    int center;
    if(size%2==1)
        center=size/2+1;
    else
        center=size/2;
    
    for(int i=0;i<=center;i++)
    {
        for(int j=i;j<size-i;j++)
        {
            sum+=arr[i][j];
        }
    }
    printf("The sum of elements in the 1st region: %d",sum);
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
            printf("\nA two-dimensional array containing an equal number of rows and columns is\n\
called a magic square if the sums of the numbers written in each row, each column,\n\
and each of the two large diagonals are equal to the same number. Determine if the\n\
given array A of n rows and n columns is a magic square.\n\n");
            task_1();
            break;
        }
        case 2:
        {
            printf("\nFind the first row in the matrix, all elements of which are positive, and\n\
the sum of these elements. Decrease all elements of the matrix by this amount.\n\n");
            task_2();
            break;
        }
        case 3:
        {
            printf("\nIn a square matrix of size NxN, find the sum of elements in the 1st region\n\n");
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


// void init_f(float arr[100],int n)
// {
//     int choose=0;
//     srand(time(NULL));
//     while(1)
//     {
//             printf("Choose way of array filling(1-for user input, 2-for random filling): ");
//             choose = pos_int();
//                 if (choose == 1) {
//                     for (int i = 0; i < n; i++) {
//                         arr[i] = real_f();
//                     }
//                     break;
//                 }

//                     if (choose == 2)
//                     {

//                         for (int i = 0; i < n; i++) {
//                             arr[i] = (float) (rand() % 100000)/ 100-100;
//                             printf("%.2f ", arr[i]);
//                         }
//                         break;
//                     }

//                     else
//                     {
//                         printf("Wrong input\n");
//                         system("cls");
//                     }
//     }
// }

// void init_int(int arr[100],int n,int diff)
// {
//     int choose=0;
//     srand(time(NULL));
//     while(1)
//     {
//             printf("Choose way of array filling(1-for user input, 2-for random filling): ");
//             choose = pos_int();
//                 if (choose == 1) {
//                     for (int i = 0; i < n; i++) {
//                         arr[i] = pos_int();
//                     }
// 					for(int i=0;i<n;i++)
// 					{
// 						if(diff<0)
// 						arr[i]*=diff;
// 					}
//                     int add;
//                     for(int i=0; i<n ;i++)
//                     {
//                         for(int j=0;j<n-i-1;j++)
//                         {
//                             if(arr[j]>arr[j+1])
//                             {
//                                 add=arr[j];
//                                 arr[j]=arr[j+1];                                    
//                                 arr[j+1]=add;
//                             }
//                         }
//                     }

// 					for(int i=0;i<n;i++)
// 					{
// 						if(diff<0)
// 						arr[i]*=diff;
// 					}

//                     printf("\n");
//                     break;
//                 }

//                     if (choose == 2)
//                     {
//                         arr[0] = rand() % 1000;
//                         printf("%d  ", arr[0]);
//                         int term;
//                         for (int i = 1; i <n; i++) 
//                         {
//                             term=diff*rand() % 100;
//                             arr[i]=arr[i-1]+term;
//                             printf("%d  ", arr[i]);
//                         }
//                         printf("\n");
//                         break;
//                     }

//                     else
//                     {
//                         printf("Wrong input\n");
//                         system("cls");
//                     }
//     }
// }



// проверОчка float

// float real_f()
// {
//     int scn=0;
//     float num=0;
//     do
//     {
//         scn=scanf("%f",&num);
//         while (getchar() != '\n');
//         if(scn!=1)
//             printf("Wrong input\n");
//     }
//     while(scn!=1);
//     return num;
// }

// проверОчка int

// int pos_int()
// {
//     int scn=0;
//     int num=0;
//     do
//     {
//         scn=scanf("%d",&num);
//         while (getchar() != '\n');
//         if(scn!=1 || num<=0)
//             printf("Wrong input\n");
//     }
//     while(num<=0 || scn!=1);
//     return num;
// }



