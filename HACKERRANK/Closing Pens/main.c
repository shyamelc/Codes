#include <stdio.h>
#include <stdlib.h>

struct pen{
    int dia,color,taken;
} pens[107];
struct cap{
    int dia,color,taken;
} caps[107];

int mini(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
int n,m,mat[1002][105],j,i,mat2[1002]={0},pendiataken[1002]={0};

int main()
{
    int ansa=0,ansb=0,temp;
    scanf("%d %d",&n,&m);
    for(i=0;i<=1000;i++)
    {
        mat[i][0] = 2;
        mat[i][1] = 0;
    }

    for(i=0;i<n;i++)
    {
        scanf("%d %d",&pens[i].color,&pens[i].dia);
        pens[i].taken = 0;
        mat2[pens[i].dia]++;
    }

    for(i=0;i<m;i++)
    {
        scanf("%d %d",&caps[i].color,&caps[i].dia);
                            //printf("%d %d %d",caps[i].dia,mat[caps[i].dia][mat[i][0]],)
        mat[caps[i].dia][mat[caps[i].dia][0]++] = i;
        caps[i].taken = 0;
    }
                                                           /* for(i=0;i<5;i++)
                                                            {
                                                                printf("\n");
                                                                for(j=0;j<mat[i][0];j++)
                                                                    printf("%d ",mat[i][j]);
                                                            }

                                                            printf("\n\n");*/

    for(i=0;i<n;i++)
    {
        temp = pens[i].dia;
        if(!pendiataken[temp])
        {
            ansa += (mini(mat[temp][0]-1,mat2[temp]));
            pendiataken[temp] = 1;
        }

        for(j=2;j<mat[temp][0];j++)
        {
            if(caps[mat[temp][j]].color == pens[i].color && !caps[mat[temp][j]].taken)
            {
                pens[i].taken = 1;
                caps[mat[temp][j]].taken = 1;
                mat[i][1]++;
                ansb++;
                break;
            }
        }
    }

   /* for(i=0;i<n;i++)
    {
        if(!pens[i].taken)
        {
            if(mat[pens[i].dia][0]-1-mat[pens[i].dia][1] > 0)
            {
                ansa++;
                mat[pens[i].dia][1]++;
            }
        }
    }*/

    printf("%d %d\n",ansa,ansb);
    return 0;
}
