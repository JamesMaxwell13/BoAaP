#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// #include <math.h>
#define pi 3.1415926535

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

// double func(double x)
// {
// 	double y;
// 	y=module(x)*cosinus(x)/5;
// 	return y;
// }

int fact(int x)
{
	int y=1;
	for(int i=1; i<=x; i++)
	y*=i;
	return y;
}

// double module(double x)
// {
// 	double y=x;
// 	if(x<0)
// 	{
// 	y*=-1;
// 	return y;
// 	}
// 	else
// 	return y;
// }

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

int main()
{
	double x=0;
	// while(x!=-9999)
	// {	
	//scanf("%lf",&x);
	for(int i=0;i<300;i++)
	printf("%lf  ",cosinus((double)i));
	getch();
	return 0;
}