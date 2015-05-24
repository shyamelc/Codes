//http://www.codechef.com/OCT14/problems/PRPOTION/
#include <stdio.h>
#include <stdlib.h>

void insertion(int arr[], int size)
{
 int i=size-1,j,tmp;

   for(j=i-1; j>=0; j--)
   {
    if(arr[j]>arr[j+1])
    {
      tmp=arr[j];
      arr[j]=arr[j+1];
      arr[j+1]=tmp;
    }
    else
      break;
   }

}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int r,g,b,m,i,j;
        scanf("%d %d %d %d",&r,&g,&b,&m);
        int red[r],green[g],blue[b],redmax=-1,bluemax=-1,greenmax=-1;

        for(i=0;i<r;i++)
        {
            scanf("%d",red+i);
            if(red[i] > redmax)
                redmax = red[i];
        }

        for(i=0;i<g;i++)
        {
            scanf("%d",green+i);
            if(green[i] > greenmax)
                greenmax = green[i];
        }

        for(i=0;i<b;i++)
        {
            scanf("%d",blue+i);
            if(blue[i] > bluemax)
                bluemax = blue[i];
        }

        while(m--)
        {
            int maxv = redmax, maxc = 0;
            if(greenmax > maxv)
            {
                maxv = greenmax;
                maxc = 1;
            }
            if(bluemax > maxv)
            {
                maxv = bluemax;
                maxc = 2;
            }

            if(!maxc)
                redmax /= 2;
            else if(maxc==1)
                greenmax /= 2;
            else bluemax /= 2;
        }

        int ans = redmax;
        if(greenmax > ans)
            ans = greenmax;
        if(bluemax > ans)
            ans = bluemax;

        printf("%d\n",ans);
    }
    return 0;
}
