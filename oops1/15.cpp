// Design a class Student with private data: name, rollNumber, grade.
// ● Add setter and getter methods to assign and retrieve these values.
// ● Write a method to determine whether the student passed (grade >= 50).
// ● Test the implementation.
# include<iostream>
# include<string>
using namespace std;
class Student
{
  private:
  string name;
  string roll_no;
  double grade;
  public:
  void setter(string n , string r , double g)
  {
    this->name=n;
    roll_no=r;
    grade=g;
  }
  string getter1()
  {
    return name;
  }
  string getter2()
  {
    return roll_no;
  }
  double getter3()
  {
    return grade;
  }
  void check()
  {
    if(grade>=50)
    {
      cout<<name<<" is pass!"<<endl;
    }
    else
    {
      cout<<name<<" is fail!"<<endl;
    }
  }
};
int main()
{
    Student s1;
    string name,roll_no;
    double grade;
    cout<<"Enter the name of strudent :";
    cin>>name;
    cout<<"Enter the roll no of stufent :";
    cin>>roll_no;
    cout<<"Enter the grade of student :";
    cin>>grade;
    s1.setter(name , roll_no , grade);
    cout<<"The name of student is: "<<s1.getter1()<<endl;
    cout<<"The roll no of student is: "<<s1.getter2()<<endl;
    cout<<"The marks of student is: "<<s1.getter3()<<endl;
    s1.check();
    return 0;


}