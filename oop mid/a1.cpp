#include <iostream>
#include <string>
using namespace std;


class Passenger {
protected:
    string name;
    string id;
    string pickup;
    string dropoff;
    bool isCardActive;
    bool attendance;

public:
    Passenger() : name("null"), id("null"), pickup("null"), dropoff("null"), isCardActive(false), attendance(false) {}
    Passenger(string n , string id , string pickup , string dropoff ):name(n),id(id),pickup(pickup),dropoff(dropoff){}
    void registerStudent() {
        cout << "Enter name:" << endl;
        cin >> name;
        cout << "Enter id:" << endl;
        cin >> id;
        cout << "Enter pick up location:" << endl;
        cin >> pickup;
        cout << "Enter drop off location:" << endl;
        cin >> dropoff;
    }
    void setName(string n) { name = n; }
    void setId(string id) { this->id = id; }
    void setPickup(string up) { pickup = up; }
    void setDropoff(string off) { dropoff = off; }
    string getName() const { return name; }
    string getId() const { return id; }
    string getPickup() const { return pickup; }
    string getDropoff() const { return dropoff; }

    virtual bool payFees() 
    {
        cout<<"Fees has been paid"<<endl;
        return true;
    }
    void setAttendance(bool a){attendance = a;}

    void tapCard() {
        if (attendance) {
            cout << "Your Attendance has been marked!\n\n\n";
        }
    }

    virtual void display() {
        cout << "Name:" << name << endl;
        cout << "Id: " << id << endl;
        cout << "Route: " << pickup << endl;
        cout << "Stop: " << dropoff << endl;

        if (isCardActive && attendance) {
            cout << name<<" semester Fees has been paid" << endl;
            cout << name<<" attendance is marked" << endl;
        }
    }
    bool operator ==(const Passenger &p)
    {
        return (name==p.name);
    }
    bool operator !=(const Passenger &p)
    {
        return !(*this==p);
    }
};

class Student :public Passenger
{
    private:
    double fees;
    public:
    Student(double fees,string n , string id , string pickup , string dropoff):fees(fees) , Passenger(n , id , pickup , dropoff){}

    bool payFees() override
    {
        isCardActive = true;
        return isCardActive;
    }
    void display()override
    {
        Passenger::display();
        cout<<"Fees is"<<fees<<endl;
    }

};

class Staff :public Passenger
{
    private:
    double salary;
    public:
    Staff(double fees,string n , string id , string pickup , string dropoff):salary(fees) , Passenger(n , id , pickup , dropoff){}

    bool payFees() override
    {
        isCardActive = true;
        return isCardActive;
    }
    void display()override
    {
        Passenger::display();
        cout<<"Fees is"<<salary<<endl;
    }

};

class Teacher :public Passenger
{
    private:
    double salary;
    public:
    Teacher(double fees,string n , string id , string pickup , string dropoff):salary(fees) , Passenger(n , id , pickup , dropoff){}

    bool payFees() override
    {
        isCardActive = true;
        return isCardActive;
    }
    void display()override
    {
        Passenger::display();
        cout<<"Salary is"<<salary<<endl;
    }

};
class Point {
private:
    Passenger **p;           //a ptr pointing array of pointer which is then point passennger type object.
    int passengerCount;
    int passengerCapacity;
    string* pickup;          //a ptr pointing pickup string
    int pickupcapacity;
    int pickupcount;
    string* dropoff;
    int dropoffcapacity;
    int dropoffcount;

public:
    Point() : pickup(nullptr), dropoff(nullptr), passengerCount(0), passengerCapacity(0), p(nullptr), pickupcapacity(0), pickupcount(0), dropoffcapacity(0), dropoffcount(0) {}

    void addPickup(string p) {
        if (pickupcapacity == pickupcount) {
            pickupcapacity = (pickupcapacity == 0) ? 1 : 2 * pickupcapacity;
            string* temp = new string[pickupcapacity];
            for (int i = 0; i < pickupcount; i++) {
                temp[i] = pickup[i];
            }
            delete[] pickup;
            pickup = temp;
        }
        pickup[pickupcount++] = p;
    }

    void addDropOff(string d) {
        if (dropoffcount == dropoffcapacity) {
            dropoffcapacity = (dropoffcapacity == 0) ? 1 : 2 * dropoffcapacity;
            string* temp = new string[dropoffcapacity];
            for (int i = 0; i < dropoffcount; i++) {
                temp[i] = dropoff[i];
            }
            delete[] dropoff;
            dropoff = temp;
        }
        dropoff[dropoffcount++] = d;
    }

    bool addPassenger(Passenger* s, bool flag) {
        bool p1 = false;
        bool d1 = false;
        for (int i = 0; i < pickupcount; i++) {
            if (s->getPickup() == pickup[i]) {
                p1 = true;
                break;
            }
        }
        for (int i = 0; i < dropoffcount; i++) {
            if (s->getDropoff() == dropoff[i]) {
                d1 = true;
                break;
            }
        }
        if (p1 == true && d1 == true && s->payFees() == true) {
            if (passengerCapacity == passengerCount) {
                passengerCapacity = (passengerCapacity == 0) ? 1 : 2 * passengerCapacity;
                Passenger** temp = new Passenger * [passengerCapacity];
                for (int i = 0; i < passengerCount; i++) {
                    temp[i] = p[i];
                }
                delete[] p;
                
                p = temp;
                flag = true;
            }
            p[passengerCount++] = s;
            s->setAttendance(true);
        } else {
            cout << s->getName() << " is not eligible for point registration" << endl;
        }
        return flag;
    }

    void displayPassenger() {
        cout<<"----------------ALL PASSENGERS OF POINT--------------"<<endl;
        for (int i = 0; i < passengerCount; i++) {
            p[i]->display();
        }
    }

    ~Point() {
        delete[] pickup;
        delete[] dropoff;
        if (p != nullptr) {
            for (int i = 0; i < passengerCount; i++) {
                delete p[i]; // Delete each Passenger obj
            }
            delete[] p; // Delete the array of pointers
        }
    }
};

int main() {
    Point* p = new Point();
    string pickup[3] = { "Qayyumabad", "MalirHalt", "DHA" };
    string dropoff[3] = { "FAST", "IBA", "Sufa" };
    for (int i = 0; i < 3; i++) {
        p->addPickup(pickup[i]);
        p->addDropOff(dropoff[i]);
    }
     

    Student *s[2];
    s[0] = new Student(1000 ,"isbah" ,"k240698" ,"MalirHalt" ,"FAST");
    s[1] = new Student(1000 , "Faris" ,"k245678" ,"DHA" ,"Sufa");
    Teacher *t = new Teacher(500 , "Dr.Mariam" , "T678" ,"Qayyumabad" , "IBA");
    Staff *st = new Staff(700 , "Mr.Ali" , "ST234" , "MalirHalt" , "FAST");
     s[0]->payFees();
     s[1]->payFees();
     t->payFees();
     st->payFees();

     p->addPassenger(s[0] , false);
     p->addPassenger(s[1] , false);
     p->addPassenger(t , false);
     p->addPassenger(st , false);
     cout<<"-----------------COMPARING TWO STUDENT OBJECT-------------------"<<endl;
     if(s[0] != s[1])
     {
        cout<<"passenger are different"<<endl;
     }
     else{
        cout<<"Paseenger are same"<<endl;
     }

     p->displayPassenger();

     delete s[0];
     delete s[1];
     delete t;
     delete st;



    
   
}