#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
			if((temp>'9' || temp<'0') && temp!='.')
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

int main()
{
	int a;
	a=inputPosInt();
	printf("%d\n",a);
	getch();
	return 0;
}