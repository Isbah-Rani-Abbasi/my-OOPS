# include<iostream>
# include<string>
using namespace std;
class Teacher
{
    private:
    string name;
    string dept;
    double salary;
  public:
  Teacher(string n, string d, double s)  // parameterized constructor
  {
     name=n;
     dept=d;
     salary=s;
  }
  void printing()
  {
    cout<<"The name of teacher is "<<name<<endl;
    cout<<"The department of teacher is "<<dept<<endl;
    cout<<"The salary of teacher is "<<salary<<endl;

  }
};
int main()
{
    string name , department;
    double salary;
    cout<<"Enter the name of teacher: "<<endl;
    cin>>name;
    cout<<"Enter the department of teacher is "<<endl;
    cin>>department;
    cout<<"Enter the salary of teacher: "<<endl;
    cin>>salary;
    Teacher t1(name , department , salary);
    t1.printing();
    return 0;
}