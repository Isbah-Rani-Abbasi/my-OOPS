# include<iostream>
# include<string>
using namespace std;
class Car
{
   private:
   string carname;
   string carmodel;
   public:
   void setter1(string name);
   void setter2(string model);
   string getter1();
   string getter2();
};
void Car::setter1(string name)
{
  carname=name;
}
void Car::setter2(string model)
{
    carmodel=model;
}
string Car::getter1()
{
    return carname;
}
string Car::getter2()
{
    return carmodel;
}
int main()
{
   Car c1;
   string carname,carmodel,carname1,carmodel1;
   cout<<"Enter the car name: "<<endl;
   cin>>carname;
   cout<<"Enter the car model: "<<endl;
   cin>>carmodel;
   c1.setter1(carname);
   c1.setter2(carmodel);
   carname1=c1.getter1();
   carmodel1=c1.getter2();
   cout <<"The name of your car is: "<<carname1<<endl;
   cout<<"The model of your car is: "<<carmodel1<<endl;
   return 0;
}