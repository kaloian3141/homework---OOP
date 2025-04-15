#include<iostream>

using namespace std;

class Parent
{
    int a;
    int b;
    int c;
    public:
    Parent(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    
    int getA()
    {
        return this->a;
    }

    int getB()
    {
        return this->b;
    }

    int getC()
    {
        return this->c;
    }

    protected:
    int getSum()
    {
        return this->a + this->b + this->c;
    }

};

class Child: public Parent
{
    int d;

    public:
    Child(int a, int b, int c, int d)
    :Parent(a,b,c)
    {
        this->d = d;
    }
    int foo()
    {
        return getSum()/this->d;
    }
    protected:
    int getSum1()
    {
        return getSum() + this->d;
    }
};

class GrandChild: public Child
{
    int e;
    int f;
    public:
    GrandChild(int a, int b, int c, int d, int e, int f)
    :Child(a,b,c,d)
    {
        this->e = e;
        this->f = f;
    }
    int foo2()
    {
        return foo() + this->e / this->f;
    }
    int pSum()
    {
        return getSum1() + this->e + this->f;
    }
    protected:
    int getSum3()
    {
        return getSum() + getSum1() + this->e + this->f;
    }

};

int main()
{
    Parent * a = new Parent(1,2,3);
    cout << a->getA() <<endl;
    cout << a->getB() <<endl;
    cout << a->getC() <<endl << endl;
    Child * b = new Child(3,5,6,7);
    cout << b->getA() <<endl;
    cout << b->getB() <<endl;
    cout << b->getC() <<endl;
    cout << b->foo()  <<endl << endl;
    GrandChild * c = new GrandChild(8,5,2,1,6,1);
    cout << c->getA() <<endl;
    cout << c->getB() <<endl;
    cout << c->getC() <<endl;
    cout << c->foo()  <<endl;
    cout << c->foo2()  <<endl;
    cout << c->pSum()  <<endl;

}