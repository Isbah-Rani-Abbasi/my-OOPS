# include<iostream>
# include<string>
using namespace std;

class A
{
  public:
  A(){}

  void name()
  {
    cout<<"without parameter"<<endl;
  }
   void name(string n)
  {
    cout<<"with 1 string parameter"<<endl;
  }
   virtual void name(string n, string h)
  {
    cout<<"with 2 string parameter"<<endl;
  }
  virtual void name(int r, int t)
  {
    cout<<"with 2 int parameter"<<endl;
  }
};
class B:public A
{
public:
//using A::name;
void name(string n, string h )override
{
  cout<<"child class wiht 2 string parameter"<<endl;
}
void name(int r, int t)override
  {
    cout<<"child class with 2 int parameter"<<endl;
  }

};
int main()
{
    B obj;
    obj.A::name("isbah" , "manahil");
    obj.A::name("isbah");
    A *ptr= new B();
    ptr->name("Isbah" , "rani"  );//child class
    ptr->name();//parent
    ptr->name("isbah");//parent
    ptr->name("isbah" , "rani");//chuld
    ptr->name(1,2);//child
    ptr->A::name(1,2);//parent
}