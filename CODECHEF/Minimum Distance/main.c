#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int Ds,Dt,D;
        scanf("%d %d %d",&Ds,&Dt,&D);

        if(Ds + Dt < D)
            printf("%d\n",D-Ds-Dt);
        else if(Ds+Dt == D)
            printf("0\n");
        else
        {
            if(D >= Ds && D >= Dt)
                printf("0\n");
            else if(D==0)
                printf("%d\n",abs(Dt-Ds));
            else if(abs(Ds-Dt)==D)
                printf("0\n");
            else
            {
                if(Ds < Dt)
                {
                    int temp = Ds;
                    Ds = Dt;
                    Dt = temp;
                }

                printf("%d\n",Ds-Dt-D);
            }
        }
    }
    return 0;
}
