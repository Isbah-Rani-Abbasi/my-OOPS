# include<iostream>
# include<string>
using namespace std;
class glass
{
    public:
    int liquidLevel;
    glass():liquidLevel(200){}
    void drink(int mm)
    {
        if(mm<liquidLevel && mm>0)
        {
          liquidLevel = liquidLevel-mm;
          if(liquidLevel<100)
          {
          refill();
          }
          cout<<"Liquid level is"<<liquidLevel<<endl;
        }
        else
        {
            cout<<"Not enough to drink"<<endl;;
        }
    }
    void refill()
    {
      liquidLevel = 200;
    }
};
int main()
{
    glass g;
    int l;
    while(1)
    {
      cout<<"Enter the liquid level you want to drink"<<endl;
      cin>>l;
      if(l==-1 )
      {
        
        break;
      }
      else
      {
        g.drink(l);
      }
     
    }
}