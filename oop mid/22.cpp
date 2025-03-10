# include<iostream>
# include<string>
using namespace std;
class engine
{
    public:
    engine()
    {
        cout<<"Engine constructor"<<endl;
    }
    ~engine()
    {
        cout<<"Engine destructor"<<endl;
    }
    void start()
    {
        cout<<"Engine started"<<endl;
    }
    void stop()
    {
        cout<<"Engine stopped"<<endl;
    }
};
class car
{
    private:
    engine e;
    public:
    car()
    {
        cout<<"car constructor"<<endl;
    }
    ~car()
    {
        cout<<"car desstructor"<<endl;
    }
    void carstart()
    {
        e.start();
    }
    void carstop()
    {
        e.stop();
    }

};

int main()
{
    car c;
    c.carstart();
    c.carstop();
}