#include <iostream>

using namespace std;

class A
{
private:
    int a;
public:
    A()
    {
        a = 2;
    }
    A(int val)
    {
        a = val;
    }   
    int func1()
    {
        return 0;
    }

};

int main()
{
    A a;
    cout << a.func1() << endl;
}