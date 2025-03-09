# include<iostream>
# include<string>
using namespace std;
class date
{
    private:
    int day;
    int month;
    int year;
    public:
    date(int a=2 , int b=12 , int c=2024):day(a) , month(b) ,year(c){};
    void display()
    {
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }
};
int main()
{
    date d(9,7);
    d.display();

}