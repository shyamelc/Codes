#include <stdio.h>
#include<math.h>

int s,t;
int dp[1000005] = {0};

int recurse(int x)
{
    if(dp[x])
        return dp[x];
    if(x <= s)
    {
        dp[x] = 1;
       return 1;
    }

    dp[x] = recurse(x/2) + recurse(ceil(x/2.0));
    return dp[x];
}

int main()
{
    scanf("%d %d",&s,&t);
    dp[s] = 1;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",recurse(n));
    }
    return 0;
}
