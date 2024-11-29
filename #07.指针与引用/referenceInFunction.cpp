#include <iostream>
using namespace std;
int num[5]={1, 2, 3, 4, 5};

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