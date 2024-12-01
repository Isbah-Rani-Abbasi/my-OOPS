# include<iostream>
# include<string>
using namespace std;
class Person
{
    public:
    string name;
    double age;
};
class Student : public Person
{
   public:
   int rollno; 
   void getinfo()
   {
     cout<<name<<endl;
     cout<<age<<endl;
     cout<<rollno<<endl;
   }
};
int main()
{
    Student s1;
    s1.age=23;
    s1.name="isbah";
    s1.rollno=12345;
    s1.getinfo();
    return 0;
}