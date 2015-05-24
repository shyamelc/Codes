    //http://www.codechef.com/JAN15/problems/CLPERM

    #include <stdio.h>
    #include <stdlib.h>
    long long cmpfunc (const void * a, const void * b)
    {
    return ( *(long long*)a - *(long long*)b );
    }
    int main()
    {
    long long test,n,k,i,kcounter;
    long long sums=0,ans,sumofks,temp;
    scanf("%lld",&test);
    while(test--)
    {
    sumofks = 0;
    scanf("%lld %lld",&n,&k);
    long long arr[k];
    for(i=0;i<k;i++)
    {
    scanf("%lld",arr+i);
    sumofks += arr[i];
    }
    qsort(arr,k,sizeof(int),cmpfunc);
    if(k==0)
    ans = n*(n+1)/2+1;
    else if(k==1)
    {
    if(arr[0] <= arr[0]*(arr[0]-1)/2)
    ans = n*(n+1)/2+1-arr[0];
    else ans = arr[0];
    }
    else
    {
    ans = 0;
    sums = arr[0]*(arr[0]-1)/2; //printf("%dsumsold\n",sums);
    kcounter = 0;
    if(arr[0] > sums)
    ans = arr[0];
    else
    {
    for(i=1;i<k;i++)
    {
    sums += (arr[i]-1)*arr[i]/2 - (arr[i-1]+1)*arr[i-1]/2;
    if(arr[i] > sums)
    {
    ans = arr[i];
    break;
    }
    }
    if(!ans)
    {
    ans = n*(n+1)/2 - sumofks + 1;
    }
    }
    }
    //printf("%lld\n",ans);
    if(ans & 1)
    printf("Chef\n");
    else printf("Mom\n");
    }
    return 0;
    }
