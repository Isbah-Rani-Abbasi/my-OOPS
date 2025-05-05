# include<iostream>
using namespace std;

class A
{
 
  public:
  int g;
  A()
  {

  }
  A(int a):g(a)
  {
      
    cout<<"class A "<<endl;
  }
  
};
class B :virtual public A
{
   
    public:
    int a;
    B(int a ):a(a) 
    {
        cout<<"class B"<<endl;
    }
};
class C:virtual public A
{
  
  public:
  int a;
  C(int a ): a(a) 
  {
      cout<<"class C"<<endl;
  }
};
class D: public C ,public B
{
  public:
  int c;
  D(int a , int b ,int c):c(a) ,C(b) ,B(b),A(c)
  {
      cout<<"class D"<<endl;
  }
  void print()
  {
    cout<<"class A "<<g<<endl;
    cout<<"class C "<<C::a<<endl;
    cout<<"class B "<<B::a<<endl;
    cout<<"class D "<<c<<endl;
  }

};
int main()
{
    D obj(2,3,4);
    obj.print();
}