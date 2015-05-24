//https://www.hackerrank.com/contests/da-iict-intra-college-programming-contest-05/challenges/help-yash

#include <stdio.h>
#include <stdlib.h>

long long ks[102] = {0}, arr[50000];
int main()
{
    int n,k,i;
    long long sum = 0,ans=0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%lld",arr+i);
    ks[0]++;
    for(i=0;i<n;i++)
    {
        sum = (sum + arr[i])%k;
        ks[sum]++;
    }
    for(i=0;i<k;i++)
        ans += ks[i]*(ks[i]-1)/2;
    printf("%lld\n",ans);
    return 0;
}
