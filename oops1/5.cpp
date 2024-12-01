// #include <iostream>
// using namespace std;
// int findLargest(int a, int b, int c) {
// if (a >= b && a >= c) {
// return a; // a is the largest
// } else if (b >= a && b >= c) {
// return b; // b is the largest
// } else {
// return c; // c is the largest
// }
// }
// int main() {
// int num1, num2, num3;
// cout << "Enter three numbers: ";

// cin >> num1 >> num2 >> num3;
// int largest = findLargest(num1, num2, num3);
// cout << "The largest number is: " << largest << endl;
// return 0;
// }

# include<iostream>
using namespace std;
class Findlargest
{
  public:
  int great(int a, int b, int c) 
  {
if (a >= b && a >= c) 
{
return a; // a is the largest
} 
else if (b >= a && b >= c) 
{
return b; // b is the largest
} 
else 
{
return c; // c is the largest
}
 }

};
int main()
{
   Findlargest f1;
   int a,b,c;
   cout<<"Enter three numbers:";
   cin>>a>>b>>c;
   int largest=f1.great(a,b,c);
   cout<<" The largest number amoung "<< a <<" , " <<b << " and " <<  c << " is " <<largest << endl;
   return 0;
}