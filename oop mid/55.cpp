#include <iostream>       // std::cout
//#include <typeinfo>
# include<exception>   
using namespace std;    // std::bad_cast
class Base {virtual void member(){}};
class Derived : Base {};
int main () {
  try {
    Base b;
    Derived& rd = dynamic_cast<Derived&>(b);
  }
  catch (std::bad_cast& bc) {
     std::cerr << "bad_cast caught: " << bc.what() << '\n';
  }
  return 0;
}
