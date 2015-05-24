#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
    long arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    long long maxTemp=0;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
    {
        long long temp = arr[i] & arr[j];
        if(temp > maxTemp)
            maxTemp = temp;
    }
    printf("%lld",maxTemp);
    return 0;
}
