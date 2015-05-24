#include <iostream>

using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    int arr[n+1];
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    int matrix[n+1][n+1];
    for(i=1; i<=n; i++)
        for(j=1;j<=n; j++)
            if(i==j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = 65000;

    for(i=1; i<=n; i++)
        for(j=i+1;j<=n; j++)
            if(j-i==1)
              {
                  matrix[i][j] = arr[i]*arr[i+1]*arr[i+2];
              }
            else
            for(int k=i; k<j; k++)
            {

              cout<<i<<" "<<k<<" "<<j<<" "<<matrix[i][k]<<" "<<matrix[k+1][j]<<" "<<arr[i-1]*arr[k]*arr[j]<<endl;
              int q = matrix[i][k] + matrix[k+1][j] + arr[i-1]*arr[k]*arr[j];
              matrix[i][j] = min(matrix[i][j],q);
            }
    cout<<matrix[1][n];
    return 0;
}
