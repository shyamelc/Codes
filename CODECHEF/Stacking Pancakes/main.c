#include <stdio.h>
#include <stdlib.h>
#define mod 1000000007

long long catalan[1001]={0};
int main()
{
    int i,test,n;
    catalan[0] = catalan[1] = 1;
    for(i=2;i<=1000;i++)
        catalan[i] = ((4*i-2)*catalan[i-1]/(i+1))%mod;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        printf("%lld\n",catalan[n]);
    }
    return 0;
}
