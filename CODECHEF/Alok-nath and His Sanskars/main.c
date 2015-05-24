#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long long n,k,i,ans=1;
        scanf("%lld %lld",&n,&k);
        long long arr[n],sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",arr+i);
            sum += arr[i];
        }

        if(sum%k != 0)
        {
            ans = 0;
            printf("no\n");
        }
        else
        {
            long long each = sum/k;
            for(i=0;i<n;i++)
            {
                if(arr[i] > each)
                {
                    ans = 0;
                    printf("no\n");
                    break;
                }
            }

            if(ans)
                printf("yes\n");
        }
    }
    return 0;
}
