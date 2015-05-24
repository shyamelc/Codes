//http://www.codechef.com/JULY14/problems/RETPO
#include <stdio.h>
#include <math.h>

int main()
{
    long test;
    scanf("%d",&test);

    while(test--)
    {
        long long x,y;
        scanf("%lld %lld",&x,&y);
        x = abs(x);     y = abs(y);
        int even = 0;
        if((x+y)%2 == 0)
            even = 1;
        long long max = x;
        int shortOnX = 0;
        if(y  > x)
        {
            max = y;
            shortOnX = 1;
        }

        max *= 2;
        if(even)
            printf("%lld\n",max);
        else
        {
            if(shortOnX)
                max--;
            else
                max++;
            printf("%lld\n",max);
        }
    }
    return 0;
}
