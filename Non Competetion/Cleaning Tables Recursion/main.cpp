#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,m,answer = 0,filled = 0;
        cin>>n>>m;
        int customers[m],tableMembers[n],tableFilled = 0;
        bool onTable[401] = {false};
        vector<int> arr[401];
        int positions[401] = {0};
        for(int i=0;i<m;i++)
        {
            cin>>customers[i];
            arr[customers[i]].push_back(i);
        }

        for(int i=0;i<m;i++)
        {
            if(!onTable[customers[i]])
            {
                answer++;
                if(tableFilled >= n)
                {
                    int minV = -1,minIndex;
                    for(int j=0;j<tableFilled;j++)
                    {
                        int x = tableMembers[j];

                         if(positions[x]==arr[x].size())
                         {
                             minIndex = j;
                             break;
                         }

                        if(arr[x][positions[x]+1] > minV)
                        {
                            minV = arr[x][positions[x]+1];
                            minIndex = j;
                        }
                    }
                    onTable[tableMembers[minIndex]] = false;
                    onTable[customers[i]] = true;

                    tableMembers[minIndex] = customers[i];
                }
                else
                {
                   onTable[customers[i]] = true;
                   tableMembers[tableFilled++] = customers[i];
                }
            }
            positions[customers[i]]++;
        }
        cout<<answer<<endl;
    }
    return 0;
}
