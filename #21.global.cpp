#include <iostream>
using namespace std;
 
// 全局变量声明
int g;
 
int main ()
{
  // 局部变量声明
  int a, b;
 
  // 实际初始化
  a = 10;
  b = 20;
  g = a + b;
 
  cout << g;
 
  return 0;
}
/*
    全局变量定义在大括号外面，因此它们在整个程序中都有效，不会消失。

    不过要注意的是，全局变量在作用域内会被同名的局部变量顶替。
*/
