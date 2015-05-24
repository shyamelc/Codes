#include <stdio.h>
#include <stdlib.h>

int root(int arr[],int i)
{
    while(arr[i]!=i)
    {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

void qunion(int arr[],int i,int j)
{
                               // printf("union %d %d\n",i,j);
    int p = root(arr,i), q = root(arr,j);
    if(p!=q)
    {
        arr[p] = q;
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,m,i,j,l,r;
        scanf("%d %d",&n,&m);
        int arr[n+1],permut[n+1];
        for(i=1;i<=n;i++)
            arr[i] = i;
        for(i=1;i<=n;i++)
            scanf("%d",&permut[i]);
                                                                                   // printf("hi");
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&l,&r);
            int y = root(arr,l);                    //printf("left rigt %d %d\n",l,r);
            for(j=l+1;j<=r;j++)
            {
                qunion(arr,y,j);
            }
        }

        int answer = 1;
        for(i=1;i<=n;i++)
        {
            if(root(arr,i) != root(arr,permut[i]))
            {
                answer = 0;
                break;
            }
        }

        if(answer)
            printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}
