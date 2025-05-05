# include<iostream>
# include<exception>
using namespace std;

// int divide(int a ,int b)
// {
//     if(b==0)
//     {
//         throw b;
//     }
//     return a/b;
// }
int main()
{
    int a=4 , b=0;
    try
    {
        if(b==0)
        {
            throw b;
        }
        cout<<"The answer:"<<a/b<<endl;
    }
    catch(int a)
    {
        cout<<"An Error "<<a<<endl;
    }
    cout<<"hahahahaha"<<endl;
}