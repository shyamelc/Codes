//http://www.codechef.com/JAN15/problems/GCDQ

#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int test,n,q,l,r,i;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&q);
        int arr[n],gcdf[n],gcdb[n];
        for(i=0;i<n;i++)
            scanf("%d",arr+i);
        gcdf[0] = arr[0];   gcdb[n-1] = arr[n-1];

        for(i=1;i<n;i++)
            gcdf[i] = gcd(gcdf[i-1],arr[i]);
        for(i=n-2;i>=0;i--)
            gcdb[i] = gcd(gcdb[i+1],arr[i]);

        while(q--)
        {
            scanf("%d %d",&l,&r);
            l--;    r--;
            if(l!=0 && r!=(n-1))
                printf("%d\n",gcd(gcdf[l-1],gcdb[r+1]));
            else if(!l && r!=(n-1))
                printf("%d\n",gcdb[r+1]);
            else if(l!=0 && r==(n-1))
                printf("%d\n",gcdf[l-1]);
        }
    }
    return 0;
}
