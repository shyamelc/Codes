//https://www.hackerrank.com/contests/codestar-long-programming-contest/challenges/arrange-the-apple-baskets

#include <stdio.h>
#include <stdlib.h>

int mplusn,m,n,i,j,temp,a[100002],b[100002],c[100002];

void merge(int a[], int m, int b[], int n, int sorted[]) {
  int i, j, k;

  j = k = 0;

  for (i = 0; i < m + n;) {
    if (j < m && k < n) {
      if (a[j] < b[k]) {
        sorted[i] = a[j];
        j++;
      }
      else {
        sorted[i] = b[k];
        k++;
      }
      i++;
    }
    else if (j == m) {
      for (; i < m + n;) {
        sorted[i] = b[k];
        k++;
        i++;
      }
    }
    else {
      for (; i < m + n;) {
        sorted[i] = a[j];
        j++;
        i++;
      }
    }
  }
}

int main()
{
    scanf("%d",&mplusn);
    j = 0;
    for(i=0;i<mplusn;i++)
    {
        scanf("%d",&temp);
        if(temp != -1)
            a[j++] = temp;
    }
    scanf("%d",&n);
    m = mplusn - n;
    for(i=0;i<n;i++)
        scanf("%d",b+i);
    merge(a,m,b,n,c);
    for(i=0;i<mplusn;i++)
        printf("%d\n",c[i]);
    return 0;
}
