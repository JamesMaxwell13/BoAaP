#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int input_uint()
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


double input_double()
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
//|| (temp>'9' || temp<'0' || temp!='.')

int main()
{
	int number;
	number=input_uint();
	printf("%d",number);
	getch();
	return 0;
}


// int getInt(int* S) {
//     int code = scanf("%i", S);
//     if (code != 1)
//         return code;
//     char temp;
//     while ((temp = getchar()) != '\n') {
//         if ((temp > '9')  (temp < '0'))
//             return -2;
//         continue;
//     }
//     return 1;
// }

// int getFloat(float* S) {
//     int code = scanf("%f", S);
//     if (code != 1)
//         return code;
//     char temp;
//     while ((temp = getchar()) != '\n') {
//         if ((temp > '9')  (temp < '0') || (temp != '.'))
//             return -2;
//         continue;
//     }
//     return 1;
// }