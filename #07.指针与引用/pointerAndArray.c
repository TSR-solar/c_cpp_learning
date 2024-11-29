#include <stdio.h>
void changeInFunction(int a[])
{
    *a+=1;
    a[1]+=1;
    a[2]+=1;
}

int main()
{
    int a[]={1, 2, 3};
    int *p=a;
    printf("a[0]=%d; *a=%d;\n",a[0],*a);
    printf("p[0]=%d; p[1]=%d; p[2]=%d;\n",p[0],p[1],p[2]);
    printf("a[0]=%d; a[1]=%d; a[2]=%d; (former)\n",a[0],a[1],a[2]);
    changeInFunction(a);
    printf("a[0]=%d; a[1]=%d; a[2]=%d; (after)\n",a[0],a[1],a[2]);
    return 0;
}