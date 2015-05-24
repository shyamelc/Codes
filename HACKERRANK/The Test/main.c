#include <stdio.h>
#include <string.h>

char a[200],b[200],c[200],d[200];

int main()
{
    scanf("%s %s %s %s",a,b,c,d);
    int la=strlen(a),lb = strlen(b),lc=strlen(c),ld=strlen(d),gotans=0;
    char ans = 'C';
    la--;   lb--;   lc--;   ld--;       la--;   lb--;   lc--;   ld--;
  //  int ab = strcmp(a+1,b+1), ac = strcmp(a+1,c+1), ad = strcmp(a+1,d+1),bc=strcmp(b+1,c+1),bd=strcmp(b+1,d+1),cd=strcmp(c+1,d+1);

    //if(ab && ac && ad)
    {
        if(la>=2*lb && la>=2*lc && la>=2*ld)
        {
            gotans = 1;
            ans = 'A';
        }
        else if(2*la<=lb && 2*la<=lc && 2*la<=ld)
        {
            gotans = 1;
            ans = 'A';
        }
    }
    // if(ab && bc && bd)
    {
        if(lb >= 2*la && lb >= 2*lc && lb >= 2*ld)
        {
            if(!gotans)
                gotans = 1;
            ans = 'B';
        }
        else if(2*lb <= la && 2*lb <= lc && 2*lb <= ld)
        {
            if(!gotans)
                gotans = 1;
            ans = 'B';
        }
    }
    // if(ad && bd && cd)
    {
        if(ld >= 2*la && ld>=2*lb && ld >= 2*lc)
        {
            if(!gotans)
                gotans = 1;
            ans='D';
                                printf("hi");
        }
        else if(2*ld <= la && 2*ld<=lb && 2*ld <= lc)
        {
            if(!gotans)
                gotans = 1;
            ans='D';
                                printf("hel");
        }
    }
    if(gotans)
        printf("%c\n",ans);
    else printf("C\n");
    return 0;
}
