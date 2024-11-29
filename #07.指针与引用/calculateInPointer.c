#include <stdio.h>
int main()
{
    int a[6]={0};
    int *p=&a[0];
    int *q=&a[6];
    printf("q-p=%d\n",q-p);
    return 0;
}