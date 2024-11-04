## 自定义类型：结构体
在C语言中，有两大基本的数据结构；  
一个是数组，支持存储多个**相同类型**的变量；  
那么，另外一个就是存储**不同类型**的变量的数据结构，它叫**结构体**。

结构体struct由于能够存储不同类型的变量，因此形式多样，可以满足用户需要的自定义类型；

### 定义 
定义一个结构体变量需要使用struct语句。struct 语句的格式如下：
```c
struct type_name {
member_type1 member_name1;
member_type2 member_name2;
member_type3 member_name3;
.
.
} object_names;
```
**type_name** 是结构体类型的名称，  
**member_type1 member_name1** 是标准的变量定义，
>比如 int i ; 或者 float f ; 或者其他有效的变量定义。

在结构定义的末尾，**最后一个分号之前**，您可以指定一个或多个结构变量，这是**可选**的。  
具体可以看下面的例子：
```c
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book1;
```
在这个结构体里面，我们把类型名称定义为了Books；  
里面存储了字符串变量标题、作者、类目以及int变量ID；  
并顺带着指定了一个变量book1；  
等价于在main函数里面输入struct Books book1；  

>在定义结构体变量时，最好将其设置为全局变量，以便我们在整个程序中都能访问；

在定义了结构体类型之后，就可以在main函数中使用struct+结构体类型+结构体变量名称来定义结构体变量了；
>如：    **struct Books book2**

此外，我们还可以使用**typedef指令**来进一步简化结构体类型的调用；

只需要使用以下一行命令：
>typedef struct Books Books;

之后，就能**省略**结构体定义中的struct了；

### 初始化

现在我们已经**定义**了结构体类型以及结构体变量；  
那么，如何对结构体内部的若干变量进行**初始化**呢？  
在数组里面，我们可以使用[]来依次访问数组内部的各个变量；  
同理，在结构体里面，我们也有**新的运算符** . (小数点) 来进行结构体成员访问；

实际上，我们也有另一种方式来初始化一个结构体变量；
就是像数组一样，在定义的时候就**用大括号来初始化**；不过仅限于定义的时候，之后还是要用运算符来访问；

>如  Books book2= { "CSS" , "Runoob" , "front" , 12346 };

如下面的例子：(struct.c)

```c
#include <stdio.h>
#include <string.h>
struct Books //定义结构体类型Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book1;
B
typedef struct Books Books;//简化结构体变量调用
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
    
    // 输出 Book1 信息
    printf("1.title :%s\n",book1.title);
    //使用小数点提取出结构体变量里面的单个变量进行操作。
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
```
输出结果：
>1.title :C++  
1.author :Runoob  
1.subject :program  
1.ID :12345  
2.title :CSS  
2.author :Runoob  
2.subject :front  
2.ID :12346

可以看到,使用小数点可以提取出结构体变量里面的单个变量进行操作。  
事实上， . 也是一个运算符，名字叫做成员访问运算符;  
它的优先级是极高的 **( 1 )** ，甚至和括号一样；  

| 优先级 | 运算符 | 运算     | 结合关系 | 举例        |
| ------ | ------ | -------- | -------- | ----------- |
| 1      | .      | 成员访问 | 从右向左 | book1.title |

## 结构体与其它数据类型

### 结构体与数组
有没有试过把两种常见的数据结构结合起来？  
在结构体里面存储数组，这是很常见的；  
>比如书的名称里面就包含了字符数组；

在数组里面存储结构体，其实也简单，就把数组当成一个能储存不同变量的二维数组就行了；

### 结构体与自己
在结构体里面嵌套结构体，也是常规操作，当引用最底层的结构体成员时，需要使用**多个**成员调用运算符；

### 结构体与指针
有没有试过把指针掺和进结构体里面？**难点**  
我们可以让指针指向结构体，这时它的地址是结构体最开始的地方；  
要通过指针引用结构体里的成员，除了用**取值运算符** * 以及**成员调用运算符** . 之外，  
还可以使用**特有**运算符：**成员引用运算符** ->   
>(这东西看起来就像一个指针)


| 优先级 | 运算符 | 运算     | 结合关系 | 举例        |
| ------ | ------ | -------- | -------- | ----------- |
| 1      | ->     | 成员引用 | 从左向右 | p->title |

可以看到，->的优先级也是相当高的；  

->可以用于结构体数组，只需要把它当成一般数组就行；  
结构体里面可以存储指针变量。这个不在多说；


### 结构体与函数
有没有试过把函数掺和进结构体里面？  
现阶段(指C语言)，我们还无法在结构体里面存储函数；  
不过等到**升级为C++了**就可以了；
只讲在函数里面调用和返回结构体的情形；

函数**调用**结构体：参数列表里面写上结构体变量的定义即可；  
在主函数里面输入变量时不需要加上前缀，就像数组**不需要加上[]** ;  
函数返回结构体：函数类型为结构体类型，return时不需要加上struct，就像数组不需要加上[] ;  
调用或返回结构体指针也是可行的。可以在不返回值的情况下访问或修改结构体成员；

**好了，说了这么多，来看一个实例，用指针和函数改写之前的代码；**  
**( struct.c -> struct++.c )**
```c
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
```
输出结果：
>title :C++  
author :Runoob  
subject :program  
ID :12345  
title :CSS  
author :Runoob  
subject :front  
ID :12346