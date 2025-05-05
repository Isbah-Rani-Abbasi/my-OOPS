# include<iostream>
# include<exception>
using namespace std;

int divide(int a ,int b)
{
    if(b==0)
    {
        throw b;
        cout<<"hahahaha"<<endl;   //never executed
    }
    
    return a/b;
}
int main()
{
    int a=4 , b=1;
    try
    {
        int r=divide(a,b);
        cout<<"The answer:"<<r<<endl;
    }
    catch(int a)
    {
        cout<<"An Error"<<a<<endl;
    }
}