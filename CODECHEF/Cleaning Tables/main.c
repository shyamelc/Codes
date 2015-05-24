#include <stdio.h>
#include <stdlib.h>

int siz = 0;
void swap(int heap[],int posi[],int i,int j)
{
    posi[heap[i]] = j;
    posi[heap[j]] = i;
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void heapify(int heap[],int posi[],int freq[],int i)
{
    int p = (i-1)/2;
                                    //printf("hefy %d %d",i,heap[p]);

    while(i>0 && freq[heap[i]] < freq[heap[p]])
    {
                                    //printf("swap %d %d",i,p);
        swap(heap,posi,i,p);
        i = p;
        p = (i-1)/2;
    }
}

void downheapify(int heap[],int freq[],int posi[],int i)
{
    int l = 2*i+1,r = l+1,largest = i;
    if(r<siz && freq[heap[r]] < freq[heap[i]])
        largest = r;
    if(l<siz && freq[heap[l]] < freq[heap[largest]])
        largest = l;
    if(largest!=i)
    {
        swap(heap,posi,i,largest);
        downheapify(heap,freq,posi,largest);
    }
}

void add(int heap[],int freq[],int posi[],int i)
{
    posi[i] = siz;
    heap[siz] = i;
    heapify(heap,posi,freq,siz++);
}

int removeMin(int heap[],int freq[],int posi[])
{
    swap(heap,posi,0,siz-1);
    posi[heap[--siz]] = -1;
    downheapify(heap,freq,posi,0);
    return heap[siz];
}

int isFull(int m)
{
    return (siz==m);
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        siz = 0;
        int n,m,i,answer = 0;
        scanf("%d %d",&m,&n);
        int customers[n+1],frequency[401],heap[m+1],positions[401];
        char bools[401];
        for(i=1;i<=400;i++)
        {
            frequency[i] = 0;
            positions[i] = -1;
            bools[i] = 0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&customers[i]);
            frequency[customers[i]]++;
        }

        for(i=1;i<=n;i++)
        {
           if(bools[customers[i]]==0)
           {
               answer++;
               if(isFull(m))
                   bools[removeMin(heap,frequency,positions)] = 0;

               add(heap,frequency,positions,customers[i]);
               bools[customers[i]] = 1;
           }
           frequency[customers[i]]--;
        }

        printf("%d\n",answer);
    }
    return 0;
}
