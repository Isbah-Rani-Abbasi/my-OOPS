# include<iostream>
# include<exception>
using namespace std;

int divide(int a ,int b)
{  
    try
    {
       if(b==0)
       {
        throw b;
       }
        
    }
    catch(int a)
    {
        cout<<"An Error"<<a<<endl;
    }
   

    return a/b;
}
int main()
{
    int a=4 , b=0;
    try
    {
        int r=divide(4,0);
        cout<<"The answer:"<<r<<endl;
    }
    catch(int a)
    {
        cout<<"An Error"<<a<<endl;
    }
}