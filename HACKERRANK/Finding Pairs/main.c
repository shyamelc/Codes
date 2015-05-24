//https://www.hackerrank.com/contests/da-iict-intra-college-programming-contest-05/challenges/finding-pairs

#include <stdio.h>
#include <stdlib.h>

char input[100005];
int arr[300]={0};

int main()
{
    int i;
    long long ans = 0;
    scanf("%s",input);
    for(i=0; input[i]!='\0';i++)
        arr[input[i]]++;
    for(i=0;i<300;i++)
    {
        ans += (arr[i]*arr[i]);
    }

    printf("%lld\n",ans);
    return 0;
}
