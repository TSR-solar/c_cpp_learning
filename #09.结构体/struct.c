#include <stdio.h>
#include <string.h>
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book1;
typedef struct Books Books;
int main()
{
    Books book2;

    strcpy( book1.title, "C++");
    strcpy( book1.author, "Runoob"); 
    strcpy( book1.subject, "program");
    book1.book_id = 12345;

    strcpy( book2.title, "CSS");
    strcpy( book2.author, "Runoob");
    strcpy( book2.subject, "front");
    book2.book_id = 12346;
    
    printf("1.title :%s\n",book1.title);
    printf("1.author :%s\n",book1.author);
    printf("1.subject :%s\n",book1.subject);
    printf("1.ID :%d\n",book1.book_id);

    printf("2.title :%s\n",book2.title);
    printf("2.author :%s\n",book2.author);
    printf("2.subject :%s\n",book2.subject);
    printf("2.ID :%d\n",book2.book_id);
    return 0;
}