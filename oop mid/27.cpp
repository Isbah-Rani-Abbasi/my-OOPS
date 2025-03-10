# include<iostream>
# include<string>
using namespace std;
class student
{
    const string rollno;
    public:
    student(string r):rollno(r){};
    void print()
    {
        cout<<rollno;
    }
};
int main()
{
    student s("24k-0698");
    s.print();
}