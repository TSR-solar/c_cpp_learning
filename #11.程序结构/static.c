#include <stdio.h>
void staprintf(int n)
{
    printf("%d\n",n);
}
int main()
{
    static int n;
    scanf("%d",&n);
    staprintf(n);
    return 0;
}