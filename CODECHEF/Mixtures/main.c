#include <stdio.h>
#include <limits.h>

int products[102][102], colors[102][102];

int minColors(int i,int j)
{
                                            //printf("%d %dcolors\n",i,j);
    if(colors[i][j]<INT_MAX)
        return colors[i][j];
    int k,tempMin;
    for(k=i;k<j;k++)
    {
        tempMin = (minColors(i,k) + minColors(k+1,j))%100;
        if(tempMin < colors[i][j])
            colors[i][j] = tempMin;
    }
    return colors[i][j];
}

int minProducts(int i,int j)
{
                                    //printf("%dhi\n",i);
    if(products[i][j] < INT_MAX)
        return products[i][j];
    int k,tempMin,x,y;
    for(k=i;k<j;k++)
    {
        x = minColors(i,k);
        y = minColors(k+1,j);
        tempMin = minProducts(i,k) + minProducts(k+1,j) + x*y;
        if((x+y)%100 < colors[i][j])
            colors[i][j] = (x+y)%100;
        if(tempMin < products[i][j])
            products[i][j] = tempMin;
    }
    return products[i][j];
}
int main()
{
    int n,i,j,k;
    while(scanf("%d",&n)!=EOF)
    {

       // printf("%d",scanf("%d",&n)) ;                       //printf("%d %d",sizeof(products),sizeof(colors));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(i==j)
                    products[i][j] = 0;
                else
                    products[i][j] = INT_MAX;
                colors[i][j] = INT_MAX;
            }
        for(i=0;i<n;i++)
            scanf("%d",&colors[i][i]);

        for(i=0;i<n-1;i++)
        {
            products[i][i+1] = colors[i][i]*colors[i+1][i+1];
            colors[i][i+1] = (colors[i][i]+colors[i+1][i+1])%100;
        }


        printf("%d\n",minProducts(0,n-1));
    }
    return 0;
}
