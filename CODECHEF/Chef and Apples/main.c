//http://www.codechef.com/DEC14/problems/CAPPLE

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,i,ans,temp,apples[100002] = {0};
        scanf("%d",&n);
        ans = n;
        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            apples[temp]++;
        }
               /* for(i=0;i<10;i++)
                    printf("%d ",apples[i]);
                printf("\n%d\n",ans);*/
        for(i=0;i<100002;i++)
        {
            if(apples[i])
                ans -= (apples[i]-1);
        }

        printf("%d\n",ans);
    }
    return 0;
}
