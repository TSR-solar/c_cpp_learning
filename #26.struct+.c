/*
    有没有试过把两种常见的数据结构结合起来？
    在结构体里面存储数组，这是很常见的；比如书的名称里面就包含了字符数组；
    在数组里面存储结构体，其实也简单，就把数组当成一个能储存不同变量的二维数组就行了；
    在结构体里面嵌套结构体，也是常规操作，当引用最底层的结构体成员时，需要使用多个成员调用运算符；

    有没有试过把指针掺和进结构体里面？难点。
    我们可以让指针指向结构体，这时它的地址是结构体最开始的地方；
    要通过指针引用结构体里的成员，除了用取值运算符 * 以及成员调用运算符 . 之外，还可以使用特有运算符：成员引用运算符 -> (这东西看起来就像一个指针)
    优先级         运算符         运算         结合关系         举例
    1               ->         成员引用       从左向右        p->title
    可以看到，->的优先级也是相当高的；
    ->可以用于结构体数组，只需要把它当成一般数组就行；
    结构体里面可以存储指针变量。这个不在多说；

    有没有试过把函数掺和进结构体里面？
    现阶段，我们还无法在结构体里面存储函数，不过等到升级为C++就可以了；
    只讲在函数里面调用和返回结构体的情形；
    
    函数调用结构体：参数列表里面写上结构体变量的定义即可；在主函数里面输入变量时不需要加上前缀，就像数组不需要加上[] ;
    函数返回结构体：函数类型为结构体类型，return时不需要加上struct，就像数组不需要加上[] ;
    调用或返回结构体指针也是可行的。可以在不返回值的情况下访问或修改结构体成员；

*/
//好了，说了这么多，来看一个实例，用指针和函数改写之前的代码；
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