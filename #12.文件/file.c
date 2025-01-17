#include <stdio.h>
void ReadAndWriteFile(FILE *p1, FILE *p2)
{
    char str[100]={0};
    if(p1==NULL)
    {
        printf("Not Found\n");
        return;
    }
    fscanf(p1,"%s",str);
    fprintf(p2,"%s\n",str);
}

int main()
{
    FILE *p1=NULL,*p2=NULL,*p3=NULL,*p4=NULL;
    p1=fopen("a.txt","r");
    p2=fopen("sub\\b.txt","r");
    p3=fopen("..\\c.txt","r");
    p4=fopen("d.txt","a");
    ReadAndWriteFile(p1,p4);
    ReadAndWriteFile(p2,p4);
    ReadAndWriteFile(p3,p4);
    _fcloseall();
    return 0;
}