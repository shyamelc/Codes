#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int arr[100000]={0},oi;

void recur(int a,int b,int n,int current,int stonevalue)
{
    if(current==n)
    {
        arr[oi++] = stonevalue;
        return;
    }

    recur(a,b,n,current+1,stonevalue+a);
    recur(a,b,n,current+1,stonevalue+b);
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        oi = 0;
        int n,a,b,i;
        scanf("%d %d %d",&n,&a,&b);
        recur(a,b,n,1,0);
        qsort(arr,oi,4,cmpfunc);
        printf("%d ",arr[0]);
        for(i=1;i<oi;i++)
            if(arr[i]!=arr[i-1])
                printf("%d ",arr[i]);
        printf("\n");
    }
    return 0;
}
