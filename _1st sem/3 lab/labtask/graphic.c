#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define pi 3.1415926535
#define length 150
#define height 50 

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
	int n=5;
	double y=0,member;
	if(x>pi)
	x=2*pi-x;
	while(x>2*pi)
	x=x-2*pi;
	for(int i=0; i<=n; i++)
	{
		member=1;
		member*=degree(-1,i)*degree(x,2*i)/(double)fact(2*i);
		y+=member;
	}
	return y;
}

	// if(y>1)
	// y=1;
	// if(y<-1)
	// y=-1;

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

double func(double x)
{
	double y;
	y=module(x)*cosinus(x)/5;
	// printf("%lf",cosinus(x));
	return y;
}

int main()
{
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
		printf("%d ",y);
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

// 		double x;
// 		scanf("%lf",&x);
// 	int round;
// 	round=cosinus(x);
// 	printf("%d\n",round);
// 		double ans=cosinus(x);
// 		printf("%lf",ans);



// 	for(int i=0;i<length;i++)
// 	printf("%lf ",cosinus((double)i/10));

// 	char scene[length][width*2];
// 	for(int x=0;x<length;x++)
// 	{ 
//     	for(int y=0;y<width*2;y++)
//         	scene[x][y]=' ';
// 		scene[x][width]='-'; 
//     }

// 	for(int x=0;x<length;x++)
// 	{
//     	int y = rounding(func((double)x/10))*10;
// 		printf("%.1lf ",rounding(func((double)x/10))); 
// 		if(module(y)<width)
//         	scene[x][y]='*'; 
// 	}

// 	printf("\n");
// 	for(int y=width*2-1;y>=0;y--){
//       printf ("%3.1lf ", (double)(y-width)/10);
//       for(int x=0;x<length;x++){
//           printf("%c",scene[x][y]);
//       }
//       printf("\n");
//   }




	// int length,height;
	// printf("Enter size of window in integer numbers([length][height]-symbols)\n");
	// printf("Enter length ");
	// length=pos_int();
	// printf("Enter height ");
	// height=pos_int();
