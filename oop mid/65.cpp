# include<string>
# include<sstream>
# include<fstream>
# include<iostream>
using namespace std;

class A
{
  public:
  int age;
  int id;
  string name;
};

int main()
{
    int n;
    cout<<"Enter no of obj you wan tto create"<<endl;
    cin>>n;
    A obj[n];
    for(int i=0 ;i<n;i++)
    {
        cout<<"Enter name of "<<i+1<<" obj"<<"."<<endl;
        cin>>obj[i].name;
        cout<<"Enter id of "<<i+1<<" obj"<<"."<<endl;
        cin>>obj[i].id;
        cout<<"Enter age of "<<i+1<<" obj"<<"."<<endl;
        cin>>obj[i].age;
    }

    ofstream out;
    out.open("A.txt");
    if(!out)
    {
        return 1;
    }
    for(int i=0 ;i<n;i++)
    {
        out<<obj[i].name<<","<<obj[i].age<<","<<obj[i].id<<endl;
    }

    out.close();

    ifstream in;
    in.open("A.txt");
    string line;
    string id[n];
    string name;
    string age;
    int i=0 ;
    while (getline(in,line)&&i<n)
    {
      stringstream ss(line);
      getline(ss,name,',');
      getline(ss,age,',');
      getline(ss,id[i],'.');
      i++;
    }
    cout<<"all ids are as follow"<<endl;
    for(int i=0 ;i<n;i++)
    {
        cout<<id[i]<<endl;
    }
    try
    {
      for(int i=0 ;i<n;i++)
      {
        for(int j=i+1;j<n;j++)
        {
            if(id[i]==id[j])
            {
                throw runtime_error{"Error 404"};
            }
        }
      }
      cout<<"NO error"<<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}