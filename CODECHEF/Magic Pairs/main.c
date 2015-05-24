//http://www.codechef.com/problems/ALEXNUMB/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    long long test,n,i,temp;
    long long ans;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        ans = (n*(n-1))/2;
        for(i=0;i<n;i++)
            scanf("%lld",&temp);
        printf("%lld\n",ans);
    }
    return 0;
}
