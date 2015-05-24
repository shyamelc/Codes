//http://www.codechef.com/DINP1501/problems/CHEFPOW
//U should write in most optimized view point
#include <stdio.h>
#include <math.h>

unsigned long long ans[100000]={0},filled=0;

int main()
{
    unsigned long long n,x,y,i;
    scanf("%llu",&n);
    while(n>=1)
    {
        x = log2(n);
        y = 1<<x;
        ans[filled++] = y;
        n -= y;
    }

    int j = filled-1;
    for( ; j>=0; j--)
        printf("%llu ",ans[j]);
    return 0;
}
