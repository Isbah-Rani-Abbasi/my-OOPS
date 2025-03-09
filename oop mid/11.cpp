# include<iostream>
# include<string>
using namespace std;
struct person
{
  string name;
  int id;  
};
int main()
{
    int n;
    cout<<"Enter n:"<<endl;
    cin>>n;
    person p[n];
    for (int i=0;i<n;i++)
    {
        cout<<"Enter the name of "<<i+1<<"person"<<endl;
        cin>>p[i].name;
        cout<<"Enter the id of "<<i+1<<"person"<<endl;
        cin>>p[i].id;
    }
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].name[0] > p[j+1].name[0])
            {
                person temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    cout<<"Sorted on the bases of first charachter of name!"<<endl;
    for (int i=0 ;i<n ;i++)
    {
        cout<<"Name is: "<<p[i].name<<endl;
        cout<<"Id is: "<<p[i].id<<endl;
    }
    
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].id > p[j+1].id)
            {
                person temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    cout<<"Sorted on the bases of id!"<<endl;
    for (int i=0 ;i<n ;i++)
    {
        cout<<"Name is: "<<p[i].name<<endl;
        cout<<"Id is: "<<p[i].id<<endl;
    }
    
   
    
}