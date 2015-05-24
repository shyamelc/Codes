#include <stdio.h>
#include <stdlib.h>

int n;
int id[1005], size[1005], trees[1005], ntrees=0;

int root(int i)
{
    while(i!=id[i])
    {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void unionu(int i,int j)
{
    int x = root(i), y = root(j);
    if(x!=y)
    {
        id[x] = y;
        size[y] += size[x];
    }
}

int main()
{
    int m,i,x,y,j;
    long long answer = 0;
    scanf("%d %d",&n,&m);

    for(i=1;i<=n;i++)
    {
        id[i] = i;
        size[i] = 1;
    }

    while(m--)
    {
        scanf("%d %d",&x,&y);
        unionu(x,y);
    }

    for(i=1;i<=n;i++)
    {
        //printf("size of this is %d %d\n",i,size[i]);
        if(id[i]==i)
           trees[ntrees++] = i;
    }

    for(i=0;i<ntrees;i++)
    {
        for(j=i+1;j<ntrees;j++)
        {
            answer += (size[trees[i]]*size[trees[j]]);
                        //printf("%d %d %d %d\n",trees[i],trees[j],size[trees[i]],size[trees[j]]);
        }
    }
    printf("%lld\n",answer);
    return 0;
}
