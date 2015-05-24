//https://www.hackerrank.com/contests/codenite1/challenges/hacking-the-erp
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int test;
    scanf("%d",&test);
    while(test--)
    {
        int arr[10] = {0},total = 0,i=1;
        long n,answer = 0;
        scanf("%d",&n);

        while(total!=10)
        {
            long long x = i*n;
            i++;
                                    //printf("%d ",n);
            answer++;

            while(x!=0)
            {
                int y = x%10;
                x /= 10;
                if(!arr[y])
                {
                    arr[y] = 1;
                    total++;
                }
                //printf("%d ",y);
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}
