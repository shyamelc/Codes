#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,i,current=1;
        scanf("%d",&n);
        int answer = n;
        int arr[n];
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        qsort(arr,n,4,cmpfunc);
        for(i=1;i<n;i++)
        {
            if(abs(arr[i]-arr[i-1])==1)
                current++;
            else
            {
                                   // printf("%d %dchange\n",current,i);
                if(current < answer)
                    answer = current;
                current = 1;

            }
        }

        if(current==1 && n!=0)
            answer = 1;

        printf("%d\n",answer);
    }
    return 0;
}
