# include<iostream>
# include<string>
using namespace std;

class Employee
{
    protected:
    string name;
    string id;
    double salary;
    public:
    Employee(){}
    Employee(string n, string id , double s):name(n),id(id),salary(s){}
};
class Ananlyst:virtual public Employee
{
    protected:
    string specialization[5];
    int scount;

    bool isCertified;
    public:
    Ananlyst(string sp[],int count ,bool is , string n, string id , double s):
    isCertified(is),Employee(n,id,s),scount(0)
    {
        scount=count;
        for(int i=0 ;i<count;i++)
        {
            if(sp[i]=="Network"||sp[i]=="IncidentResponse"||
                sp[i]=="ThreatIntelligence")
                {
                    specialization[i]=sp[i];
                }
        }
    }
    
    void HasCertifications()
    {
        if(scount==0)
        {
            cout<<"No Certifications"<<endl;
        }
        else{
            cout<<"The specializaiotn of "<<name<<" are as follow:"<<endl;
            for(int i=0 ;i<scount;i++)
            {
                cout<<i<<"."<<specialization[i]<<endl;
            }
        }
    }

};
class Enigneer:virtual public Employee
{
    protected:
    bool isExpert;
    bool isAssigned;
    string *project;
    int pcount;
    int pcapacity;
    public:
   

    Enigneer(string n, string id, double s):Employee(n,id,s),isExpert(false),
    isAssigned(false),pcount(0),pcapacity(0),project(nullptr){}
    void isExpert123()
    {
        isExpert=true;
    }
    void AddProjects(string s)
    {
      if(isAssigned==true)
      {
        
        if(pcount==pcapacity)
        {
            pcapacity=(pcapacity==0)?1:2*pcapacity;
            string *temp=new string [pcapacity];
            for(int i=0 ;i<pcount;i++)
            {
                temp[i]=project[i];
            }
            delete []project;
            project=temp;
        }
        project[pcount++]=s;
      }
      else
      {
       cout<<"No projects can be added!"<<endl;
      }
    }

    void AssignProject()
    {
        if(isExpert)
        {
            isAssigned=true;
        }
        else
        {
            isAssigned=false;
        }
    }
    ~Enigneer()
    {
        delete []project;
    }

};
class LeadProfessionals:public Ananlyst,public Enigneer
{
    public:
    LeadProfessionals(string n, string id ,double s ,string sp[],int count ,bool is):Employee(n,id,s),Ananlyst(sp , count , is , n,id,s),Enigneer(n,id,s){}
    void ShowProjects()
    {
        cout<<"List of Project"<<endl;
        for(int i=0 ;i<pcount;i++)
        {
          cout<<i<<"."<<project[i]<<endl;
        }
    }
    void ShowCertifications()
    {
        HasCertifications();
    }
};
int main()
{
    string arr[3]={"Network","IncidentResponse","ThreatIntelligence"};
    LeadProfessionals l("isbah","k240698",900,arr,3,true);
    l.isExpert123();
    l.AssignProject();
    l.AddProjects("eating");
    l.ShowCertifications();
    l.ShowProjects();
}