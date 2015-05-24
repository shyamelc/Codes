//http://www.codechef.com/OCT14/problems/CHEFGR
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,m,i,j,maxv = -1,diff=0;
        scanf("%d %d",&n,&m);
        int arr[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",arr+i);
            if(arr[i] > maxv)
                maxv = arr[i];
        }

        for(i=0;i<n;i++)
        {
            diff += (maxv - arr[i]);
        }

        if((m - diff) % n == 0)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
