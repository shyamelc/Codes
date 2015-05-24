//http://codeforces.com/contest/545/problem/A

#include <stdio.h>
#include <stdlib.h>

int mat[101][101],ansarr[101];

int main()
{
    int n,i,j,ans=0,flag;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        flag = 1;
        for(j=0;j<n;j++)
        {
            if(mat[i][j]==3 || mat[i][j]==1)
                {
                    flag = 0;
                    break;
                }
        }

        if(flag)
            ansarr[ans++] = i+1;
    }
    printf("%d\n",ans);
    for(i=0;i<ans;i++)
        printf("%d ",ansarr[i]);
    return 0;
}
