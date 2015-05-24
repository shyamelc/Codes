#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,i,j;
        int colums[1001] = {0}, rows = {0}, rowfilled = 0, columfilled = 0;
        char t;
        scanf("%d",&n);
        int arr[n+1][n+1];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                scanf("%c",&t);
                if(t=='#')
                {
                    arr[i][j] = 1;
                    rows[rowfilled++] = i;
                    colums[columfilled++] = j;
                }
                else arr[i][j] = 0;
            }
    }
    return 0;
}
