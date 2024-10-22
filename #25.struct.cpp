/*
    在C语言中，有两大基本的数据结构；
    一个是数组，支持存储多个相同类型的变量；
    那么，另外一个就是存储不同类型的变量的数据结构，它叫结构体。

    结构体struct由于能够存储不同类型的变量，因此形式多样，可以满足用户需要的自定义类型；
    定义一个结构体变量需要使用struct语句。struct 语句的格式如下：

    struct type_name {
    member_type1 member_name1;
    member_type2 member_name2;
    member_type3 member_name3;
    .
    .
    } object_names;
    type_name 是结构体类型的名称，
    member_type1 member_name1 是标准的变量定义，比如 int i; 或者 float f; 或者其他有效的变量定义。
    在结构定义的末尾，最后一个分号之前，您可以指定一个或多个结构变量，这是可选的。

    定义完成之后，你便可以使用结构体类型名称像平常定义变量一样定义结构体变量，
    当然，你也可以在定义结构体时就顺带的指定几个结构体变量。
*/
//具体可以看下面的例子：
#include <stdio.h>
#include <cstring>
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book1;
/*
    在这个结构体里面，我们把类型名称定义为了Books；
    里面存储了字符串变量标题、作者、类目以及int变量ID；
    并顺带着指定了一个变量book1；
    等价于在main函数里面输入Books book1；

    在定义结构体变量时，最好将其设置为全局变量，以便我们在整个程序中都能访问；

    现在我们已经定义了结构体类型以及结构体变量；那么，如何对结构体内部的若干变量进行赋值呢？
    在数组里面，我们可以使用[]来依次访问数组内部的各个变量；
    同理，在结构体里面，我们也有新的运算符 . 来进行结构体成员访问；
*/
//如下面的例子：
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
    book1.book_id = 12346;
    /*
        可以看到，使用小数点可以提取出结构体变量里面的单个变量进行操作。
        事实上， . 也是一个运算符，名字叫做成员访问运算符，它的优先级是极高的，甚至和括号一样；
        优先级         运算符         运算         结合关系         举例
          1             .           成员访问      从右向左      book1.title
    */

    // 输出 Book1 信息
    printf("1.title :%s\n",book1.title);
    printf("1.author :%s\n",book1.author);
    printf("1.subject :%s\n",book1.subject);
    printf("1.ID :%d\n",book1.book_id);

    // 输出 Book2 信息
    printf("2.title :%s\n",book2.title);
    printf("2.author :%s\n",book2.author);
    printf("2.subject :%s\n",book2.subject);
    printf("2.ID :%d\n",book2.book_id);
    return 0;
}