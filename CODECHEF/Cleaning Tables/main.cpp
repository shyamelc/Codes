//http://www.codechef.com/AUG14/problems/CLETAB
#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int m,n;
        cin>>n>>m;
        int customers[m],tableMembers[402],onTable[402],positins[402] = {0},tableFilled = 0,answer = 0;
        vector<int> customerSequence[402];
        for(int i=0;i<m;i++)
        {
            cin>>customers[i];
            int x = customers[i];
            customerSequence[x].push_back(i);
            onTable[x] = 0;
        }

        for(int i=0;i<m;i++)
        {                                    /*cout<<"tableMembers"<<endl;
                                            for(int z=0;z<tableFilled;z++)
                                                cout<<tableMembers[z]<<" ";*/
            int x = customers[i];
            positins[x]++;
            if(!onTable[x])
            {
                answer++;

                if(tableFilled < n)
                {
                   tableMembers[tableFilled++] = x;
                   onTable[x] = 1;
                }
                else
                {
                    int maxV = -1, maxIndex = 0;
                    for(int j=0;j<n;j++)
                    {
                        int u = tableMembers[j];
                        if(positins[u]==customerSequence[u].size())
                        {
                            maxIndex = j;
                            break;
                        }
                        if(customerSequence[u][positins[u]] > maxV)
                        {
                            maxV = customerSequence[u][positins[u]];
                            maxIndex = j;
                        }
                    }

                    int oldMember = tableMembers[maxIndex];
                    tableMembers[maxIndex] = x;
                    onTable[oldMember] = 0;
                    onTable[x] = 1;
                }
            }
        }
        cout<<answer<<endl;
    }
    return 0;
}
