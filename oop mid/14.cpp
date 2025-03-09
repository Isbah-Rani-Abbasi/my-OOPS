# include<iostream>
# include<string>
using namespace std;
class person
{
    public:
    string name;
    int age;
};
int main()
{
    person p;
    p.name = "toe";
    p.age = 24;
    cout<<p.name<<endl<<p.age<<endl;

}