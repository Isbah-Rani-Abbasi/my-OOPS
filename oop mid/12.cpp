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
    subject sub[3];
    
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
        cout<<"Enter all 3 subject of "<<s[i].id<<endl;
        cin>>s[i].sub[0].subj;
        cin>>s[i].sub[1].subj;
        cin>>s[i].sub[2].subj;
    }
    for(int i=0 ;i<size ;i++)
    {
        cout<<"Id of "<<i+1<<" student:"<<endl<<endl;
        cout<<s[i].id<<endl;
        cout<<"All 3 subject of "<<s[i].id;
        cout<<s[i].sub[0].subj<<endl;
        cout<<s[i].sub[1].subj<<endl;
        cout<<s[i].sub[2].subj<<endl;
    }
    delete []s;
}
