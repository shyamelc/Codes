#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test,n,i,sum,ans;
    scanf("%d",&test);
    while(test--)
    {
        ans = 0;
        sum = 0;
        scanf("%d",&n);
        int arr[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",arr+i);
            sum += arr[i];
        }

        if(sum < 100)
            ans = 0;
        else if(sum==100)
            ans = 1;
        else if(sum - n -1 <= 100)
            ans = 1;
        else ans = 0;

        if(ans)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
