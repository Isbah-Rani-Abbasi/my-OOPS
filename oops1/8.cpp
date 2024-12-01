# include<iostream>
# include<string>
using namespace std;
class Teacher
{    
     public:
     Teacher()   //constructor
     {
        dept="Computer Science";
     }
    string dept;
     void changedept(string newdept)
     {
          dept=newdept;
     }
};
int main()
{
    Teacher t1;  //construct called only at once at object creation and constructor is always public
    cout<<" Old departement is: "<<t1.dept<<endl;
    string newdept;
    cout<<" Enter a new departemnt :";
    cin>>newdept;
    t1.changedept(newdept);
    cout<<" New departement is: "<<t1.dept<<endl;
    return 0;

     
}