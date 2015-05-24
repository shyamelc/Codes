//https://www.hackerrank.com/contests/csindia/challenges/mice-v1
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<limits.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n;
        scanf("%d",&n);
        long long mouse[n],holes[n],i,ans = -1;
        for(i=0;i<n;i++)
            scanf("%lld",mouse+i);
        for(i=0;i<n;i++)
            scanf("%lld",holes+i);
        qsort(mouse,n,sizeof(long long),cmpfunc);
        qsort(holes,n,sizeof(long long),cmpfunc);

        for(i=0;i<n;i++)
            {
                long long z =abs(mouse[i]-holes[i]);
               if(z > ans)
                    ans =  z;
            }


        printf("%lld\n",ans);
    }
    return 0;
}
