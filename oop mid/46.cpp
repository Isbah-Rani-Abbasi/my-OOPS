# include<iostream>
# include<string>
using namespace std;

class A
{
    
    public:
    int a;
    A(int a):a(a){}
};
class B:public A
{
  public:
  int b;
  B(int b , int a):b(b),A(a){}
};
class C:public A
{
    public:
  int c;
  C(int a ,int c):c(c),A(a){}
};
class D:public B,public C
{
    public:
    int d;
    D(int d , int b ,int c,int a1 , int a2):d(d),B(b,a1),C(c,a2){}
};

int main()
{
    D d(1,2,3,4,5);
    cout<<d.B::a<<endl;

}