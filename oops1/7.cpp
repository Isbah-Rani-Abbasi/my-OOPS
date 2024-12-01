// #include <iostream>
// using namespace std;
// class Example {
// private:
// int a;
// int b;
// public:
// };
// int main() {
// Example obj;
// return 0;
// }
# include<iostream>
using namespace std;
class Example
{
    private:
    int a=5;
    int b=6;
    public:
    int getter1()
    {
        return a;
    }
    int getter2()
    {
        return b;
    }
    void setter1(int num1)
    {
      a=num1;
    }
     void setter2(int num2)
    {
      b=num2;
    }
};
int main()
{
    Example e1;  //constructor call
    int num1=e1.getter1();
    int num2=e1.getter2();
    cout<<"Number 1 is "<< num1 << endl;
    cout<<"Number 2 is "<< num2 << endl;

    num1=8;
    num2=9;
     cout<<"Number 1 is "<< num1 << endl;
    cout<<"Number 2 is "<< num2 << endl;
    e1.setter1(num1);
    e1.setter2(num2);
     num2=e1.getter1();
     num1=e1.getter2();
    cout<<"Number 1 is "<< num1 << endl;
    cout<<"Number 2 is "<< num2 << endl;

    return 0;

}