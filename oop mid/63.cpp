# include<iostream>
# include<fstream>
# include<string>
# include<sstream>

using namespace std;

class A
{
    public:
    int id;
    string name;
   
    int age;
};

int main()
{
    int n;
    cout<<"Enter no of obj you want to create"<<endl;
    cin>>n;
    A obj[n];
    for(int i=0 ;i<n;i++)
    {
        cout<<"Enter name of "<<i+1<<" obj"<<endl;
        cin>>obj[i].name;
       // getline(cin,obj[i].name);
        cout<<"Enter id of "<<i+1<<" obj"<<endl;
        cin>>obj[i].id;
        cout<<"Enter age of "<<i+1<<" obj"<<endl;
        cin>>obj[i].age;
    }

    ofstream out;
    out.open("obj.txt",ios::app);
    if(!out)
    {
        cout<<"File not open"<<endl;
        return 1;
    }
    for(int i=0 ;i<n;i++)
    {
        out<<obj[i].id<<","<<obj[i].age<<","<<obj[i].name;
        out<<endl;
        
    }
    out.close();

    ifstream in;
    in.open("obj.txt");
    string id[n];
    int i=0;
    string line;
    if(in.is_open())
    {
    while (getline(in ,line)&&i<n)
    {
       stringstream ss(line);
       getline(ss,id[i],',');
       i++;
    }
    
    }
    for(int i=0 ;i<n;i++)
    {
        cout<<id[i]<<endl;
    }
    try
    {
        for(int i=0 ;i<n;i++)
    {
        if(id[i]==id[i+1])
        {
            throw runtime_error{"error"};

        }
        else{
            cout<<"no error"<<endl;
        }
    }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   
}