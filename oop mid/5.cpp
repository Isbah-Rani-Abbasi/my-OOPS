# include<iostream>
# include<string>
using namespace std;
struct movie
{
    string name;
    float adultTP;
    float childTP;
    int adultTS;
    int childTS;
    float grossA;
    float grossP;
    float dontedA;
    float TotalS;
};
int main()
{
    movie m;
    cin>>m.name;
    cin>>m.adultTP;
    cin>>m.childTP;
    cin>>m.adultTS;
    cin>>m.childTS;
    cin>>m.grossP;
    m.grossA = (m.adultTP*m.adultTS)+(m.childTP*m.childTS);
    m.dontedA = (m.grossA*m.grossP)/100;
    m.TotalS = m.grossA -m.dontedA;
    cout<<m.TotalS;

}