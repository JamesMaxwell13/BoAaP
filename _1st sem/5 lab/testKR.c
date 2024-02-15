#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

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
                                printf("%4d",arr[i][j]);
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

void task_1()
{
	int size1,size2;
    int **arr;

    printf("Enter the height of matrix: ");
	size1=inputPosInt();

    printf("Enter the width of matrix: ");
	size2=inputPosInt();

    arr=(int**)malloc(size1*sizeof(int*));
    for(int i=0;i<size1;i++)
        arr[i]=(int*)malloc(size2*sizeof(int));
    fillMatrix(arr,size1,size2);

                                                printf("\n");
                                                for(int i=0;i<size1;i++)
                                                {
                                                    for(int j=0;j<size2;j++)
                                                    {
                                                        printf("%4d",arr[i][j]);
                                                    }
                                                    printf("\n");
                                                }
                                                printf("\n");

	int negative=-1;
	int flag=0;
	for(int i=size1-1;i>=0;i--)
	{
        flag=0;
		for(int j=0;j<size2;j++)
		{
			if(arr[i][j]>=0)
			{
				flag=1;
				break;
			}
		}
		
		if(flag==0)
		{
			negative=i;
			size1++;
			arr=(int**)realloc(arr,size1*sizeof(int*));
			arr[size1-1]=(int*)malloc(size2*sizeof(int));

			for(int i=size1-1; i>negative+1; i--)
			{
				for(int j=0;j<size2;j++)
					arr[i][j]=arr[i-1][j];
			}

			for(int j=0;j<size2;j++)
				arr[negative+1][j]=0;

			break;
		}
	}
                                                
                                                for(int i=0;i<size1;i++)
                                                {
                                                    for(int j=0;j<size2;j++)
                                                    {
                                                        printf("%4d",arr[i][j]);
                                                    }
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
