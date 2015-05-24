//http://www.codechef.com/MAY15/problems/SETDIFF

#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

long long powerof2[100005],i,ans;
int arr[100005]={0};

int func(void* a,void* b)
{
    return ( *( (int*)a ) - *( (int*)b ) );
}

int main()
{
    powerof2[0] = 1;
    for(i=1;i<=100001;i++)
    {
        powerof2[i] = (powerof2[i-1] << 1)%MOD;
    }

    int test,n,j;
    scanf("%d",&test);
    while(test--)
    {
        ans = 0;
        scanf("%d",&n);
        for(j=1;j<=n;j++)
            scanf("%d",&arr[j]);
        qsort(arr,n+1,sizeof(int),func);
        for(j=1;j<=n;j++)
        {
            ans = (ans + ((powerof2[j-1]-powerof2[n-j])*arr[j])%MOD )%MOD;
        }

        printf("%lld\n",ans);
    }
    return 0;
}
