# include<iostream>
# include<string>
using namespace std;
class statics
{
    static int a;
    int b;
    public:
    static int c;
    static void setA(int c)
    {
      a =c;
    }
    static int getA()
    {
        return a;
    }
};
int statics::c = 4;
int statics::a = 5;
int main()
{
  statics::setA(3);
  cout<<statics::getA()<<endl;
  cout<<statics::c;
}