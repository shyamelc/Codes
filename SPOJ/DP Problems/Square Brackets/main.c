//http://www.spoj.com/problems/SQRBR/

#include <stdio.h>
#include <stdlib.h>

int dp[21][21],ks[40] = {0};

int main()
{
    int test,n,k,i,temp,j;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&k);
        memset(ks,0,sizeof(ks));
        memset(dp,0,sizeof(dp));

        for(i=0;i<k;i++)
        {
            scanf("%d",&temp);
            ks[temp] = 1;
        }

        for( i=1;i<=2*n;i++){

            for(j=0;j<=i;j++){

                if(i==1){

                    if(j==1)dp[i][j]=1;

                    else dp[i][j]=0;

                }else{

                    if(ks[i]){

                        dp[i][j] = ((j==0)?0:dp[i-1][j-1]);

                    }else{

                        dp[i][j] = dp[i-1][j+1] + ((j==0)?0:dp[i-1][j-1]);

                    }

                }

            }

        }
        printf("%d\n",dp[2*n][0]);
    }
    return 0;
}
