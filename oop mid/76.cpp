# include<iostream>
# include<string>
# include<sstream>
# include<fstream>
using namespace std;

class Course
{
 protected:
 string name;
 string courseCode;
 int creditHours;
 
 public:
 Course(string name ,string courseCode, int creditHours):
 name(name),courseCode(courseCode),creditHours(creditHours){}
 virtual string getName()=0;
 virtual string getCourseCode()=0;
 virtual int getCreditHours()=0;
 virtual ~Course(){}

};
class Corecourse:public Course
{
    public:
    Corecourse(string name ,string courseCode, int creditHours):
    Course(name ,courseCode,creditHours){}

    string getName()override
    {
        return name;
    }
    string getCourseCode()override
    {
        return courseCode;
    }
    int getCreditHours()override
    {
        return creditHours;
    }

};

class ElectiveCourse:public Course
{
    public:
    ElectiveCourse(string name ,string courseCode, int creditHours):
    Course(name ,courseCode,creditHours){}

    string getName()override
    {
        return name;
    }
    string getCourseCode()override
    {
        return courseCode;
    }
    int getCreditHours()override
    {
        return creditHours;
    }
};
class Prerequisite
{
    protected:
    string code[3];
    public:
    Prerequisite()
    {
        for(int i=0;i<3;i++)
        {
            code[i]="C101"+i;
        }
    }
    void tellPrerequisite(Course *c)
    {
        if(c->getCourseCode()=="C1010")
        {
            cout<<"prerequisite is Eng"<<endl;
        }
        else if(c->getCourseCode()=="C1011")
        {
            cout<<"prerequisite is Sci"<<endl;
        }
        else if(c->getCourseCode()=="C1012")
        {
            cout<<"prerequisite is PF"<<endl;
        }
    }
 
};

class ComputerScienceCoreCourse:public Corecourse
{
   public:
   ComputerScienceCoreCourse ():
   Corecourse("ComputerScience" ,"C101",3){}
   string getName()override
   {
       return name;
   }
   string getCourseCode()override
   {
       return courseCode;
   }
   int getCreditHours()override
   {
       return creditHours;
   }
};

class MathCoreCourse:public Corecourse
{
   public:
   MathCoreCourse ():
   Corecourse("Math" ,"M101",3){}
   string getName()override
   {
       return name;
   }
   string getCourseCode()override
   {
       return courseCode;
   }
   int getCreditHours()override
   {
       return creditHours;
   }
};

template<typename t>
class CourseCatalog
{
    
     t **p;
     int count;
     int capacity;
     public:
    CourseCatalog():count(0),capacity(0),p(nullptr){}

     void addCours(t *c)
    {
        if(count==capacity)
        {
        capacity=(capacity==0)?1:2*capacity;
            t **temp=new t*[capacity];
            for(int i=0 ;i<count;i++)
            {
                temp[i]=p[i];
            }
    delete []p;
            p=temp;
        }
        p[count++]=c;
    }
    void calculateCreditHourse()
    {
        int total = 0;
        for(int i=0 ;i<count;i++)
        {
            
           total=total+p[i]->getCreditHours();
        }
        cout<<"Total credit hourse"<<total<<endl;
    }
    void ifEligible()
    {
        Prerequisite p;
        for(int i=0;i<count;i++)
        {
            p.tellPrerequisite(&p[i]);
        }
    }

};
int main()
{
    Course *c;
    ElectiveCourse e("RS","C101",2);
    Corecourse f("MA","C102",3);
    c=&e;
    CourseCatalog<Course> t;
    t.addCours(&f);
    t.calculateCreditHourse();
    t.ifEligible();
}