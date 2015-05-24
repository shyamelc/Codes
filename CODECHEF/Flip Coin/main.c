//http://www.codechef.com/problems/FLIPCOIN/
#include<stdio.h>

#define MAX 3000000

short lazy[MAX] = {0};
int heads[MAX] = {0};

int query(int node,int i,int j,int p,int q)
{
    int left = 2*node + 1;
    if(lazy[node])
    {
        heads[node] = j-i+1-heads[node];
        lazy[left] = !lazy[left];
        lazy[left+1] = !lazy[left+1];
        lazy[node] = 0;
    }

    if(j<p || i>q)
        return 0;
    if(i>=p && j<=q)
        return heads[node];
    int mid = (i+j)/2;

    return query(left,i,mid,p,q) + query(left+1,mid+1,j,p,q);
}

void update(int node,int i,int j,int p,int q)
{
    int left = 2*node + 1;
    if(lazy[node])
    {
        heads[node] = j-i+1-heads[node];
        lazy[left] = !lazy[left];
        lazy[left+1] = !lazy[left+1];
        lazy[node] = 0;
    }

    if(j<p || i>q)
        return;
    if(i>=p && j<=q)
    {
        heads[node] = j-i+1-heads[node];
        lazy[left] = !lazy[left];
        lazy[left+1] = !lazy[left+1];
        return;
    }

    int mid = (i+j)/2;
    update(left,i,mid,p,q);
    update(left+1,mid+1,j,p,q);
    heads[node] = heads[left] + heads[left+1];
}

int main()
{
    int n,q,i,op,a,b;
    scanf("%d %d",&n,&q);
    for(i=0;i<q;i++)
    {
        scanf("%d %d %d",&op,&a,&b);
        if(op)
            printf("%d\n",query(0,0,n-1,a,b));
        else
            update(0,0,n-1,a,b);
    }
    return 0;
}
