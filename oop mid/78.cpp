# include<iostream>
# include<string>
using namespace std;

class A
{
    private:
    int a;
    int b;
    int c;
    public:
    A(int a, int b, int c):a(a),b(b),c(c){}
    A(){
        a=0;
        b=0;
        c=0;
    }

    A operator+(A & obj)
    {
        A obj1;
        obj1.a=a+obj.a;
        obj1.b=b+obj.b;
        obj1.c=c+obj.c;
        return obj;
    }

    void operator+(int i)
    {
        a=a+i;
        b=b+i;
        c=c+i;
    }

    void operator=(int i )
    {
        a=i;
        b=i;
        c=i;
    }
    friend ostream & operator<<(ostream & out , A &obj);
    friend istream & operator>>(istream & in , A &obj);
    
    
};
ostream & operator<<(ostream & out , A & obj)
{
    out<<obj.a<<endl<<obj.b<<endl<<obj.c<<endl;
    return out;
}

istream & operator>>(istream & in , A  &obj)
{
    in>>obj.a>>obj.b>>obj.c;
    return in;
}
int main()
{
    A obj;
    A obj2;
    obj+2;
    cout<<obj;
    obj2=7;
    cout<<obj2;
    cin>>obj;
    cout<<obj;
}