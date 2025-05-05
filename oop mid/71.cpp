# include<iostream>
# include<string>
using namespace std;

class doctor;
class biling;
class PatientRecord
{
    private:
    string history;
    string currentTreatment;
    string name;
    string dob;
    string billinfo;

    
    void updatename(string n)
    {
        name =n;
    }
    void updatehistory(string h)
    {
        history = h;
    }
    void updatecurrentTreatment(string t)
    {
        currentTreatment =t;
    }
    void updatedob(string d)
    {
        dob =d;
    }
    void updatebill(string b)
    {
        billinfo = b;
    }
    public:
   

    PatientRecord(string n, string d ,string h, string c,string b)
    {
        name = n;
        dob = d;
        history = h;
        currentTreatment = c;
        billinfo=b;
    }

    void getPublicData()
    {
       cout<<"Name "<<name<<endl<<"Date of Birth "<<dob<<endl;
       cout<<"Current treatment "<<currentTreatment<<endl;
       cout<<"Bill Info "<<billinfo<<endl;
       cout<<"History "<<history<<endl;
    }
    friend doctor;
    friend biling;

};
class doctor
{
  public:
  void updatemedicalhistory(PatientRecord &p)
  {
    p.updatehistory("patient is now all healthy");
  }
};
class biling
{
    public:
    void addBilingdetails(PatientRecord &p)
    {
        p.updatebill("Bill is 900");
    }
};
int main()
{
    PatientRecord *p=new PatientRecord("isbah","20-05-2004","thelasimia","radiography","500");
    doctor d;
    d.updatemedicalhistory(*p);
    biling b;
    b.addBilingdetails(*p);
    p->getPublicData();

}