#include <stdio.h>
#include <stdlib.h>

int dp[1005][1005];
char s1[1005],s2[1005];

int maxi(int a,int b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    int k,i,j,x,till;
    scanf("%d",&k);
    while(k)
    {
        scanf("%s %s",s1+1,s2+1);
        memset(dp,0,sizeof(dp));
        for(i=1; s1[i]!='\0'; i++)
        {
            for(j=1; s2[j]!='\0'; j++)
            {
                if(s1[i]!=s2[j])
                    dp[i][j] = maxi(dp[i-1][j] ,dp[i][j-1]);
                else
                {
                    for(x=0;s1[i+x]!='\0' && s2[i+x]!='\0';x++)
                    {
                        if(s1[i+x]!=s2[j+x])
                            break;
                    }

                    if(x >= k)
                        till = x-1;
                    else j += x-1;
                }
            }
        }

        scanf("%d",&k);
    }
    return 0;
}
