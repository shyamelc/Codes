#include<stdio.h>

int main()
{
    int x = 1;
    printf("%d\n",*((char*)&x));
    return 0;
}
