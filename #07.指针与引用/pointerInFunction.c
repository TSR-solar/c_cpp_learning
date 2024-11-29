#include <stdio.h>
void changeInFunction(int *p)
{
    *p=514;
}

int main()
{
    int i=114;
    int *p=&i;
    printf("former: i=%d\n",i);
    changeInFunction(p);
    printf("after: i=%d\n",i);
    return 0;
}