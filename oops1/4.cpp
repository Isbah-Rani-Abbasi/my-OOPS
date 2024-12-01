#include <iostream>
// using namespace std;
// int factorial(int n) {
// if (n == 0 || n == 1) {
// return 1;
// } else {
// return n * factorial(n - 1);
// }
// }
// int main() {
// int number;
// cout << "Enter a number: ";
// cin >> number;
// if (number < 0) {
// cout << "Factorial is not defined for negative numbers." << endl;
// } else {
// cout << "Factorial of " << number << " is " << factorial(number) << endl;
// }
// return 0;
// }
# include<iostream>
using namespace std;
class Factorial
{
    public:
    int factorial(int n)
    {
if (n == 0 || n == 1)
{
return 1;
}
 else 
{
return n * factorial(n - 1);
}
    }


};
int main()
{
    Factorial f1;
    long num;
    cout<<"Enter a number:";
    cin>>num;
    long result;

    if(num<0)
    {
        cout<<"Invalis input!";
    }
    else
    {
         result = f1.factorial(num);
        cout<< "Factorial of " << num << " is " << result <<endl;
    }

   
    return 0;
}