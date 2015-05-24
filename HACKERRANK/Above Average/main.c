//https://www.hackerrank.com/contests/csindia/challenges/above-average
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int test;
    scanf("%d",&test);
    while(test--)
        {
        int n,i;
        long long sum = 0;
        double avg;
        scanf("%d",&n);
        int arr[n];
        for(i=0;i<n;i++)
            {
            scanf("%d",arr+i);
            sum += arr[i];
        }
        avg = sum/(double)n;
        int ans = 0;
        for(i=0;i<n;i++)
            if(arr[i] > avg)
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
