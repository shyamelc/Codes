//http://www.spoj.com/problems/KOFFBRD/
#include <stdio.h>
#include <stdlib.h>



struct combo
{
    int colorNumber, rank;
};

int cmpfunc (const void * a, const void * b)
{
   return ( (*(struct combo*)a).rank - (*(struct combo*)b).rank );
}

int colorsUsed[100002] = {0};
struct combo vinci[100002], gogh[100002];
char ans[100005];

int main()
{
    int n,i;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        vinci[i].colorNumber = i;
        scanf("%d",&vinci[i].rank);
    }

    for(i=0;i<n;i++)
    {
        gogh[i].colorNumber = i;
        scanf("%d",&gogh[i].rank);
    }

    qsort(vinci,n,sizeof(struct combo),cmpfunc);
    qsort(gogh,n,sizeof(struct combo),cmpfunc);

    int turn  = 0, vinciPri = 0, goghPri = 0;

    for(i=0; i<n; )
    {
        if(!turn)
        {
            if( !colorsUsed[vinci[vinciPri].colorNumber] )
            {
                ans[vinci[vinciPri].colorNumber] = 'V';
                                //printf("check V %d color%d\n",i,vinci[vinciPri].colorNumber+1);
                colorsUsed[vinci[vinciPri].colorNumber] = 1;
                vinciPri++;
                turn ^= 1;
                i++;
            }
            else
            {
                vinciPri++;
            }
        }
        else
        {
            if( !colorsUsed[gogh[goghPri].colorNumber] )
            {
                               // printf("check G %d color%d\n",i,gogh[goghPri].colorNumber+1);
                ans[gogh[goghPri].colorNumber] = 'G';
                colorsUsed[gogh[goghPri].colorNumber] = 1;
                goghPri++;
                turn ^= 1;
                i++;
            }
            else
            {
                goghPri++;
            }
        }
    }

    ans[i] = '\0';
    printf("%s",ans);
    return 0;
}
