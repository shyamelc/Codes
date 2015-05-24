#include <stdio.h>
#include <math.h>
#include<string.h>

int lca_level(int a, int b)
{
    int level_a = (int) log2(a);
    int level_b = (int) log2(b);

    if(level_a > level_b)
    {
        while(level_a != level_b)
        {
            a /= 2;
            level_a--;
        }
    }
    else
    {
        while(level_a != level_b)
        {
            b /= 2;
            level_b--;
        }
    }

    while(a != b)
    {
        a /= 2;     b /= 2;
        level_a--;      level_b--;
    }

    return level_a;
}

int currentColor(int x, int evenColor)
{
    int level_x = (int) log2(x);

    if(level_x & 1)
        return (evenColor ^ 1);
    return evenColor;
}

int levelColor(int level, int evenColor)
{
    if(level & 1)
        return (evenColor ^ 1);
    return evenColor;
}

int main()
{
    char qry[5];
    int evenColor = 0, q, x, y;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s",qry);
        if(!strcmp(qry,"Qi"))
            evenColor ^= 1;
        else
        {
            scanf("%d %d",&x,&y);
            int level_x = (int) log2(x), level_y = (int) log2(y);

            int level_lca = lca_level(x,y), node_x = level_x - level_lca + 1, node_y = level_y - level_lca + 1;
            int even_x = !(node_x & 1), even_y = !(node_y & 1), ans = 0;


            if(!strcmp(qry,"Qb"))
            {
                if(even_x)
                    ans += (node_x>>1);
                else
                {
                    if(!currentColor(x,evenColor))
                        ans += (node_x>>1) + 1;
                    else ans += (node_x>>1);
                }

                if(even_y)
                    ans += (node_y>>1);
                else
                {
                    if(!currentColor(y,evenColor))
                        ans += (node_y>>1) + 1;
                    else ans += (node_y>>1);
                }

                if(!levelColor(level_lca,evenColor))
                    ans--;
            }
            else
            {
                if(even_x)
                    ans += (node_x>>1);
                else
                {
                    if(currentColor(x,evenColor))
                        ans += (node_x>>1) + 1;
                    else ans += (node_x>>1);
                }

                if(even_y)
                    ans += (node_y>>1);
                else
                {
                    if(currentColor(y,evenColor))
                        ans += (node_y>>1) + 1;
                    else ans += (node_y>>1);
                }

                if(levelColor(level_lca,evenColor))
                    ans--;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
