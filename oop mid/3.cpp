# include<iostream>
using namespace std;
struct bill
{
    int id;
    string name;
    float unitconsumed;
    float total;
};
int main()
{
    struct bill b;
    cin>>b.name;
    cin>>b.id;
    cin>>b.unitconsumed;
    if (b.unitconsumed<=199)
    {
        b.total=b.unitconsumed*16.20;
    }
    else if (b.unitconsumed>199 && b.unitconsumed<300)
    {
        b.total=b.unitconsumed*20.10;
    }
    else if (b.unitconsumed>=300 && b.unitconsumed<500)
    {
        b.total=b.unitconsumed*27.10;
    }
    else if (b.unitconsumed>=500)
    {
        b.total=b.unitconsumed*35.90;
    }
    cout<<b.id<<endl<<b.name<<endl<<b.unitconsumed<<endl<<b.total<<endl;


}