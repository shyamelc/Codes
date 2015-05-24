//http://www.codechef.com/AUG14/problems/REVERSE

//I am using Dijkstra's Algorithm
//Each edge given from u->v, I made that edge with weig 9ht 0 and made edge v->u with weight 1
//Running dijkstra on this graph and finding shortest path gives the answer

#include<iostream>
#include<vector>
#include<limits.h>
#define MYMAX 100005
using namespace std;
vector< pair<int,int> > nodes[100002];
int distances[100002] = {0};
class Heap
{
//private :
public:
    pair<int,int> arr[MYMAX];
    int positions[MYMAX];
    int sizze;
    int parent(int i)
    {
        return (i-1)/2;
    }
    int leftChild(int i)
    {
        return 2*i+1;
    }
    void swapKeys(int i,int j)
    {
        positions[arr[i].first] = j;
        positions[arr[j].first] = i;
        swap(arr[j],arr[i]);
    }
//public:

    bool isEmpty()
    {
        return sizze==0;
    }
    void Heapify(int i)
    {
        while(arr[i].second < arr[parent(i)].second && i>0)
        {
            int p = parent(i);
            swapKeys(i,p);
            i = p;
        }
    }

    void downHeapify(int i)
    {
        int l = leftChild(i);
        int maxi;
        if(l+1 < sizze)
        {
            if(arr[l].second < arr[l+1].second)
                maxi = l;
            else maxi = l+1;
        }
        else if(l < sizze)
            maxi = l;
        else return;
        if(arr[i].second > arr[maxi].second)
        {
            swapKeys(i,maxi);
            downHeapify(maxi);
        }
    }

    pair<int,int> removeMin()
    {
        swapKeys(0,--sizze);
        downHeapify(0);
        positions[arr[sizze].first] = -1;
        return arr[sizze];
    }

    void add(pair<int,int> x)
    {
        arr[sizze++] = x;
        positions[x.first] = sizze-1;
        Heapify(sizze-1);
    }

    void update(int i,int dist)
    {
        int pos = positions[i];
        if(pos==-1)
            return;
        if(dist < arr[pos].second || arr[pos].second < 0)
        {
            arr[pos].second = dist;
            Heapify(pos);
        }
    }
};

int main()
{
    Heap hp;
    hp.positions[1] = -1;
    hp.sizze = 0;
    int m,n,a,b,edges;
    cin>>n>>m;
    edges = m;
    while(m--)
    {
        cin>>a>>b;
        if(a!=b)
        {
            nodes[a].push_back(make_pair(b,0));
            nodes[b].push_back(make_pair(a,1));
        }
    }
    for(int i=2;i<=n;i++)
    {
        distances[i] = MYMAX;
        hp.add(make_pair(i,MYMAX));
    }
    distances[1] = 0;
    for(int i=0;i<nodes[1].size();i++)
        hp.update(nodes[1][i].first,nodes[1][i].second);

    while(!hp.isEmpty())
    {
        pair<int,int> minEle = hp.removeMin();
        distances[minEle.first] = minEle.second;
        for(int i=0;i<nodes[minEle.first].size();i++)
            hp.update(nodes[minEle.first][i].first, distances[minEle.first] + nodes[minEle.first][i].second);
    }

    if(0<=distances[n] && distances[n]<=edges)
        cout<<distances[n];
    else
        cout<< -1;
    return 0;
}
