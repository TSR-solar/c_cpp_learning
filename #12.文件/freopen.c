#include <stdio.h>
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",a+b);
    _fcloseall();
    return 0;
}