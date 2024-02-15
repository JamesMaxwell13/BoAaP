#include <stdio.h>
#include <conio.h>
int main()
{
double a,b;
while ((scanf("%lf%lf",&a,&b)!=2) || b<=0 || a<=0 || a<=b)
{
    printf("Error");
    rewind(stdin);
}
printf("%.2lf %.2lf",a,b);

}