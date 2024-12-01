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
   private:
   double bonus;  
  
   public:
     
    void setter(string name , double salary,double bonus)
   {
     this->salary=salary;
     this->bonus=bonus;
     this->name=name;
   } 

   void info()
   {
    cout<<"Name of manager is "<<name<<endl;
    cout<<"Saalry of maanger is "<<salary<<endl;
    cout<<"Total earning of mananger is "<<salary+bonus<<endl;
   }
};
class Intern : private Employee
{
    private:    // all attrinutes are private.
    double hourlyrate;
    double hoursworked;
    public:
    void setter(string name, double hourswroked , double hourlyrate)
    {
      this->name=name;
      this->hoursworked=hoursworked;
      this->hourlyrate=hourlyrate;
    }

    void info()
    { 
       cout<<"Name of intern is "<<name<<endl;
       cout<<"Hours of intern is "<<hoursworked<<endl;
       cout<<"Total earning of intern is "<<hoursworked*hourlyrate<<endl;
    }
};
int main()
{
    Manager m1;
    Intern i1;
    string name;
    double salary,total_earning,bonus,hourlyrate,hours;
    int n;
    cout<<"1.For manager."<<endl;
    cout<<"2.For intern."<<endl;
    cin>>n;
    switch (n)
    {
    case 1:
         cout<<"Enter maanger name: "<<endl;
         cin>>name;
         cout<<"Enter salary of manager: "<<endl;
         cin>>salary;
         cout<<"Enter bonus of manager: "<<endl;
         cin>>bonus;
         m1.setter(name , bonus , salary);
         m1.info();

        break;
    case 2:
         cout<<"Enter intern name: "<<endl;
         cin>>name;
         cout<<"Enter hours of intern: "<<endl;
         cin>>hours;
         cout<<"Enter hourly rate of intern: "<<endl;
         cin>>hourlyrate;
         i1.setter(name , hours , hourlyrate);
         i1.info();
        break;
    
    default:
    cout<<"Invalid input!";
        break;
    }
    return 0;

}