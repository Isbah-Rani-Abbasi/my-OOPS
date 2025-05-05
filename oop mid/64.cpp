# include<iostream>
# include<fstream>
# include<sstream>
# include<string>
using namespace std;

class ST
{
    public:
    int id;
    int age;
    string name;
};

int main()
{
    int n;
    cout<<"Enter no of obj you want to create"<<endl;
    cin>>n;
    ST obj[n];
    for(int i=0 ;i<n;i++)
    {
        cout<<"Enter name of "<<i+1<<" obj"<<endl;
        cin>>obj[i].name;
        cout<<"Enter id of "<<i+1<<" obj"<<endl;
        cin>>obj[i].id;
        cout<<"Enter age of "<<i+1<<" obj"<<endl;
        cin>>obj[i].age;
    }

    ofstream out;
    out.open("st.txt");
    if(!out)
    {
        cout<<"File not open"<<endl;
        return 1;
    }
    for(int i=0 ;i<n;i++)
    {
        out<<obj[i].id<<","<<obj[i].name<<","<<obj[i].age<<endl;
    }
    out.close();

    ifstream in;
    in.open("st.txt");
    string name[n];
    string id;
    string line;
    int i=0;
    bool check;
    if(in.is_open())
    {
        while (getline(in,line)&&i<n)
        {
           stringstream ss(line);
           getline(ss,id,',');
           getline(ss,name[i],',');
           i++;
        }
       in.close(); 
    }
    else{
        cout<<"File is not open"<<endl;
    }
    for(int i=0 ;i<n;i++)
    {
        cout<<name[i]<<endl;
    }
    try
    {
        for(int i=0 ;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        if(name[i]==name[j])
        {
            check =1;
            throw runtime_error{"error"};
            
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