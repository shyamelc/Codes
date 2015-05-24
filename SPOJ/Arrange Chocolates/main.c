#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

long long combi(long long n, long long r)
{
    if(n-r > r)
        r = n-r;
    long long ans=1,i;

    for(i=0; i<r; i++)
        ans = (ans * n--);
    for(i=r; i>1; i--)
        ans /= i;

    return ans % MOD;
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long long n1, n2, k, answ;
        scanf("%lld %lld %lld",&n1,&n2,&k);
        answ = combi( (n2+1)*k, n1 ) ;
        printf("%lld\n",answ);
    }
    return 0;
}
