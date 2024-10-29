/*
    在C++中还有一种与指针类似的变量，名叫引用；
	引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。
	一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。

    引用变量的定义方式为加上&；
	即		int &r = i；
*/
//具体可以看下面的例子：
#include <iostream>
using namespace std;

int num[5]={1,2,3,4,5};     //数组num是全局变量，可以直接在函数调用；

int& f(int i)
{
    int &a=num[i];
    return a;
}

int* g(int i)
{
    int *a=&num[i];
    return a;
}

int& h(void)
{
    int i=666;
    return i;
}

int main()
{
    // 声明简单的变量
    int    i;
    double d;
    
    // 声明引用变量
    int&    r = i;
    double& s = d;
    
    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r  << endl;
    
    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s  << endl;
    /*
        运行输出：
        Value of i : 5
        Value of i reference : 5
        Value of d : 11.7
        Value of d reference : 11.7
        在这里我们能体会到，引用其实就是变量的另一个名字；
    */
    

/*
	引用很容易与指针混淆，它们之间有三个主要的不同：

	不存在空引用。引用必须连接到一块合法的内存。而指针可以指向空地址NULL；

	一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。（除非是const指针）
    int&    r = i;
    r=j             //错误！          

	引用必须在创建时被初始化。指针可以在任何时间被初始化；
*/

/*
    还有一个重要的点，就是指针和引用不仅可以作为函数参数引进，还可以作为返回值输出；
    而函数返回的引用可以直接作为左值做赋值运算；但指针不行；
    相应地，函数的变量名称要设置成 int* 或 int& ；
*/
//如下面的例子：

    cout << "改变前的值" << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "num[" << i << "] = ";
        cout << num[i] << endl;
    }

    f(0)=114;
    f(2)=514;

    cout << "改变后的值" << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "num[" << i << "] = ";
        cout << num[i] << endl;
    }

    // g(0)=114;
    // g(2)=514;

    // cout << "改变后的值" << endl;
    // for ( int i = 0; i < 5; i++ )
    // {
    //     cout << "num[" << i << "] = ";
    //     cout << num[i] << endl;
    // }

/*
    可以看到，返回引用的函数能正常运行，但是返回指针的函数（上面的注释）却不行；
    究其原因，是因为当函数返回一个引用时，则返回一个指向返回值的隐式指针。这样，函数就可以放在赋值语句的左边。

    但引用也有它的不足之处，就是不能返回局部变量的引用；
    编译时会出现警告，运行时会出现段错误（Segmentation fault）；
*/
    // int n=h();
    // cout<<"reference:"<<n<<endl;
    //上述代码是执行不了的；但是如果把函数里面的i改成全局变量，就没问题；
    return 0;
}