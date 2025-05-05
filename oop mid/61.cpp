# include<iostream>
# include<fstream>
# include<string>
using namespace std;

class student
{
    public:
    int rolllno;
    int marks;
    char name[10];
};
void write()
{
    ofstream out;
    out.open("student.txt",ios::app);
   
    student s1={20,100,"isbah"};
   

    if(out.is_open())
    {
        out<<s1.name<<endl<<s1.marks<<endl<<s1.rolllno<<endl;
    }
    out.close();
}
void read()
{
    ifstream in;
    in.open("student.txt");
    if(in.is_open())
    {
        string line;
        while(getline(in,line))
        {
            cout<<line<<endl;
        }
        in.close();
    }
    else{
        cout<<"file does not open"<<endl;
    }
}
int main()
{
    int yes=1;
   while(yes)
   {
     cout<<"Enter your choice"<<endl;
     cout<<"1.read file"<<endl;
     cout<<"2.write file"<<endl;
     cout<<"3.break"<<endl;

     int var;
     cin>>var;
     switch (var)
     {
     case 1:
        read();
        break;
     case 2:
      write();
      break;
      case 3:
      yes=0;
      break;
     default:
        break;
     }
   }


    
    
}