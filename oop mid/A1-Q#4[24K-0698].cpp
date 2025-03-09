#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string id;
    string pickup;
    string dropoff;
    float fees;
    bool isCardActive;
    bool attendance;

public:
    Student() : name("null"), id("null"), pickup("null"), dropoff("null"), fees(0.0), isCardActive(false), attendance(false) {}

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

    bool payFees() {
        isCardActive = true;
        return isCardActive;
    }
    void setAttendance(bool a){attendance = a;}

    void tapCard() {
        if (attendance) {
            cout << "Your Attendance has been marked!\n\n\n";
        }
    }

    void display() {
        cout << "Name:" << name << endl;
        cout << "Id: " << id << endl;
        cout << "Route: " << pickup << endl;
        cout << "Stop: " << dropoff << endl;

        if (isCardActive && attendance) {
            cout << name<<" semester Fees has been paid" << endl;
            cout << name<<" attendance is marked" << endl;
        }
    }
};

class Point {
private:
    Student** student;
    int studentCount;
    int studentCapacity;
    string* pickup;
    int pickupcapacity;
    int pickupcount;
    string* dropoff;
    int dropoffcapacity;
    int dropoffcount;

public:
    Point() : pickup(nullptr), dropoff(nullptr), studentCount(0), studentCapacity(0), student(nullptr), pickupcapacity(0), pickupcount(0), dropoffcapacity(0), dropoffcount(0) {}

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

    bool addStudent(Student* s, bool flag) {
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
            if (studentCapacity == studentCount) {
                studentCapacity = (studentCapacity == 0) ? 1 : 2 * studentCapacity;
                Student** temp = new Student * [studentCapacity];
                for (int i = 0; i < studentCount; i++) {
                    temp[i] = student[i];
                }
                delete[] student;
                student = temp;
                flag = true;
            }
            student[studentCount++] = s;
            s->setAttendance(true);
        } else {
            cout << s->getName() << " is not eligible for point registration" << endl;
        }
        return flag;
    }

    void displayStudent() {
        cout<<"----------------All students of point--------------"<<endl;
        for (int i = 0; i < studentCount; i++) {
            student[i]->display();
        }
    }

    ~Point() {
        delete[] pickup;
        delete[] dropoff;
        delete[] student;
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
    Student* s[2];
    s[0] = new Student();
    s[1] = new Student();
    s[0]->registerStudent();
    s[1]->registerStudent();
    p->addStudent(s[0], false);
    p->addStudent(s[1], false);
    p->displayStudent();
    delete p;
    delete s[0];
    delete s[1];
    return 0;
}