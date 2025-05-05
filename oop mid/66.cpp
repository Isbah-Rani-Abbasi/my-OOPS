# include<iostream>
# include<string>
# include<exception>
using namespace std;

template<typename t>
class A
{
    public:
 t *p;
 int size;
 
 A(int s)
 {
   size=s;
   p=new t[size];
 }
 void setelement(t e)
 {
    
   for(int i=0 ;i<size;i++)
   {
    p[i]=e;
   }
 }
 t operator[](int index)const
 {
    cout<<"hello i am constatnt"<<endl;
    if(index<0)
    {
        throw runtime_error{"Arrayoutofbound"};
    }
    else{
        return p[index];
    }
 }
 t operator[](int index)
 {
    
    if(index<0)
    {
        throw runtime_error{"Arrayoutofbound"};
    }
    else{
        return p[index];
    }
 }
 template<typename p>
 void operator +(p  i)
 {
    size=size+i;
 }
 template <typename u>
 friend ostream & operator<<(ostream &out,const A<u> &obj);
};

template <typename u>
 ostream & operator<<(ostream &out,const A<u> &obj)
{
    for(int i=0 ;i<obj.size;i++)
    {
        cout<<obj.p[i]<<endl;
    }
}
int main()
{
    A<string> obj(3);
    A<int> obj1(3);
    obj1.setelement(3);
    cout<<obj1;
    obj1+'s';
    cout<<obj1.size<<endl;
    obj.setelement("sdasd");
    cout<<obj;

    try
    {
        cout<<obj[1]<<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}