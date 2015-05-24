//http://codeforces.com/contest/465/problem/B
#include <stdio.h>
#include <stdlib.h>

int arr[1001], nextOne[1001] = {0};

int main()
{
    int n,i,count = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",arr + i);

    for(i=n-2; i>=0; i--)
    {
        if(arr[i+1])
            nextOne[i] = i+1;
        else nextOne[i] = nextOne[i+1];
    }


    if(nextOne[0])
        count++;

    int first = nextOne[0];
    if(arr[0])
        first = 0;
    for(i=first;i<n;i++)
    {
                                //printf("enter %d %d\n",i,count);
        if(!nextOne[i])
            break;
        if(nextOne[i] - i > 2)
        {
            count++;
            i = nextOne[i]-1;
        }

        count++;
                               // printf("exit %d %d\n",i,count);
    }

    printf("%d\n",count);
    return 0;
}
