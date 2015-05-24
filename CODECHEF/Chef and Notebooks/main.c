//http://www.codechef.com/MARCH15/problems/CNOTE
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int test,x,y,k,n,p,r,ans,i;
    scanf("%d",&test);
    while(test--)
    {
        ans = 0;
        scanf("%d %d %d %d",&x,&y,&k,&n);
        x -= y;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&p,&r);
            if(r<=k && p>=x)
            {
                ans=1;
            }
        }
        if(!ans)
            printf("UnluckyChef\n");
        else printf("LuckyChef\n");
    }
    return 0;
}
