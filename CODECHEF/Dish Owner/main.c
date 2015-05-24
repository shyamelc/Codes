http://www.codechef.com/JULY14/problems/DISHOWN
#include <stdio.h>
#include <stdlib.h>

long root(long id[], long i)
{
    while(id[i]!=i)
    {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void qUnion(long id[], long s[], long f, long sec)
{
    long p = root(id, f);
    long q = root(id, sec);
    if(p==q)
    {
        printf("Invalid query!\n");
        return;
    }

    if(s[p]==s[q])
        return;

    if(s[p] < s[q])
        id[p] = q;
    else
        id[q] = p;
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long n,i,Q;
        scanf("%ld",&n);
        long s[n];
        for(i=0; i<n; i++)
            scanf("%ld",&s[i]);
        long connected[n];
        for(i=0; i<n; i++)
            connected[i] = i;
        scanf("%ld",&Q);
        while(Q--)
        {
            long x,y;
            int op;
            scanf("%d",&op);
            if(op==0)
            {
                scanf("%ld %ld",&x,&y);
               // printf("test %c %ld %ld",op,x,y);
                qUnion(connected, s, x-1, y-1);
            }
            else
            {
                scanf("%ld",&x);
                printf("%d\n",root(connected,x-1)+1);
            }
        }
    }
    return 0;
}
