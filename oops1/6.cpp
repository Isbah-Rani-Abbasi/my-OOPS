# include<iostream>
# include<string>
using namespace std;
class Teacher
{    
     public:
    string dept;
     void changedept(string newdept)
     {
          dept=newdept;
     }
};
int main()
{
    Teacher t1;
    t1.dept = "computer science";
    cout<<" Old departement is: "<<t1.dept<<endl;
    string newdept;
    cout<<" Enter a new departemnt :";
    cin>>newdept;
    t1.changedept(newdept);
    cout<<" New departement is: "<<t1.dept<<endl;
    return 0;

     
}