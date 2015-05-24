#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

int getMin(int arr[],int m)
{
    int i,temp = INT_MAX;
    for(i=0;i<m;i++)
        if(arr[i] < temp)
            temp = arr[i];
    return temp;
}

int main()
{
    int test,n,m,i,j,firstMin,previougain;
    long long previousMin,temp,ans;
    scanf("%d",&test);
    while(test--)
    {
        previousMin = INT_MAX;
        scanf("%d %d",&n,&m);
        int power[n][m], gain[n][m], dp[n][m];

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&power[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&gain[i][j]);
        for(i=0;i<m;i++)
        {
            dp[0][i] = power[0][i];

            temp = dp[0][i]-gain[0][i];
            if(temp < previousMin)
            {
                previousMin = temp;
                previougain = gain[0][i];
            }

        }


        firstMin = previousMin+gain[0][i];
                        //printf("\n\nfirst min %d\n\n",firstMin);
        for(i=1;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                dp[i][j] = previousMin + power[i][j];
                if(dp[i][j] < 0)
                    dp[i][j] = 0;
            }

            previousMin = INT_MAX;

            for(j=0;j<m;j++)
            {
                temp = dp[i][j] - gain[i][j];
                if(temp < previousMin)
                    previousMin = temp;
            }

        }

        /*for(i=0;i<m;i++)
        {
            printf("\n");
            for(j=0;j<m;j++)
                printf("%d ",dp[i][j]);
        }*/
        n--;
        int mini = getMin(dp[n],m);
        if(mini <= 0)
            printf("%d\n",firstMin);
        else printf("%d\n",mini);

    }
    return 0;
}
