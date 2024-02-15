#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int inputNum(int *num)
{
	int size;
	printf("Enter amount of numbers: ");
	size=inputPosInt();
	for(int i=0;i<size;i++)
		num[i]=inputInt();
	return size;
}

int main(int argc,char *argv[])
{
	if(!argv[1])
		printf("You didn't enter the name of file, run the program again");
	else
	{
		int *num;
		int size;
		size=inputNum(num);
		int *print;
		print=(int*)malloc(size*sizeof(int));

		FILE *f;
		char *name=argv[1];
		f=fopen(name,"w+b");

			fwrite(num,sizeof(int),size,f);
			fseek(f,0,SEEK_SET);
			fread(print,sizeof(int),size,f);

		fclose(f);
		
		for(int i=0;i<size;i++)
			printf("%d\n",print[i]);
	}
	getchar();
	return 0;
}