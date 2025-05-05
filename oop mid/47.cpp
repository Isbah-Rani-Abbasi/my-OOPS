
# include<iostream>
# include<string>
using namespace std;
class A
{
    public:
    void display()
    {
        cout<<"non constant"<<endl;
    }
    void display()const
    {
        cout<<"constant function"<<endl;
    }
};
int main()
{
    const A obj;
    obj.display();
    A obj1;
    obj1.display();
}