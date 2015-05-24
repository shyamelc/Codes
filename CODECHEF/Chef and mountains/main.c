#include <stdio.h>
#include <stdlib.h>

int h[100002], nextGreat[100002]={0},n,a,b,i,j,q;

int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",h+i);
    for(i=n-2;i>=0;i--)
    {
        for(j=i+1;j<n ;j=nextGreat[j])
        {
            if(h[j] > h[i])
            {
                                    //printf("cehc%d %d %d\n",i,j,h[j]);
                nextGreat[i] = j;
                break;
            }
            if(!nextGreat[j])
                break;
        }
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&a,&b);
        a--;    b--;
       // printf("%dkkkkkkne\n",nextGreat[a]);
        if(nextGreat[a] >= b || !nextGreat[a])
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
