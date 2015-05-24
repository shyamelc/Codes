#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,m,i,j,k;
        scanf("%d %d",&n,&m);
        char matrix[n][m];
        int enemyR[n], enemyC[m];

        for(i=0;i<n;i++)
            enemyR[i] = 0;
        for(i=0;i<m;i++)
            enemyC[i] = 0;

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                scanf("%c",&matrix[i][j]);
                    printf("%c\n",matrix[i][j]);
                if(matrix[i][j]=='E')
                {
                    enemyR[i] += 1;
                    enemyC[j] += 1;
                }
            }


        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
               if(matrix[i][j]=='L')
               {
                   if(enemyR[i])
                   {
                       for(k=0;k<m;k++)
                       {
                           if(matrix[i][k]=='E')
                           {
                               matrix[i][k] = '.';
                               enemyC[k] -= 1;
                           }
                       }

                       enemyR[i] = 0;
                   }
                   else
                   {
                       if(enemyC[j])
                       {
                           for(k=j;k>=0;k--)
                           {
                               if(matrix[k][j]=='E')
                               {
                                   matrix[k][j] = '.';
                                   enemyR[k] -= 1;
                                   enemyC[j] -= 1;
                               }
                           }
                       }
                   }
               }
            }
        }

        int answer = 1;
        for(i=0;i<n;i++)
            if(enemyR[i])
            {
                answer = 0;
                break;
            }
        if(answer)
        for(i=0;i<m;i++)
            if(enemyC[i])
            {
                answer = 0;
                break;
            }

        if(answer)
            printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}
