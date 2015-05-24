//http://www.codechef.com/problems/RRFRNDS/
#include <cstdio>
#include<vector>
#include<string>
#include<iostream>

using namespace std;
short matrix[2005][2005];
vector<int> graph[2005];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        string str;
        cin>>str;
        for(j=0;j<str.size();j++)
        {
            if(str[j]=='1')
            {
                graph[i].push_back(j);
                matrix[i][j] = 1;
            }
            else    matrix[i][j] = 0;
        }
    }
    long long answer = 0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(i!=j && !matrix[i][j])
            {
                for(k=0;k<graph[i].size();k++)
                {
                    if(matrix[j][graph[i][k]] == 1)
                    {
                        answer++;
                                        //cout<<i<<" "<<j<<" "<<graph[i][k]<<endl;
                        break;
                    }
                }
            }
        }

    printf("%lld\n",answer);
    return 0;
}
