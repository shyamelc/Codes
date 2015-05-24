//This program just give yes or no, its possible or not for m
//spoj MINUS problem

#include <stdio.h>
#include <stdlib.h>

int dp[101][1002];
int arr[102];

int main()
{

    int test,n,i,m;
    scanf("%d",&test);
    while(test--)
    {
        memset(dp,sizeof(dp),0);
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",arr+i);
        dp[0][arr[0]+500] = 1;

        for(i=0;i<n;i++)
        {
            for(j=0;j<1001;j++)
            {
                if(dp[i][j])
                {
                    dp[i+1][ j-arr[i+1]+500 ] = 1;
                    dp[i+1][ j+arr[i+1]+500 ] = 1;
                }
            }
        }

    }
    return 0;
}
