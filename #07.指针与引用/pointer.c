#include <stdio.h>
int main()
{
    int i = 114;
    int *p = &i;
    int *q = NULL;
    printf("p=%p\n",p);
    printf("q=%p\n",q);
    printf("i=%d\n",i);
    printf("*p=%d\n",*p);
    return 0;
}