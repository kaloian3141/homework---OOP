#include<iostream>
#include<execution>
using namespace std;

int f1(int v)
{
    if(v<=0)
    {
        throw invalid_argument("v must be >0");
        return -1;
    }
    return v;
}

class A{

    const int a;
    int *b;
    public:
    A(int a1)
    :a(a1), b(new int[a1])
    {
        //this->a = a;
    }   
    int getA() const
    {
        return this->a;
    }
};

int main()
{
    try{
        f1(-2);
    }
    catch(exception& e)
    {
        cout << e.what() <<endl;
    }
    const int *arr = new int[2];
    arr = new int[5];
    //arr[0] = 5;   Error
    int * const arr1 =  new int[2];
    //arr1 = new int[5]; Error
    arr1[0] = 4;
    const int * const arr2 = new int[2];
    //arr2 = new int[6];    Error
    //arr2[0] = 1;      Error
    A a(4);
    cout << a.getA()<< endl;
    return 0;

}