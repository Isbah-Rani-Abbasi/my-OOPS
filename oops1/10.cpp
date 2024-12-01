// Write a C++ program that detects if a number entered by the user is even or odd
// using Object-Oriented Programming.
# include<iostream>
using namespace std;
class Check
{
    public:
    void find(int a)
    {
        if(a%2==0)
        {
            cout<< a << " is even number! ";
        }
        else
        {
           cout << a << " is odd number! ";
        }
    }
};
int main()
{
    Check obj;
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    obj.find(num);
    return 0;

}
