# include<iostream>
# include<string>
using namespace std;

class A
{
    int a;
    float b;
    string carr[10];
    int size;
    public:
    A()
    {

    }
    A(int a ,float b, int s,string arr[]):a(a),b(b),size(s)
    {
        for(int i=0;i<size;i++)
        {
          carr[i]=arr[i];
        }
    }
    A operator +(A &obj)
    {
        A obj2;
        obj2.a=a+obj.a;
        obj2.b=b+obj.b;                                     // A member function of a class can access private members of any object of the same class.
        obj2.size=size+obj.size;
        int k=0;
        for(int i=0 ;i<size;i++)
        {
            obj2.carr[i]=carr[i];
        }
        for(int i=size ;i<obj.size+size;i++)
        {
           obj2.carr[i]=obj.carr[k];
           k++;
        }
        return obj2;

    }
    friend ostream operator <<(ostream & out,A &obj);
    A operator ++()
    {
        a++;
        b++;
        size++;
    
    }
};
ostream operator <<(ostream &out , A &obj)
{
    out<<"A:"<<obj.a<<endl<<"B:"<<obj.b<<endl<<"Size:"<<obj.size<<endl;
    for(int i=0 ;i<obj.size;i++)
    {
        out<<obj.carr[i]<<endl;
    }
}
int main()
{
    string arr[3]={"isbah","rani","abbasi"};
    string arr1[2]={"faris","ghazi"};
    A obj1(1,2.4,3,arr) ,obj2{1,2.6,2,arr1} ,obj3;
    obj3 = obj1+obj2;
    cout<<obj3;
}