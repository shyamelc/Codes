//http://www.codechef.com/SEPT14/problems/UASEQ

//Completely made in C
#include <stdio.h>
#include<limits.h>

using namespace std;

int arr[100002];
int mina = INT_MAX, mind = INT_MAX;

int min(int a,int b)
{
    if(a < b)
        return a;
    return b;
}
void method1(int n,int k)
{
   if(!k)
        return;
    int a,d;
    int i,j,x;
    for(i=1;i<=n-1;i++)
    {
        d = arr[i+1] - arr[i];
        a = arr[i+1] - (i)*d;
                                        //printf("%d %dgene\n",a,d);
        if(a < mina || (a==mina && d < mind))
        {
                                //printf("%d %dwent\n",a,d);
            int counter = 0;
            for(j=1;j<=n;j++)
            {
                if(arr[j] != (a + (j-1)*d))
                    counter ++;
                if(counter > k)
                    break;
            }

            if(counter <= k)
            {
                mina = a;
                mind = d;
            }
        }
    }

    for(i=1;i<=n;i++)
        arr[i] = mina + (i-1)*mind;
}

void method2(int n,int k)
{
     if(!k)
        return;
    int a,d;
    int i,j,x;
    for(i=1;i<=n-1;i++)
        for(j=i+1;j<=n;j++)
        {
            d = (arr[j] - arr[i])/(j-i);
            a = min(arr[i]-(i-1)*d, arr[j]-(j-1)*d);
            if(a < mina || (a==mina && d<mind))
            {
                int counter = 0;
                for(x=1;x<=n;x++)
                {
                    if(arr[x]!=(a+(x-1)*d))
                        counter++;
                    if(counter > k)
                        break;
                }

                if(counter <= k)
                {
                    mina = a;
                    mind = d;
                }
            }
        }

    for(x=1;x<=n;x++)
        arr[x] = mina + (x-1)*mind;
}
int main()
{
    int n,k,i;
    scanf("%d %d",&n,&k);

    for(i=1;i<=n;i++)
        scanf("%d",arr+i);

    if(n <= 12 || n > 30)
        method1(n,k);
    else
        method2(n,k);

    for(i=1;i<=n;i++)
        printf("%d ",arr[i]);
    return 0;
}
