# include<iostream>
# include<string>
using namespace std;
class employee
{
    private:
    string Fname;
    string Lname;
    double salary;
    public:
    employee(string f , string l , double s):Fname(f),Lname(l),salary(s){}
    void setFname(string Fname)
    {
      this->Fname = Fname;
    }
    void setLname(string Lname)
    {
      this->Lname = Lname;
    }
    void setSalary(double s)
    {
        if (s<0)
        {
            salary = 0.0;
        }
        else
        {
            this->salary = s;
        }
        
    }
    string getFname()
    {
        return Fname;
    }
    string getLname()
    {
        return Lname;
    }
    double getsalary();
    void display()
    {    
        cout<<"First name of employee:"<<Fname<<endl<<"Last name of employee:"<<Lname<<endl<<"Salary of employee:"<<12*salary<<endl;
    }
    void display2()
    {
        salary = salary + (salary*10)/100;
        cout<<"First name of employee:"<<Fname<<endl<<"Last name of employee:"<<Lname<<endl<<"Salary of employee:"<<12*salary<<endl;

    }
};
double employee::getsalary()
{
    return salary;
}
int main()
{
    employee *e = new employee[2]{employee("Isbah" , "Abbasi" , 1000), employee("Ammar" , "Abbasi" , 2000)};
    for(int i=0;i<2;i++)
    {
        e[i].display();
    }

    for(int i=0;i<2;i++)
    {
        e[i].display2();
    }
    for(int i=0;i<2;i++)
    {
        delete []e;
    }
}