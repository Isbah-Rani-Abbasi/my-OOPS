# include<iostream>
# include<string>
using namespace std;
class blendJuice
{
    public:
    void blendjuice(string f)
    {
        for(int i =0 ;i<100 ;i++)
        {

        }
        cout<<f<<" is blended"<<endl;

    }

};
class grindJuice
{
    public:
    void grindjuice(string f)
    {
        for(int i =0 ;i<100 ;i++)
        {

        }
        cout<<f<<" is grind"<<endl;

    }

};

class juicemaker
{
    private:
    blendJuice b;
    grindJuice g;
    public:
    void blendJuice()
    {
        b.blendjuice("apple");
    }
    void grindJuice()
    {
        for(int i =0 ;i<100 ;i++)
        {

        }
       g.grindjuice("Mango");
    }
};
int main()
{
 juicemaker j;
 j.blendJuice();
 j.grindJuice();
}