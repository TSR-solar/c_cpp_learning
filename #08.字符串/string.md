## C风格字符串
C风格字符串即字符数组char[]，但是在最后有**空字符'\0'**;  
由于在数组的末尾存储了空字符，所以字符数组的大小比字符串的字符数多一个。

字符串除了像数组一样定义，还可以用双引号字符串定义。  
下面是两种定义方式：  
>char site[6] = {'H', 'E', 'L', 'L', 'O' '\0'};
char site[] = "HELLO";

注意到，双引号定义的字符串无需加上后置的空字符，因为它本身就是字符串，而不是相互独立的字符数组；

有大量的函数用来操作字符串；
(需要头文件<string.h>或< string>)  
具体有以下几个：

1. **strcpy(s1, s2)**：复制    
   复制字符串 s2 到字符串 s1。
2. **strcat(s1, s2)**：连接  
   连接字符串 s2 到字符串 s1 的末尾。
3. **strlen(s1)**：    长度  
   返回字符串 s1 的长度。
4. **strcmp(s1, s2)**：比较  
  如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；     
  如果 s1>s2 则返回值大于 0。

>这里比较的是字符串中第一个字符的ASCII编码，而非整个字符串。  
若不相等，返回的是两个字符的编码差值；

5. strchr(s1, ch)：查找字符  
   返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。

6. strstr(s1, s2)：查找字符串
   返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。   

以下是一些字符串函数的实例：(string.c)
```c
#include <stdio.h>
#include <string.h>
int main()
{
    //用字符串初始化字符数组
    char str1[13]="hello";  
    //等价于    char str1[13]={'h','e','l'.'l','o','\0'};
    char str2[13]="world";
    char str3[13]={0};
    int len;//定义整型变量以记录字符串长度

    //将str1复制到str3
    strcpy(str3,str1);
    printf("strcpy(str3,str1): %s\n",str3);

    //将str2连接到str1后面
    strcat(str1,str2);
    printf("strcat(str1,str2): %s\n",str1);

    //输出连接后的str1字符串长度
    len=strlen(str1);
    printf("strlen(str1): %d\n",len);
    
    return 0;
}
```
输出结果：
>strcpy(str3,str1): hello  
strcat(str1,str2): helloworld  
strlen(str1): 10

## C++风格的字符串
学了C++以后；字符串可以用**两种形式**表示；即：  
#### C 风格字符串  
#### C++ 引入的 类 string ；

如你所见，C++风格的字符串是一个**类**；  
它保存在命名空间**std**里面；里面包含许多**成员函数**和**运算符重载操作**；  
可以代替部分string头文件里面的函数；

string类型的字符串**兼容**C风格的字符串功能，而且**不需要初始化字符串的长度**，同时还可以做**赋值**和**四则运算** (重载 + - =)  
这是C风格的字符串所**做不到**的；

接下来让我们用C++风格的字符串来改写一下上面的代码，看一看它的简便之处；(string.c -> string++.cpp)
```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
   //使用类string来定义字符串变量
   string str1="hello";
   string str2="world";
   string str3={0};
   int len;

   //在类的内部进行了运算符的重载，可以直接使用 = 来进行 strcpy()
   str3=str1;
   cout<<"str3: "<<str3<<endl;

   //用 + 进行 strcat() "+=也可以接受哦"
   str1+=str2;
   cout<<"str1+str2= "<<str1<<endl;

   //使用string类里面的成员函数length来提取长度;
   len=str1.length();
   cout<<"the length of str1: "<<len<<endl;

   return 0;
}
```
