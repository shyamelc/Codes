#include <stdio.h>
#include <stdlib.h>

int ans[1000001]={0},filled=0,n,k,arr[10000]={0},present[1000002]={0};

void swapp(int i,int j)
{
    int p = present[i],q = present[j];

    ans[p] = j;     ans[q] = i;

    present[i] = q;     present[j] = p;
}
void insertoo(int i)
{
    int j;
    if(!present[i])
    {
        ans[filled] = i;
        present[i] = filled;
        for(j=filled-1;j>=0 && ans[j] > i;j--)
            swapp(ans[j],i);
        filled++;
    }
}

void insertBefore(int i,int before)
{
    int p = present[before],j,q = present[i];
    if(!q)
    {
        ans[filled] = i;
        present[i] = filled;
        for(j=filled-1; j>=p; j--)
        {
            if(!ans[j])
                continue;
            swapp(i,ans[j])
        }
        for( ;j>=0 && ans[j] > i; j--)
        {
            if(!ans[j])
                continue;
            swapp(ans[j],i);
        }
        ++filled;
    }
    else
    {
        if(p < q)
            return;
        present[i] = 0;
        ans[q] = 0;
        insertBefore(i,before);
    }
}

void inserti(int i,int after)
{
    int p,q,posi = present[i],posafter = present[after];
    if(!posi)
    {
        ans[filled] = i;
        present[i] = filled;
        for(p=filled-1; p>=0 && ans[p]!=after; p--)
        {
            if(!ans[p])
                continue;
            if(ans[p] < i)
                break;
            swapp(i,ans[p]);
        }
        filled++;
    }
    else
    {
        if(posi > posafter)
            return;
        present[i] = 0;
        ans[posi] = 0;
        inserti(i,after);
    }

}


int main()
{
    int i,j,gotta;
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d",ans+i);
        present[ans[i]] = i;
    }

    n--;
    filled += k;

        while(n--)
        {
            gotta = 0;
            scanf("%d",&k);
                                              //  printf("k here %d\n",k);
            scanf("%d",arr);


            for(i=1;i<k;i++)
                scanf("%d",arr+i);

            for(i=0;i<k;i++)
            {
                if(present[arr[i]])
                {
                    gotta = 1;
                    break;
                }
            }

            if(gotta)
            {
                for(j=i-1;j>=0;j--)
                    insertBefore(arr[j],arr[j+1]);
            }
            else
            {
                insertoo(arr[0]);
                i = 0;
            }


        }

        for(i=0;i<filled;i++)
        {
            if(ans[i])
                printf("%d ",ans[i]);
        }
    return 0;
}
