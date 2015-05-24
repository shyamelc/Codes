#include <stdio.h>
#include <string.h>

char str[11][22];
int length[11] = {0};
int n,i;

void recurse()
{
    char temp[25];
    if(str[0][length[0]] == '\0')
        return;
    int j;
    for(j=0;j<n;j++)
    {
        if(str[j][length[j]] == '\0')
        {
            length[j] = 0;
            length[j-1]++;
            recurse();
            return;
        }
        temp[j] = str[j][length[j]];
    }
    temp[j] = '\0';
    printf("%s\n",temp);
    length[n-1]++;
    recurse();
}

int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",str[i]);
    recurse();

    return 0;
}
