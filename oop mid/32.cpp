# include<iostream>
# include<string>
using namespace std;

class A
{
    public:
    A()
    {
        cout<<"class A"<<endl;
    }
    ~A()
    {
        cout<<"class A destroyed"<<endl;
    }
};
class B:public A
{
    public:
    B() : A()
    {
        cout<<"class B"<<endl;
    }
    ~B()
    {
        cout<<"class B destroyed"<<endl;
    }
};
class C:public B
{
    public:
    C():B() //, A()
    {
        cout<<"class C"<<endl;
    }
    ~C()
    {
        cout<<"class C destroyed"<<endl;
    }
};
int main()
{
    C obj;
}