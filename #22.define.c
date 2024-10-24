/*
    #define 是宏，可以将代码中所有与预处理变量相同的式子换为处理后的式子。
    为避免混淆，宏定义的常量也用大写字母表示;
    如果要取消怎么办？使用#undef即可。取消之后就可以对宏进行重新定义，否则宏不能重复定义；
    宏定义可以使代码变得更加简洁可读；
*/
//如下面的例子：
#include <stdio.h>
 
#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'
 
int main()
{
 
   int area;  
   
   area = LENGTH * WIDTH;
   printf("%dNEWLINE",area);
   return 0;
}
/*
    需要注意的是，#define只能简单粗暴的做替换工作，不能运算。
    如果#define A 3+2；
    那么 2*A 的结果就会是8而不是10.
    因为实际上代码被替换为了 2*3+2 而不是 2*(3+2);
    勤加括号可以避免这一类问题的出现。
*/

/*

*/