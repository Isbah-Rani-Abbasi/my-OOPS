//  Create a Rectangle Class
// ● Define private variables: length and width.
// ● Provide public setter and getter methods to access and update these variables.
// ● Write a method calculateArea() to return the area of the rectangle.
// ● Test the class by creating an object, setting values, and printing the area.
# include<iostream>
# include<string>
using namespace std;
class Rectangle
{
  private:
  double lenght;
  double width;
  
  public:
  void setter(double len , double wid);
  double calculateArea();
  
};
void Rectangle::setter(double len , double wid)
{
    lenght=len;
    width=wid;
}
double Rectangle::calculateArea()
{
    return lenght*width;  
}

int main()
{
    Rectangle r1;
    double lenght , width;
    cout<<"Enter the lenght of rectangel: "<<endl;
    cin>>lenght;
    cout<<"Enter the width of recatangle: "<<endl;
    cin>>width;
    r1.setter(lenght , width);
    double area=r1.calculateArea();
    cout << "The area of rectangle is "<< area<< endl;
    return 0;

}