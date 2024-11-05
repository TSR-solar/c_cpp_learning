#include <iostream>
using namespace std;
int main()
{
    string str1="hello";
    string str2="world";
    string str3={0};
    int len;

    str3=str1;
    cout<<"str3: "<<str3<<endl;

    str1+=str2;
    cout<<"str1+str2= "<<str1<<endl;

    len=str1.length();
    cout<<"the length of str1: "<<len<<endl;

    return 0;
}
