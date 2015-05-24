//http://www.codechef.com/MAY15/problems/CHEFRP/

#include <stdio.h>
#include <stdlib.h>

int arr[100002];
int main()
{
    int test,n,ans,i,sum,mini;
    scanf("%d",&test);
    while(test--)
    {
        sum = ans = 0;
        mini = 100000;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",arr+i);
            sum += arr[i];
            if(arr[i] < mini)
                mini = arr[i];
            if(arr[i] < 2)
                ans = -1;
        }

        if(ans==-1)
            printf("-1\n");
        else printf("%d\n",sum-mini+2);
    }
    return 0;
}
