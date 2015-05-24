//https://www.hackerrank.com/contests/w13/challenges/swaps-and-sum

#include <stdio.h>
#include <stdlib.h>

long long st[600000]={0};
int arr[200002]={0};

void buildST(int node,int l,int r)
{
    int c,m=(l+r)/2;
    if(l > r)
        return;
    if(l==r)
        st[node] = arr[l];
    else
    {
        c = 2*node+1;
        buildST(c,l,m);
        buildST(c+1,m+1,r);

        st[node] = st[c] + st[c+1];
    }
               // printf("check %d %d %d %lld\n",l,r,node,st[node]);
}

long long query(int node, int l, int r,int ql, int qr)
{
    if(qr < ql || r < l)
        return 0;
    if(qr < l || ql > r)
        return 0;
    if(ql <= l && qr >= r)
        return st[node];
    int c = node*2+1, m=(l+r)/2;
    return (query(c,l,m,ql,qr) + query(c+1,m+1,r,ql,qr));
}

void swapp(int a,int b)
{
    arr[a] = arr[a]+arr[b];
    arr[b]=arr[a]-arr[b];
    arr[a]=arr[a]-arr[b];
}

int main()
{
    int n,q,tp,a,b,i;
    scanf("%d %d",&n,&q);

    for(i=0;i<n;i++)
        scanf("%d",arr+i);
                                   // printf("%dfsdfds\n",arr[0]);
    buildST(0,0,n-1);
                                  //  printf("%lld\n",query(0,0,n-1,2,5));
                                        // printf("%lld\n",st[12]);
                                        //for(i=0;i<2*n;i++)
                                        //    printf("%lld ",st[i]);
    while(q--)
    {
        scanf("%d %d %d",&tp,&a,&b);
        a--;    b--;
        if(tp==1)
        {
            for(i=a;i<b;i+=2)
                swapp(i,i+1);
            buildST(0,0,n-1);
        }
        else
            printf("%lld\n",query(0,0,n-1,a,b));

    }
    return 0;
}
