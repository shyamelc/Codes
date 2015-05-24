#include <stdio.h>
#include <stdlib.h>

int findMax(int* arr,int n,int i)
{
    int max = arr[i],maxIndex = i++;
    for(;i<n;i++)
        if(arr[i] > max)
        {
            max = arr[i];
            maxIndex = i;
        }

    return maxIndex;
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,i;
        scanf("%d",&n);
        int arr[n];
        long long sums[n];
        sums[0] = 0;
        scanf("%d",arr);
        printf("0 ");
        for(i=1;i<n;i++)
        {
            scanf("%d",&arr[i]);
            sums[i] = sums[i-1] + arr[i-1];
            printf("%lld ",sums[i]);
        }

        i = 0;
        int lastFlush = -1;
        long long profit = 0;
        while(i < n)
        {
            int maxi = findMax(arr,n,i);
                                    printf("%d %lldhello ",maxi,(maxi-lastFlush)*arr[maxi] - (sums[maxi]-sums[lastFlush+1]));
            profit += (maxi-lastFlush)*arr[maxi] - (sums[maxi]-sums[lastFlush+1]);
            lastFlush = maxi;
            i = maxi + 1;
        }

        printf("%lld\n",profit);
    }
    return 0;
}
