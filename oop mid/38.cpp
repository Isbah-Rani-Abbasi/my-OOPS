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
  void name(int r, int t)
  {
    cout<<"with 2 int parameter"<<endl;
  }
};
class B:public A
{
public:
using A::name;
void name(string h, string j )override
{
  cout<<"child class wiht 2 string parameter"<<endl;
}

};
int main()
{
    B obj;
    obj.A::name("Isbah" , "rani"  );
    obj.name();
    obj.name("isbah");
    obj.name("isbah" , "rani");
    obj.name(1,2);
}