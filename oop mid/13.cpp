# include<iostream>
# include<string>
using namespace std;

struct subject
{
    string subj;
};
struct student
{
    int id;
    int n ;
    subject *sb ;
    
};
int main()
{
    int size;
    cout<<"Enter size";
    cin>>size;
    student *s = new student[size];
    
    for(int i=0 ;i<size ;i++)
    {
        cout<<"Enter the id of "<<i+1<<" student:"<<endl;
        cin>>s[i].id;
        cout<<"Enter no subject of "<<s[i].id<<endl;
        cin>>s[i].n;
        s[i].sb = new subject[s[i].n];
        for(int j=0 ;j<s[i].n ;j++)
        {
        cin>>s[i].sb[j].subj;
        }
    }
    for(int i=0 ;i<size ;i++)
    {
        cout<<"Id of "<<i+1<<" student:"<<endl;
        cout<<s[i].id<<endl;
        cout<<"All  subject of "<<s[i].id<<endl;
        for(int j=0 ;j<s[i].n ;j++)
        {
            cout<<s[i].sb[j].subj<<endl;
        }
        delete []s[i].sb;
    }
    delete []s;
}
