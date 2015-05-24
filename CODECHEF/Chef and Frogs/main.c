http://www.codechef.com/JULY14/problems/FROGV
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct coordinate
{
    long long point;
    long index;
};

long connected[100005];

long root(long i)
{
    while(i != connected[i])
    {
        connected[i] = connected[connected[i]];
        i = connected[i];
    }
    return i;
}

void qUnion(long i, long j)
{
    long p = root(i);       long q = root(j);
    if(p!=q)
        connected[q] = p;
}

int comp(void *f, void *s)
{
    struct coordinate first = *((struct coordinate*)f);
    struct coordinate second =  *((struct coordinate*)s);

    return (first.point-second.point);
}

int main()
{
    long n,p,i;
    long long k;
    scanf("%ld %lld %ld",&n,&k,&p);
    for(i=0; i<n; i++)
        connected[i] = i;
    struct coordinate input[n];
    for(i=0; i < n; i++)
    {
        input[i].index = i;
        scanf("%lld",&input[i].point);
    }
    qsort(input,n,sizeof(struct coordinate),comp);
    for(i=1; i<n; i++)
    {
        if(abs(input[i].point-input[i-1].point) <= k)
        {
            qUnion(input[i-1].index, input[i].index);
           // printf("Union %ld %ld\n",input[i-1].index, input[i].index);
        }
    }

    while(p--)
    {
        long A,B;
        scanf("%ld %ld",&A, &B);
        A--;    B--;
        if(root(A)==root(B))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
