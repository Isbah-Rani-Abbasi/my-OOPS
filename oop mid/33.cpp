// default values in function and constructor
# include<iostream>
# include<string>
using namespace std;

class A
{
    int a , b ,c;
    public:
    A()
    {
        cout<<"Default"<<endl;
    }
    A(int a , int b ,int c=30): a(a),b(b),c(c)
    {
        cout<<"class A"<<endl;
    }
    void hello(string name , string name2="world")
    {
        cout<<name<<" "<<name2<<endl;
    }
    void print()
    {
        cout<<"A:"<<a<<endl<<"B:"<<b<<endl<<"C:"<<c<<endl;
    }
    ~A()
    {
        cout<<"class A destroyed"<<endl;
    }
};

int main()
{
    A obj(2,6);
    obj.print();
    obj.hello("hello");
}