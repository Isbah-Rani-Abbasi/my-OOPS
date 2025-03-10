# include<iostream>
# include<string>
using namespace std;
class Car
{
    private:
    string name;
    int id;
    public:
    void setname(string n)
    {
        name = n;
    }
    void setid(int id)
    {
        this->id = id;
    }
    string getname()
    {
        return name;
    }
    int getid()
    {
        return id;
    }
};
class garage
{
    private:
    Car **car;
    int carCount;
    int carCapacity;
    public:
    garage(): car(nullptr) , carCapacity(0) ,carCount(0){};
    void parkcar(Car *c)
    {
        if(carCapacity == carCount)
        {
            carCapacity = (carCapacity==0)? 1:2*carCapacity;
            Car **temp = new Car *[carCapacity];
            for (int i=0 ;i<carCount ;i++)
            {
                temp[i] = car[i];
            }
            delete []car;
            car = temp;
        }
        car[carCount++] = c;
    }
    void listcar()
    {
        for(int i=0 ;i<carCount ;i++)
        {
            cout<<"car name is:"<<car[i]->getname()<<endl;
            cout<<"car id is:"<<car[i]->getid()<<endl;
        }
    }
    ~garage()
    {
        delete []car;
    }
};
int main()
{
    garage g;
    Car *c = new Car[3];
   
    c[0].setid(1234);
    c[0].setname("BMW");
    c[1].setid(1698);
    c[1].setname("Corolla");
    c[2].setid(9987);
    c[2].setname("Honda");

    g.parkcar(&c[0]);
    g.parkcar(&c[1]);
    g.parkcar(&c[2]);
    g.listcar();

    delete []c;
    
    
    
}