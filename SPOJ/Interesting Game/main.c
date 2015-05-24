//http://www.spoj.com/problems/KOFEGAME/
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int x,y,den=6,gd;
        scanf("%d %d",&x,&y);
        int max = x > y ? x:y;
        max = 6 - max + 1;
        gd = gcd(max,den);

        max /= gd;      den /= gd;

        printf("%d/%d\n",max,den);
    }
    return 0;
}
