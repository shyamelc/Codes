#include <stdio.h>
#include <stdlib.h>

int minMoves(int A,int B,int C)
{
    int a=A,b=0,transfer=0,moves=1;

    while(a!=C && b!=C)
    {
                            //printf("%d %dbegin\n",a,b);
        transfer = (a < B-b ? a:B-b);
        b += transfer;
        a -= transfer;
        moves++;

        if(a==C || b==C)
            break;
        if(a==0)
        {
            a=A;
            moves++;
        }
        if(b==B)
        {
            b=0;
            moves++;
        }
                            //printf("%d %dend\n",a,b);
    }
    return moves;
}

int gcd(int a,int b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int A,B,C;
        scanf("%d %d %d",&A,&B,&C);

        if((C>A && C>B) || (C%gcd(A,B)!=0))
            printf("-1\n");
        else
            {
                int x = minMoves(A,B,C);
                int y = minMoves(B,A,C);
                printf("%d\n",(x<y ? x:y));
            }
    }
    return 0;
}
