#include <iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    vector<int> firstMatch;
    int n,i,maxMatch = 0,answer,k,temp;
    scanf("%d",&n);
    char A[1000006],B[1000006];
    scanf("%s",A);
    char first = A[0];
    scanf("%s",B);
    for(i=0;i<n;i++)
    {
        if(B[i]==first)
            firstMatch.push_back(i);
    }

    for(i=0;i<firstMatch.size();i++)
    {
        temp = 0;
        for(int j=0,k=firstMatch[i]; j<n; j++)
        {
            if(A[j]!=B[k])
                break;
            else
            {
                temp++;
                k = (++k)%n;
            }
        }
        if(temp>maxMatch)
        {
            maxMatch = temp;
            answer = firstMatch[i];
                                        //cout<<answer<<" ";
        }
    }
    //cout<<endl;
    cout<<answer<<endl;
    return 0;
}
