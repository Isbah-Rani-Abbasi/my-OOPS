// 3: Create a base class Employee with protected data members: name and salary.
// Derive two classes:
// ● Manager (add bonus attribute).
// ● Intern (add hoursWorked attribute).
// Write a method in each class to calculate total earnings:
// ● For Manager: salary + bonus.
// ● For Intern: hoursWorked * hourlyRate.
// Test both classes in the main function.
# include<iostream>
# include<string>
using namespace std;
class Employee
{
    protected:
    string name;
    double salary;
};
class Manager : private Employee
{
  public:
  double bonus;
  void setter(string n, double s)   // setter function has no return type
    {
       this->name=n;
       this->salary=s;
    }
  
  void info()
  {
     cout<<"Name: "<<name<<endl;
     cout<<"Salary: "<<salary<<endl;
     cout<<"Total amount: "<<salary+bonus<<endl;
  }
 
};
class Intern : private Employee
{
    public:
    double hoursworked;
    double hourlyrate;
    void setter(string n, double s)   // setter function has no return type
    {
       this->name=n;
       this->salary=s;
    }
      void info()
  {
     cout<<"Name: "<<name<<endl;
     cout<<"Salary: "<<salary<<endl;
     cout<<"Total amount: "<<hoursworked*hourlyrate<<endl;
  }
 
};
int main()
{
   Employee e1;
   Manager m1;
   Intern i1;
   string name;
   double salary;
   double bonus;
   double hoursworked;
   double hourlyrate;
   int n;
   cout<<"1.For manager."<<endl;
   cout<<"2.For intern."<<endl; 
   cin>>n;
   switch (n)
   {
   case 1:
    cout<<"Enter the name of maanager:"<<endl;
    cin>>name;
    cout<<"Enter the saalry of Manager:"<<endl;
    cin>>salary;
    m1.setter(name , salary);
    cout<<"Enter bonus:"<<endl;
    cin>>bonus;
    m1.bonus=bonus;
    m1.info();
    break;

    case 2:
     cout<<"Enter the name of intern:"<<endl;
    cin>>name;
    cout<<"Enter the salary of intrn:"<<endl;
    cin>>salary;
    cout<<"Enter hour worked of intern:"<<endl;
    cin>>hoursworked;
    cout<<"Enter hourly rate of intern:"<<endl;
    cin>>hourlyrate;
    i1.setter(name , salary);
    i1.hoursworked=hoursworked;
    i1.hourlyrate=hourlyrate;
    i1.info();


    break;
   
   default:
   cout<<"Invalid input!"<<endl;
    break;
   }
   return 0;

}