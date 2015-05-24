#include <stdio.h>
#include <stdlib.h>
#define MAXI 100002
long long a[MAXI],b[MAXI];
int main()
{
    long long test,n,k,i,ans,temp,t;
    scanf("%lld",&test);
    while(test--)
    {
        ans=0;
        scanf("%lld %lld",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        for(i=0;i<n;i++)
            scanf("%d",b+i);
        for(i=0;i<n;i++)
        {
            temp = k/a[i];
            t = temp*b[i];
            if(t > ans)
                ans = t;
        }

        printf("%lld\n",ans);
    }
    return 0;
}
