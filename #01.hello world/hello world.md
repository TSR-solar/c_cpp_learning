## 最基础的C程序
```c
#include <stdio.h>
int main()
{
    printf("Hello World\n");
    return 0;
}
```
**stdio.h**是C中掌管输入输出的头文件，必须要 **#include**它才能实现后续的输出操作；     
**main**是主函数，用来执行你的代码操作；    
**printf**是C语言的标准输出函数，它可以向你的屏幕打印 *hello world*；
## 最基础的C++程序
```cpp
#include <iostream>
using namespace std;
int main()
{
    cout <<"Hello World\n";
    return 0;
}
```
iostream是c++的头文件;  
还想用C的头文件的话就只能在前面加“c”(不用加.h); 
如stdio.h变成cstdio；   
std是标准命名空间，包含大量基本函数。**不同命名空间的函数定义是不一样的。**     
cout可以被认为是C++里的printf，加上<<即可。