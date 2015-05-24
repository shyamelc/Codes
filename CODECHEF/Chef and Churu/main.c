#include <stdio.h>
#include <stdlib.h>

int arr[100002], leftV[100002], rightV[100002], leastIn[300001], maxIn[300001] ,f[100001] ,segmentTree[300001], st[300001];

int mini(int a,int b)
{
    if(a < b)
        return a;
    return b;
}

int maxi(int a,int b)
{
    if(a > b)
        return a;
    return b;
}

void formST(int from[],int to[],int start, int end, int index)
{
                    //printf("check %d",from[start]);
    if(start==end)
    {
        to[index] = from[start];
        leastIn[index] = leftV[start];      maxIn[index] = rightV[start];
        return;
    }

    if(end < start)
        return;

    int mid = (start + end)/2,x=2*index+1;

    formST(from,to,start,mid,x);
    formST(from,to,mid+1,end,x+1);

    to[index] = to[x] + to[x+1];
    leastIn[index] = mini(leastIn[x],leastIn[x+1]);     maxIn[index] = maxi(maxIn[x],maxIn[x+1]);
}


int findST(int from[],int qs, int qe, int ss, int se, int index)
{
    if(se < qs || ss > qe || se < ss)
        return 0;

    if(qs <= ss && qe >= se)
        return from[index];

    int mid = (ss+se)/2, x=2*index+1;

    return findST(from,qs,qe,ss,mid,x) + findST(from,qs,qe,mid+1,se,x+1);
}

void update(int x, int y, int n)
{
    int diff = y - arr[x];
    arr[x] = y;
    updateST(0,n-1,x,diff,0);
}

void updateST(int start,int end,int x,int diff,int index)
{
    if(end < start)
        return;
    if(start==end && leastIn[index] <= x && x <= maxIn[index])
        segmentTree[index] += diff;

    if(leastIn[index] > x || maxIn[index] < x)
        return;

    segmentTree[index] += diff;

    int mid = (start + end)/2, z=2*index+1;

    updateST(start,mid,x,diff,z);
    updateST(mid+1,end,x,diff,z+1);
}

int main()
{
    int n,i,u,v,q,check,a,b;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",arr+i);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        leftV[i] = --u;     rightV[i] = --v;
    }

    formST(arr,st,0,n-1,0);
                /*for(i=0;i<3*n;i++)
                    printf("%d ",st[i]);
                printf("\n\n");*/
    for(i=0;i<n;i++)
    {
        f[i] = findST(st,leftV[i],rightV[i],0,n-1,0);
       // printf("%d ",f[i]);
    }

   // formSegmentTree(f,segmentTree,0,n-1,0);
        formST(f,segmentTree,0,n-1,0);
               // printf("\n\n");
    /*/ for(i=0;i<3*n;i++)
    {
        //f[i] = findST(leftV[i],rightV[i],0,n-1,0);
        printf("%d ",segmentTree[i]);
    }*/

    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d %d",&check,&a,&b);
        if(check == 2)
            printf("%d\n",findST(segmentTree,a-1,b-1,0,n-1,0));
        else
            update(a-1,b,n);
    }
    return 0;
}
