// Create a simple calculator application in C++ that performs the following operations:
// addition, subtraction, multiplication, and division. You will implement this calculator using
// Object-Oriented Programming.
# include<iostream>
# include<string>
using namespace std;
class Calculator
{
    public:
  double add(double a, double b)
  {
    return a+b;
  }
  double product(double a, double b)
  {
    return a*b;
  }
  double subtract(double a, double b)
  {
     if(a>b)
     {
        return a-b;
     }
     else
     {
       return b-a;
     }
  }
  double divide(double a,double b)
  {
    if(a==0||b==0)
    {
       cout<<" Invalid Input "<<endl;
       return 0;
    }
    else
    {
        return a/b;
    }
  }
};
int main()
{
   Calculator obj;
   double a,b,result;
   cout <<" Enter num1: ";
   cin>>a;
   cout<<" Enter num2: ";
   cin>>b;
   char operation;
   cout <<" Enter the operation you want to perform between num 1 and num 2: ";
   cin>>operation;
   switch (operation)
   {
   case '+':
    result=obj.add(a,b);
    cout<< " The sum of " << a << " and " << b << " is " << result;
    break;
   case '-':
    result=obj.subtract(a,b);
    cout<< " The subtration of " << a << " and " << b << " is " << result;
    break;
    case '*':
    result=obj.product(a,b);
    cout<< " The product of " << a << " and " << b << " is " << result;
    break;
    case '/':
    result=obj.divide(a,b);
    cout<< " The division of " << a << " and " << b << " is " << result;
    break;
   default:
   cout<< " Invalid operation";
    break;
   }


}