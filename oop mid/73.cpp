# include<iostream>
# include<string>
using namespace std;

class Student
{
    // private:
    // string status;
    // int creditHours;
    public:
    //Student(string s,int h):status(s),creditHours(h){}
   virtual void getTution(string status , int creditHours)=0;
};

class GraduateStudent : public Student
{
    private:
    string researchTopic;
    public:
    GraduateStudent(string t):researchTopic(t){}
    void setresearchTopic(string t)
    {
        researchTopic=t;
    }
    string getResearchTopic()
    {
        return researchTopic;
    }
    void getTution(string status , int creditHours)override
    {
        if(status=="undergraduate"&& creditHours>10)
        {
            cout<<"Tution fee is "<<200<<endl;
        }
       
        else if(status=="graduate"&& creditHours>15)
        {
            cout<<"Tution fee is "<<300<<endl;
        }
        else if(status=="Doctoral"&& creditHours>20)
        {
            cout<<"Tution fee is "<<400<<endl;
        }

        else
        {
            cout<<"Student is out of domain"<<endl;
        }
    }
};
int main()
{
    GraduateStudent *g=new GraduateStudent("Botany");
    g->getTution("undergraduate", 18);
}