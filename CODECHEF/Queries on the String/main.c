#include <stdio.h>
#include <stdlib.h>

char input[100005];
struct st
{
    long long sum,subs;
};

struct st segment[300000];

void buildST(int node,int l,int r)
{
    int m = (l+r)/2, c = 2*node+1,x;
    if(l > r)
        return;
    if(l==r)
        {
            segment[node].sum = input[l] - 48;
            if(segment[node].sum%3==0)
                segment[node].subs = 1;
        }
    else
    {
        buildST(c,l,m);
        buildST(c+1,m+1,r);

        segment[node].sum = segment[c].sum + segment[c+1].sum;
        segment[node].subs = segment[c].subs + segment[c+1].subs;

        if(segment[node].sum%3==0)
            segment[node].subs++;
    }
}

void updateST(int node,int l,int r,int index,int newvalue)
{
    if(l>r || r<index || l>index)
        return;
    if(l==r && l==index)
    {
        segment[node].subs = 0;
        segment[node].sum = newvalue;
        if(newvalue%3==0)
            segment[node].subs = 1;
        return;
    }

    int c=2*node+1, m = (l+r)/2;

    updateST(c,l,m,index,newvalue);
    updateST(c+1,m+1,r,index,newvalue);

    segment[node].sum = segment[c].sum + segment[c+1].sum;
    segment[node].subs = segment[c].subs + segment[c+1].subs;

        if(segment[node].sum%3==0)
            segment[node].subs++;
}

long long query(int node,int l,int r,int ql,int qr)
{
    if(l>r || r<ql || qr<l)
        return 0;
    if(ql<=l && r<=qr)
        return segment[node].subs;
    int c=2*node+1, m = (l+r)/2;
    return (query(c,l,m,ql,qr)+query(c+1,m+1,r,ql,qr));
}

int main()
{
    int n,m,i,a,b,c;
    scanf("%d %d",&n,&m);
    scanf("%s",input);
    buildST(0,0,n-1);
                                for(i=0;i<3*n;i++)
                                    printf("%lld ",segment[i].subs);
    while(m--)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a==1)
        {
            updateST(0,0,n-1,b-1,c);
            input[b-1] = c+48;
        }
        else printf("%lld\n",query(0,0,n-1,b-1,c-1));
    }
    return 0;
}
