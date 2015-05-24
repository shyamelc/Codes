#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,m,omultiple,emultiple;
        scanf("%d %d",&n,&m);
        n--;

        if(n & 1)
        {
            emultiple = n/2;
            omultiple = n - emultiple;
        }
        else
            omultiple = emultiple = n/2;

        long long answer = 0;

        answer = ( omultiple*(2*m-2) )%MOD;
        long long temp = ( emultiple*(3*m-2))%MOD;

        answer = (answer + temp)%MOD;

        if(n==0)
            answer = m;
        printf("%lld\n",answer);
    }
    return 0;
}
