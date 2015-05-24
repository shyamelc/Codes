//http://www.codechef.com/APRIL15/problems/CHEFLCM

#include <stdio.h>
#include <stdlib.h>

long long arr[100002];
int main()
{
    long long test,n,i,ans,precounted=-1;
    scanf("%lld",&test);
    while(test--)
    {
        ans = 0;

        scanf("%lld",&n);
        scanf("%lld",&arr[0]);
        for(i=1;i<n;i++)
        {
            scanf("%lld",&arr[i]);
            if(arr[i]!=arr[i-1])
            {
                if(i==1)
                {
                    ans += 2;
                }
                else
                {
                    if(precounted == (i-1))
                        ans++;
                    else ans += 2;
                }
                precounted = i;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
