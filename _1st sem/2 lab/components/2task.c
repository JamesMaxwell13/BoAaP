#include <stdio.h>
#include <conio.h>

/*int money(int p)
{
    if(p==0)
    return 1;
    if(p<0)
    return 0;
    return money(p-50)+money(p-20)+money(p-5)+money(p-2);
}*/

int main()
{
    int num;
    for(int i; i<=100;i+=50)
    num++;

    
    printf("Number of ways to compose 1 ruble %d\n",num);
    getch();
    return 0;
}