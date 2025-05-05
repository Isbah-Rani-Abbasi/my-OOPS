# include<iostream>
using namespace std;

class A
{
 
  public:
  int a;
  A()
  {
   
  }
  A(int a):a(a)
  {
      
    cout<<"class A "<<endl;
  }
  
};
class B : public A
{
   
    public:
    int b;
    B(int a  , int b):b(a) , A(b) 
    {
        cout<<"class B"<<endl;
    }
};
class C: public B
{
  
  public:
  int c;
  C(int a , int b ,int c ): c(a) ,B(b , c) 
  {
      cout<<"class C"<<endl;
  }
};
class D: public C 
{
  public:
  int d;
  D(int a , int b ,int c , int d):d(a) ,C(b,c,d)
  {
      cout<<"class D"<<endl;
  }
  void print()
  {
    cout<<"class A "<<a<<endl;
    cout<<"class B "<<b<<endl;
    cout<<"class C "<<c<<endl;
    cout<<"class D "<<d<<endl;
  }

};
int main()
{
    D obj(1,2,3,4);
    obj.print();
}