/*
    现在学了C++；因此字符串可以用两种形式表示；即：
    C 风格字符串
    C++ 引入的 string 类类型；
*/

/*
    C风格字符串即字符数组char[]，但是在最后有空字符'\0';
    由于在数组的末尾存储了空字符，所以字符数组的大小比字符串的字符数多一个。

    字符串除了像数组一样定义，还可以用双引号字符串定义。
    下面是两种定义方式：
    char site[6] = {'H', 'E', 'L', 'L', 'O' '\0'};
    char site[] = "HELLO";
    注意到，双引号定义的字符串无需加上后置的空字符，因为它本身就是字符串，而不是相互独立的字符数组；
*/

/*
    有大量的函数用来操作以 null 结尾的字符串（需要头文件<string.h>或<cstring>)，具体有以下几个：

    #1.strcpy(s1, s2)：复制
    复制字符串 s2 到字符串 s1。
    #2.strcat(s1, s2)：连接
    连接字符串 s2 到字符串 s1 的末尾。
    #3.strlen(s1)：    长度
    返回字符串 s1 的长度。
    #4.strcmp(s1, s2)：比较
    如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。
        这里比较的是字符串中第一个字符的ASCII编码，而非整个字符串。
        若不相等，返回的是两个字符的编码差值；
    #5.strchr(s1, ch)：查找字符
    返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
    #6.strstr(s1, s2)：查找字符串
    返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。
*/
//以下是一些字符串函数的实例：
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str1[13]="hello";
    char str2[13]="world";
    char str3[13];
    int len;

    // 复制 str1 到 str3
    strcpy( str3, str1);
    cout << "strcpy( str3, str1) : " << str3 << endl;
    //如果想用printf输出字符串的话，用%s；
    //比如，上面那一行可以替换成 printf("strcpy(str3,str1)")
    
    // 连接 str1 和 str2
    strcat( str1, str2);
    cout << "strcat( str1, str2): " << str1 << endl;
    
    // 连接后，str1 的总长度
    len = strlen(str1);
    cout << "strlen(str1) : " << len << endl;

    /*
        运行后的输出结果：
        strcpy( str3, str1) : hello
        strcat( str1, str2): helloworld
        strlen(str1) : 10
    */

/*
    除此之外，就是C++特有的string类型字符串（需要iostream头文件）
    string类型的字符串兼容C风格的字符串功能，同时还可以做赋值和四则运算。而且不需要初始化字符串的长度；
    这是C风格的字符串所做不到的；
*/   
//如下面的例子：
    string str4="hello";
    string str5="world";
    string str6;
    int l;

    // 复制 str4 到 str6
    str6 = str4;
    cout << "str6 : " << str6 << endl;
    
    // 连接 str1 和 str2
    str6 = str4 + str5;
    cout << "str4 + str5 : " << str6 << endl;
    
    // 连接后，str3 的总长度
    len = str6.size();
    cout << "str6.size() :  " << len << endl;
    
    /*
        输出结果：
        str6 : hello
        str4 + str5 : helloworld
        str6.size() :  10
    */
   
    return 0;
}
