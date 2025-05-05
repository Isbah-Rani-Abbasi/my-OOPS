# include<iostream>
# include<string>
using namespace std;

class A
{
 private:
 int a,b;
 public:
 A()
 {

 }
 A(int a,int b):a(a),b(b){}


 A operator -(A &obj)
 {
    return A(a-obj.a ,b-obj.b);
 }
 
 A operator ++(int)
 {
    A obj =*this;
    obj.a++;
    obj.b++;
    return obj;
 }
 friend A operator +(int i, A &obj);
 friend ostream & operator <<(ostream & out , A & obj);
 friend istream & operator>>(istream & in , A &obj);

 A operator +(int i)
 {
    cout<<"Memebr func"<<endl;
    return A(a+i ,b+i);
 }
 
};
istream & operator>>(istream & in , A &obj)
 {
    in>>obj.a;
    in>>obj.b;
    return in;
 }

 ostream & operator <<(ostream & out , A & obj)
 {
    out<<obj.a<<endl<<obj.b<<endl;
    return out;
 }

 A operator +(int i, A &obj)
 {
    cout<<"friend function"<<endl;
    return A(i+obj.a,i+obj.b);
 }
 
 int main()
 {
    A obj1(0,0) , obj2(2,1) ,obj3 ,obj4 , obj5 ;

    obj3 = obj1-obj2;
    cout<<obj3;
    obj4=obj3++;
    cout<<obj3<<obj4;
    cin>>obj4;
    cout<<obj4;
    obj5=2+obj3+9;
    cout<<obj5;

    
 }