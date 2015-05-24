//http://www.spoj.com/problems/MARTIAN/
// solution well explained :- http://apps.topcoder.com/forums/?module=Thread&threadID=710074&start=0&mc=9#1542444
#include<stdio.h>

int left[502][502],up[502][502],rowSums[502][502],colsums[502][502],y[502][502],b[502][502],m,n,i,j;

int maxi(int a,int b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    scanf("%d %d",&n,&m);
    while(m!=0)
    {
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                scanf("%d",&y[i][j]);
                left[i][j] = 0;
                up[i][j] = 0;
            }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&b[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(j!=0)
                    rowSums[i][j] = rowSums[i][j-1] + y[i][j];
                else rowSums[i][j] = y[i][j];

                if(i!=0)
                    colsums[i][j] = colsums[i-1][j] + b[i][j];
                else colsums[i][j] =  b[i][j];
            }

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(i!=0)
                    left[i][j] = maxi(left[i-1][j],up[i-1][j]) + rowSums[i][j];
                else left[i][j] = rowSums[i][j];

                if(j!=0)
                    up[i][j] = maxi(up[i][j-1],left[i][j-1]) + colsums[i][j];
                else up[i][j] = colsums[i][j];
            }
       printf("%d\n",maxi(left[n-1][m-1],up[n-1][m-1]));
        scanf("%d %d",&n,&m);
    }
}
