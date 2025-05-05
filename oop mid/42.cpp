# include<iostream>
# include<string>
using namespace std;
class B;
class A
{
    int a;
    int b;
    void func()
    {
        cout<<"Hello World"<<endl;
    }
    friend class B;
    public:
    void print()
    {
        cout<<"class A a:"<<a<<endl<<"class A b:"<<b<<endl;
    }
};

class B
{
   private:
    void accessA(A &obj)
    {
        obj.a=20;
        obj.b=30;
        obj.func();
        cout<<"class B a:"<<obj.a<<endl<<"class B b:"<<obj.b<<endl;
    }
    friend void accessB(B &obj1);
};

void accessB(B &obj1)
{
   A obj;
   obj1.accessA(obj);
}
int main()
{
    B objb;
    A obja;
    //objb.accessA(obja);
    accessB(objb);
  

    
}