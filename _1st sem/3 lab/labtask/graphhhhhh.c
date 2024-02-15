#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <math.h>
#define pi 3.1415926535

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

double rounding(double x)
{
	int comp;
	double y;
	comp=x*100;
	if(comp%10 >= 5)
	{
		comp/=10;
		y=(double)comp/10+0.1;
	}
	else
	{
		comp/=10;
		y=(double)comp/10;
	}
	return y;
}

int fact(int x)
{
	int y=1;
	for(int i=1; i<=x; i++)
	y*=i;
	return y;
}

double module(double x)
{
	double y=x;
	if(x<0)
	{
	y*=-1;
	return y;
	}
	else
	return y;
}

double degree(double x,int n)
{
	double y=1;
	for(int i=1;i<=n;i++)
	y*=x;
	return y;
}

double cosinus(double x)
{
	int n=7;
	double y=0,member;
	while(x>2*pi)
	{
		x=x-2*pi;
	}
	while(x>pi)
	{
		x=2*pi-x;
	}
	for(int i=0; i<=n; i++)
	{
		member=1;
		member*=degree(-1,i)*degree(x,2*i)/(double)fact(2*i);
		y+=member;
	}
	return y;
}

double func(double x)
{
	double y;
	y=module(x)*cosinus(x)/5;
	return y;
}

int main()
{
	int length,height;
	printf("Enter size of window in integer numbers([length][height]-symbols)\n");
	printf("Step will be 0.1\nDue to the function is even< there will be no negative values of x\n");
	printf("Enter length ");
	length=pos_int();
	printf("Enter height ");
	height=pos_int();

	char console[length][height*2];
	for(int x=0;x<length;x++)
	{
		for(int y=0;y<height*2;y++)
        	console[x][y]=' ';
		console[x][height]='-'; 
	}

	for(int x=0;x<length;x++)
	{
		int y=rounding(func((double)x/10));
		//printf("%d ",y);
		console[x][y-height]='*';
	}

	rewind(stdin);
	for(int y=0;y<height*2;y++)
	{
		printf ("%2.d ", (height-y));
		for(int x=0;x<length;x++)
			printf("%c",console[x][y]);
		printf("\n");
	}

	getch();
	return 0;
}
