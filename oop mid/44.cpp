# include<iostream>
# include<string>
using namespace std;

class A
{
    int a;
    float b;
   
    public:
    A()
    {

    }
    A(int a ,float b):a(a),b(b)
    {
    }
    A operator +(A &obj)
    {
        A obj2;
        obj2.a=a+obj.a;
        obj2.b=b+obj.b;                                     // A member function of a class can access private members of any object of the same class.
       
       
        return obj2;

    }
    friend ostream& operator <<(ostream & out,A &obj);
    friend A operator +(int i ,A & obj);
    A operator ++()                                      // pre increment
    {
        a++;
        b++;
        return A(a,b);
    }
    A operator ++(int)
    {
      A obj=*this;
      a++;
      b++;
      return obj;
    }
    bool operator ==(A & obj)
    {
        return (a==obj.a && b==obj.b);
    }
};
ostream& operator <<(ostream & out , A &obj)
{
    out<<"A:"<<obj.a<<endl<<"B:"<<obj.b<<endl;
    return out;
}
A operator +(int i ,A & obj)
{
    return A(i+obj.a , i+obj.b);
}
int main()
{
   
    A obj1(1,2.4) ,obj2{1,2.6} ,obj3 ,obj4 , obj5;
    obj3 = obj1+obj2;
    cout<<obj3;
    obj4=++obj3;
    cout<<obj4;
    obj5=obj3++;
    cout<<obj5;
    cout<<obj3;
    if(obj4==obj5)
    {
        cout<<"equal"<<endl;
    }
    else{
        cout<<"Unequal"<<endl;
    }
    obj5 = 2+obj3;
    cout<<obj5;
}