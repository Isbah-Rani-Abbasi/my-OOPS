# include<iostream>
# include<string>
using namespace std;
class car
{
    private:
    mutable int hp;
    mutable int c;
    mutable int s;
    int g;
    public:
    car():hp(0) ,c(0) ,s(0){}
    void change(int a, int b, int d)const
    {
      hp=a;
      c=b;
      s=d;
      //g=a;
    }
     void display()const
    {
        cout<<"Horse power:"<<hp<<endl;
        cout<<"Capacity:"<<c<<endl;
        cout<<"Speaker:"<<s<<endl;
    }
};
int main()
{
    car c;
    c.change(10,20,30);
    c.display();
}