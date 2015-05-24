#include <stdio.h>
#include <stdlib.h>

struct two
{
    int index,value;
};

int cmp(const void *p1,const void *p2)
{
    struct two a = *( (struct two*) p1 );
    struct two b = *( (struct two*) p2 );

    return abs(a.value) - abs(b.value);
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,i,ans=0,t,vi,di;
        scanf("%d",&n);
        struct two villagers[n],dino[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&t);
            if(t < 0)
            {
                dino[di].index = i;
                dino[di++].value = t;
            }
            else
            {
                villagers[vi].index = i;
                villagers[vi++].value= t;
            }
        }

        qsort(villagers,vi,sizeof(struct two),cmp);
        qsort(dino,di,sizeof(struct two),cmp);

       /* int cur = 0;
        for(i=0;i<vi;i++)
        {
            while(villagers[i].value != 0)
            {
               if(villagers[i].value <= (-dino[cur].value))
               {
                   dino[cur].value += villagers[i].value;
                   ans += villagers[i].value*(abs(villagers[i].index - dino[cur].index));
                   villagers[i].value = 0;
               }
               else
               {
                   villagers[i].value += dino[cur].value;
                   ans += (-(dino[cur].value))*(abs(villagers[i].index - dino[cur].index));
                   dino[cur].value = 0;
               }

               if(dino[cur].value == 0)
                    cur++;
            }
        }*/
        printf("%d\n",ans);
    }
    return 0;
}
