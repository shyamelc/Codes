#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
struct counters
{
    int count,in;
};
int compares(const void * a, const void * b)
{
    struct counters* x = (struct counters*) a, y = (struct counters*) b;
    return (x->count - y->count);
}

int binSearch(int *arr,int i,int j, int tofind)
{
    if(j < i)
        return i;
    if(j==i)
        return i;
    int mid = (i+j)/2;
    if(arr[mid]==tofind)
        return mid;

    if(tofind < arr[mid])
        return binSearch(arr,i,mid-1,tofind);
    else return binSearch(arr,mid+1,j,tofind);
}

int main()
{
    int test;
    scanf("%d",&test);

    while(test--)
    {
        int n,m,i,j;
        scanf("%d %d",&n,&m);

        int mouse[n+1], holes[m+1], filled[m+1];

        for(i=0;i<n;i++)
            scanf("%d",mouse+i);
        for(i=0;i<m;i++)
        {
            scanf("%d",holes+i);
            filled[i] = 0;
        }

        qsort(mouse,n,4,compare);
        qsort(holes,m,4,compare);

        struct counters values[n];
        for(i=0;i<n;i++)
        {
            values[i].in = i;
            values[i].count = abs(mouse[i]-holes[i]);
        }

        qsort(values,n,sizeof(struct counters),compares);
        ans = values[n-1];

        for(i=n-m, j=n-m;i<n;i++)
            if()
        printf("%lld\n",ans);
    }
    return 0;
}
