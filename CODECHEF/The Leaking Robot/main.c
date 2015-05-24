//http://www.codechef.com/AUG14/problems/CRAWA
#include <stdio.h>
#include <math.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long x,y;
        int flagx = 0, flagy = 0;
        scanf("%ld %ld",&x,&y);

        if(x>0 && x%2!=0)
            flagx = 1;
        else if(x<0 && (-x)%2==0)
            flagx = 1;
        if(abs(y)%2==0)
            flagy = 1;
        if(flagx && !flagy)
        {
            int t = -(x-1);
            if(x>0 && t<=y && y<=(t+2*x))
                flagy = 1;
            else if(x<0 && x<=y && y<=(-x))
                flagy = 1;
        }
        else if(!flagx && flagy)
        {
            int dy = abs(y),l1 = 2*dy-1,l2 = 2*dy+1;
            if(y>=0 && (-y)<=x && x<=(-y)+l1)
                flagx = 1;
            else if(y<=0 && y<=x && x<=y+l2)
                flagx = 1;
        }

        if(flagx && flagy)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
