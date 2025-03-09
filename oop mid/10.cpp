# include<iostream>
# include<string>
using namespace std;
struct organisation
{
    string name;
    string id;
    struct employee
    {
        string Ename;
        int Eid;
        float salary;
    }emp;
    
};
int main()
{
    organisation org;
    cout<<"Enter organisation nmae:"<<endl;
    cin>>org.name;
    cin>>org.id;
    cin>>org.emp.Ename;
    cin>>org.emp.Eid;
    cin>>org.emp.salary;

    cout<<org.name<<endl;
    cout<<org.id<<endl;
    cout<<org.emp.Ename<<endl;
    cout<<org.emp.Eid<<endl;
    cout<<org.emp.salary<<endl;
    
}