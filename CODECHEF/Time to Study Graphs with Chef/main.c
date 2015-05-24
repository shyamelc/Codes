#include <stdio.h>
#include <stdlib.h>
#define mod 1000000007

struct changedLevels
{
    int level,totalwt;
}changedLs[100002];

int powe(int a,int b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%mod;
    long long sq=powe(a,b/2)%mod;
    if(b & 1)
        return ((sq*sq)%mod*a)%mod;
    return (sq*sq)%mod;
}

struct edgedata
{
    int levelS,levelE,nodeS,nodeE,weight;
}arr[100002];

int cmpfunc (const void * a, const void * b)
{
   return ( *(struct edgedata*)a->levelE - *(struct edgedata*)b->levelE );
}
int main()
{
    long long n,m,k,increamentByNow=0,lastLevel,i,lastLevelWeightTotal=0,thisLevelChanged=0;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=0;i<k;i++)
        scanf("%d %d %d %d",&arr[i].levelS,&arr[i].nodeS,&arr[i].levelE,&arr[i].nodeE);
    lastLevel = arr[0].levelE;
    qsort(arr,k,sizeof(struct edgedata),cmpfunc);
    for(i=0;i<k;i++)
    {
        if(lastLevel == arr[i].levelE)
        {
            howManyThisLevelChanged++;
            lastLevelWeightTotal += powe(arr[i].levelS)
        }

        else
        {

        }
        arr[i].weight = powe(m,arr[i].levelS-1);
    }
    return 0;
}
