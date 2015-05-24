//http://www.codechef.com/JAN15/problems/ONEKING

#include <stdio.h>
#include <stdlib.h>

struct kingdom
{
    int l,r;
};

int cmpfunc (const void * a, const void * b)
{
   return ( ((struct kingdom*)a)->r - ((struct kingdom*)b)->r);
}

int main()
{
    int test,n,i,previousBomb,ans;
    scanf("%d",&test);
    while(test--)
    {
        ans = 1;
        scanf("%d",&n);
        struct kingdom arr[n];
        for(i=0;i<n;i++)
            scanf("%d %d",&arr[i].l,&arr[i].r);
        qsort(arr,n,sizeof(struct kingdom),cmpfunc);
        previousBomb = arr[0].r;

        for(i=1;i<n;i++)
        {
            if(arr[i].l <= previousBomb && previousBomb <= arr[i].r)
                continue;
            else
            {
                ans++;
                previousBomb = arr[i].r;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
