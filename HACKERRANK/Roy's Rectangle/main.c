//https://www.hackerrank.com/contests/csindia/challenges/roys-rectangle/submissions/code/10001586
#include <stdio.h>
#include <limits.h>
#include<math.h>
#include<stdlib.h>

int mini(int a,int b)
{
    a = abs(a);
    b = abs(b);
    if(a < b)
        return a;
    return b;
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int x,y,x1,y1,x2,y2;
        scanf("%d %d %d %d %d %d",&x,&y,&x1,&y1,&x2,&y2);
        int min = INT_MAX;

        min = mini(x-x1, x2-x);
        min = mini(min,mini(y-y1,y2-y));
        printf("%d\n",min);
    }
    return 0;
}
