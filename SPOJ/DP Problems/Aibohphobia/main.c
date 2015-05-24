//http://www.spoj.com/problems/AIBOHP/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 6103

char inp[LEN];
int dp[LEN][LEN];

int mini(int x,int y)
{
    if(x < y)
        return x;
    return y;
}

int recur(int a,int b)
{
    if(a>b)
        return 0;
    if(dp[a][b]!=-1)
        return dp[a][b];
    if(a==b)
        return dp[a][b] = 0;
    if(inp[a]==inp[b])
        return dp[a][b] = recur(a+1,b-1);
    return dp[a][b] = 1 + mini(recur(a,b-1),recur(a+1,b));
}

int main()
{
    int test,i,j;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",inp);
        int l = strlen(inp);
        for(i=0;i<=l;i++)
        {
            for(j=0;j<=l;j++)
            {
                dp[i][j] = -1;
                if(i==j)
                    dp[i][j] = 0;
            }
        }
        printf("%d\n",recur(0,l-1));
    }
    return 0;
}
