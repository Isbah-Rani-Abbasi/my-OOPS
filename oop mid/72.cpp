# include<iostream>
# include<string>
using namespace std;

class Shape
{
    public:
    virtual void getArea()=0;
};
class Rectangle:public Shape
{
   private:
   int l;int b;
   public:
   Rectangle(int l ,int b):l(l),b(b){}
   void getArea()override
   {
    cout<<"Area of Rectangle: "<<l*b<<endl;
   }
};

class Circle:public Shape
{
   private:
   int r;
   public:
   Circle(int r):r(r){}
   void getArea()override
   {
    cout<<"Area of Circle: "<<3.14*r*r<<endl;
   }
};
int main()

{
    Shape *s;
    Circle c(2);
    Rectangle r(2,2);
    s=&c;
    s->getArea();
    s=&r;
    s->getArea();
}