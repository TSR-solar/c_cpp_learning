## 引用：变量的别名
在C++中还有一种与指针类似的变量，名叫**引用**；  
引用变量是一个**别名**，也就是说，它是某个已存在变量的**另一个名字**。  
一旦把引用初始化为某个变量，就可以使用**该引用名称**或变量名称来指向变量。

引用变量的定义方式为加上&；  
即 `int &r = i`；

具体可以看下面的例子：(reference.cpp) 
```c++
#include <iostream>
using namespace std;
int main()
{
    int i;
    double d;
    int &r = i;
    double &s = d;

    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r  << endl; 

    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s  << endl;   
    return 0;
}
```

运行输出：  
>Value of i : 5  
Value of i reference : 5  
Value of d : 11.7  
Value of d reference : 11.7 

在这里我们能体会到，引用其实就是变量的另一个名字；

## 引用 VS 指针
引用很容易与指针混淆，它们之间有三个主要的不同：

1. 引用必须在**创建时被初始化**。  
指针没有此限定；
```c++
int &r;        //错误
int *p;        //正确
```

2. 不存在空引用。引用必须连接到一块**合法的内存**。  
而指针可以指向**空地址NULL**；  

3. 一旦引用被初始化为一个对象，就**不能被指向到另一个对象**。  
而指针可以在**任何时候**指向到另一个对象。（除非是const指针）  
```c++
int &r = i;
r=j;          //错误
int *p = &i;
*p = j;       //正确
```          
    
## 引用和函数

引用和指针一样都可以作为函数形参；  
但不同的是，引用不仅可以作为函数参数引进，还可以作为返回值输出,  
但是指针不能作为左值被赋值；    
此时，函数类型为 int& ;  

如下面的例子：(referenceInFunction.cpp)

```c++
#include <iostream>
using namespace std;
int num[5]={1, 2, 3, 4, 5}; // 设置全局变量

int& changeInFunction(int i)
{
    int &a=num[i];
    return a;
}

int main()
{
    cout << "former:" << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "num[" << i << "] = ";
        cout << num[i] << endl;
    }

    changeInFunction(0)=114;
    changeInFunction(2)=514;

    cout << "after:" << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "num[" << i << "] = ";
        cout << num[i] << endl;
    }
    return 0;
}
```
输出结果：
>former:  
num[0] = 1  
num[1] = 2  
num[2] = 3  
num[3] = 4  
num[4] = 5  
after:  
num[0] = 114  
num[1] = 2  
num[2] = 514  
num[3] = 4  
num[4] = 5  

可以看到，返回引用的函数能正常运行，但是返回指针的函数（上面的注释）却不行；  
比如，把上面函数 changeInFunction 的定义改成：
```c++
int *p=&num[i];
return p;
```
则会发生错误；

究其原因，是因为当函数返回一个引用时，则返回一个指向返回值的**隐式指针**。  
这样，函数就可以放在赋值语句的左边。  

但引用也有它的不足之处，就是不能返回局部变量的引用；
编译时会出现警告，运行时会出现段错误（Segmentation fault）；

比如，设计下面一个函数：
```c++
int& Function()
{
    int i=666;
    return i;
}
```

上述代码是执行不了的；但是如果把函数里面的i改成全局变量，就没问题；