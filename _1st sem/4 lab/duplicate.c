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
        while (temp=getchar()!='\n')
        if(scn!=1 || num<=0 || temp>'9' || temp<'0')
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
    printf("Enter size of two-dimensional array: ");
    size=inputPosInt();
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

    int mainsum=0;
    for(int i=0;i<size;i++)
        mainsum+=arr[i][i];

    int secsum=0,k=0;
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
            printf("This is NOT magic squire\n");
            break;
        }
    }

    if(columflag==0 && rowflag==0 && columsum[0]==rowsum[0] && mainsum==columsum[0] && mainsum==secsum)
    {
        printf("This IS magic squire\n");
    }
}

// Найти в матрице первую строку, все элементы которой положительны, 
// и сумму этих элементов. Уменьшить все элементы матрицы на эту сумму.

void task_2()
{
    
}

//В квадратной матрице размером NxN найти сумму элементов в 1-ой области(верхняя центральная)

void task_3()
{
    
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