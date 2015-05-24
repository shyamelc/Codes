#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long long d;
        scanf("%lld",&d);
        long long ans = (sqrt(1+4*d) -1)/2;

        printf("%lld\n",ans);
    }
    return 0;
}
