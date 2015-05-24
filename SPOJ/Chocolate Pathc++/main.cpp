#include <stdio.h>
#include<vector>
#include<queue>

using namespace std;

int chocVan[2][101];

int nodes[201][201],visited[201] = {0};
char temp[102];


void BFS()
{

}

int main()
{
    int m,i,j,mdub;
    scanf("%d",&m);
    mdub = 2*m;
    scanf("%s",temp);
    for(i=0;i<m;i++)
    {

        if(temp[i]=='.')
            chocVan[0][i] = 0;
        else chocVan[0][i] = 1;
    }
    scanf("%s",temp);
    for(i=0;i<m;i++)
    {

        if(temp[i]=='.')
            chocVan[1][i] = 0;
        else chocVan[1][i] = 1;
    }



    for(i=0;i<mdub;i++)
        for(j=0;j<mdub;j++)
            nodes[i][j] = 0;

    for(i=0;i <m;i++)
    {
        if( !chocVan[0][i] )
        {
            if( !chocVan[0][i+1])
            {
                nodes[i][i+1] = 1;
                nodes[i+1][i] = 1;
            }


            if( !chocVan[1][i])
            {
                nodes[i][m+i] = 1;
                nodes[m+i][i] = 1;
            }
        }
    }

    for(i=0;i <m;i++)
    {
        if( !chocVan[1][i] )
        {
            if( !chocVan[1][i+1])
            {
                nodes[m+i][m+i+1] = 1;
                nodes[m+i+1][m+i] = 1;
            }

        }
    }
    return 0;
}
