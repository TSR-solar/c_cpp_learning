#include <stdio.h>
 
#define LENGTH 10   
#define WIDTH  5
 
int main()
{
 
    int area;  
    area = LENGTH * WIDTH;

    printf("%d\n",area);

    printf("%s\n",__DATE__);
    printf("%s\n",__TIME__);
    printf("%s\n",__FILE__);
    printf("%d\n",__LINE__);
                
    return 0;
}
