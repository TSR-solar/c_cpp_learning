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

void printBook( Books *book ) //调用结构体指针的打印函数，用来输出书的标题、作者、类目、ID
{
    printf("title :%s\n",book->title);
    printf("author :%s\n",book->author);
    printf("subject :%s\n",book->subject);
    printf("ID :%d\n",book->book_id);
    //由于传进来的是指针，所以用运算符 -> 。若传进来的是结构体而不是指针，则使用运算符 . 
}

int main()
{
    Books book2;

    // Book1 详述
    strcpy( book1.title, "C++");
    strcpy( book1.author, "Runoob"); 
    strcpy( book1.subject, "program");
    book1.book_id = 12345;
    
    // Book2 详述
    strcpy( book2.title, "CSS");
    strcpy( book2.author, "Runoob");
    strcpy( book2.subject, "front");
    book2.book_id = 12346;
    
    printBook(&book1);//把book1地址传给结构体指针，令其输出数据
    printBook(&book2);//把book2地址传给结构体指针，令其输出数据
    return 0;
}