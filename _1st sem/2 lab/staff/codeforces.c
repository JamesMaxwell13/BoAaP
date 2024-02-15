#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int emerald(int a, int b) {
    static int sum;

    sum++;
    if (a <= 1 && b <= 1) {
        sum--;
        return sum;
    }
    if (a > 0 && b > 0)
    {
        if (b >= 1 && a >= b)
        {
            a = a - 2;
            b--;
            return emerald(a, b);
        }
        if (a >= 1 && b >= a)
        {
            b = b - 2;
            a--;
            return emerald(a, b);
        }
    }
}

int main()
{
    int a,b,c;
    scanf("%d%d",&a,&b);
    printf("%d",emerald(a,b));
    getch();
    return 0;
}