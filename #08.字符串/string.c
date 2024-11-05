#include <stdio.h>
#include <string.h>
int main()
{
    char str1[13]="hello";
    char str2[13]="world";
    char str3[13]={0};
    int len;

    strcpy(str3,str1);
    printf("strcpy(str3,str1): %s\n",str3);

    strcat(str1,str2);
    printf("strcat(str1,str2): %s\n",str1);

    len=strlen(str1);
    printf("strlen(str1): %d\n",len);
    
    return 0;
}