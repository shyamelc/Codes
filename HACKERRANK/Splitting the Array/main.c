#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    long long sum[n],ans=0;
    scanf("%d",arr);
    sum[0] = arr[0];
    for(i=1;i<n;i++)
    {
        scanf("%d",arr+i);
        sum[i] = sum[i-1] + arr[i];
    }

    for(i=0;i<)
    return 0;
}
