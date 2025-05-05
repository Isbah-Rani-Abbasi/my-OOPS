// Write a C++ Program of templated class derived from another templated class.
// Consider two classes one base class with two variables and another derived class with
// two variables multiply the values in the classes and print their outputs respectively. (The
// template classes must inherit from each other)

# include<iostream>
# include<string>
using namespace std;

template <typename T>
class Base
{
  protected:
  T b1;
  T b2;
  public:
  Base(T b1 , T b2):b1(b1),b2(b2){}
  virtual void display()
  {
    cout<<b1+b2<<endl;
  }
};

template <typename P>
class Child :public Base<P>
{
 private:
 P c1;
 P c2;
 public:
 Child(P c1, P c2, P b1, P b2):Base<P>(b1,b2),c1(c1),c2(c2){}
 void display() override
 {
    Base<P>::display();
   cout<<this->b1+this->b2+c1+c2<<endl;
 }
};
int main()
{
    Child<int>obj(1,2,3,4);
    Base<int>*ptr;
    Base<int>obj2(3,3);
    obj2.display();
    ptr=&obj;
    obj.display();
    ptr->display();
}