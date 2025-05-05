# include<iostream>
using namespace std;

class A
{
 
  public:
  int a;
  A(int a):a(a)
  {
      
    cout<<"class A :"<<a<<endl;
  }
  
};
class B : public A
{
   
    public:
    int a;
    B(int a , int b):a(a) , A(b)
    {
        cout<<"class B"<<endl;
    }
};
class C:public A
{
  
  public:
  int a;
  C(int a , int b): a(a) , A(b)
  {
      cout<<"class C"<<endl;
  }
};
class D: public C ,public B
{
  public:
  int c;
  D(int a , int b ,int c):c(c) ,C(a,b) ,B(a,b)
  {
      cout<<"class D"<<endl;
  }
  void print()
  {
    cout<<"class C"<<C::a<<endl;
    cout<<"class B"<<B::a<<endl;
    cout<<"class D"<<c<<endl;
  }

};
int main()
{
    D obj(2,3,4);
    obj.print();
}