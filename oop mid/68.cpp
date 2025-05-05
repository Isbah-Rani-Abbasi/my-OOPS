# include<iostream>
# include<string>
using namespace std;

template <typename T>
class Base
{
    protected:
    T b1;
    int b2;
    public:
    Base(T b1 ,int b2):b1(b1),b2(b2){}
    virtual void display()
    {
        cout<<b1<<endl<<b2<<endl;
    }
};

template <typename P>
class Child:public Base<P>
{
    protected:
    P c1;
    int c2;
    public:
    Child(P b1 ,int b2,P c1,int c2):c1(c1),c2(c2),Base<P>(b1,b2){}
     void display()override
    {
        Base<P>::display();
        cout<<this->b1<<endl<<this->b2<<endl<<c1<<endl<<c2<<endl;
    }

};
int main()
{
    Child<string>obj("isbah",2,"mana",3);
    obj.display();
}