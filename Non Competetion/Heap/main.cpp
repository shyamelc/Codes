#include <iostream>
#include<vector>

using namespace std;

template<class T>
class Heap
{

    std::vector<T> PQ;
    int n = 0;

    int parent(int i)
    {
        return (i-1)/2;
    }

    int leftChild(int i)
    {
        return (2*i+1);
    }

    int rightChild(int i)
    {
        return (2*i + 2);
    }

    void swapKeys(int i, int j)
    {
        int temp = PQ[i];
        PQ[i] = PQ[j];
        PQ[j] = temp;
    }

    void heapify_up(int i)
    {
       while(PQ[i] > PQ[parent(i)] && i>0)
           swapKeys(i,parent(i));
    }

    void heapify_down(int i)
    {

        while((PQ[i] < PQ[leftChild(i)] || PQ[i] < PQ[rightChild(i)]) && i<n)
        {
                                            cout<<PQ[i]<<" ";
            int l = leftChild(i),r = rightChild(i);
            T x = max(PQ[l],PQ[r]);
            int toWork = l;
            if(x==PQ[r])
                toWork = r;
            swapKeys(i,toWork);
            i = toWork;
        }
    }

public:
    void add(T key)
    {
        PQ.push_back(key);
        heapify_up(n++);
    }

    T del_max()
    {
        T toreturn = PQ[0];
        swapKeys(0,--n);
        heapify_down(0);

        return toreturn;
    }

    T showMax()
    {
        return PQ[0];
    }

};

int main()
{
    Heap<int> heap;
    heap.add(5);    heap.add(7);    heap.add(2);    cout<<heap.del_max()<<endl;     cout<<heap.del_max()<<endl;

    return 0;
}
