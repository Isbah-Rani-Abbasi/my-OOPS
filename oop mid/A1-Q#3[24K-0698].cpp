#include <iostream>
#include <string>
using namespace std;

class vehicle {
private:
    string model;
    float price;
    string eligibility;

public:
    vehicle() {}
    vehicle(string model, float price, string eligibility) : model(model), price(price), eligibility(eligibility) {}

    void setmodel(string m) { model = m; }
    void setprice(float p) { price = p; }
    void seteligibility(string e) { eligibility = e; }
    string getmodel() const { return model; }
    float getprice() const { return price; }
    string geteligibility() const { return eligibility; }

    void display() {
        cout << "Model: " << model << ", Price: " << price << ", Eligibility: " << eligibility << endl;
    }
};

class user {
private:
    float age;
    string license_type;
    string ph_no;
    int id;
    string name;
    vehicle** rentedVehicles;
    int rentedSize;
    int rentedCapacity;

public:
    user() : rentedVehicles(nullptr), rentedSize(0), rentedCapacity(0) {}
    user(float a, string l, string ph, int id, string n) : age(a), license_type(l), ph_no(ph), id(id), rentedVehicles(nullptr), rentedSize(0), rentedCapacity(0), name(n) {}

    bool rentVehicle(vehicle* vh , bool check)
    {     check = false;
        if (vh->geteligibility() == license_type) {
            if (rentedSize == rentedCapacity) {
                rentedCapacity = (rentedCapacity == 0) ? 1 : rentedCapacity * 2;
                vehicle** temp = new vehicle*[rentedCapacity];
                for (int i = 0; i < rentedSize; i++) {
                    temp[i] = rentedVehicles[i];
                }
                delete[] rentedVehicles;
                rentedVehicles = temp;
            }
            rentedVehicles[rentedSize++] = vh;
            cout << "Vehicle rented successfully!" << endl;
            check = true;
        } else {
            cout << "You are not eligible to rent this vehicle." << endl;
        }
        return check;
    }

    void displayRentedVehicles() {
        cout << "-----RENTED VEHICLES-----" << endl;
        for (int i = 0; i < rentedSize; i++) {
            rentedVehicles[i]->display();
        }
    }
    
    void registerUser() {
        cout << "-----REGISTRATION-----" << endl;
        cout << "Enter name of user: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age of user: ";
        cin >> age;
        cout << "Enter license type of user: ";
        cin >> license_type;
        cout << "Enter id of user: ";
        cin >> id;
        cout << "Enter phone no of user: ";
        cin >> ph_no;
    }

    void updateUser() {
        cout << "-----UPDATE-----" << endl;
        cout << "Enter name of user: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age of user: ";
        cin >> age;
        cout << "Enter license type of user: ";
        cin >> license_type;
        cout << "Enter id of user: ";
        cin >> id;
        cout << "Enter phone no of user: ";
        cin >> ph_no;
    }

    void setage(float a) { age = a; }
    void set_li_type(string l) { license_type = l; }
    void setphno(string p) { ph_no = p; }
    void setid(int i) { id = i; }
    float getage() const { return age; }
    string getlicensetype() const { return license_type; }
    string getph_no() const { return ph_no; }
    int getid() const { return id; }
    string getName() const {return name;}

    ~user() { delete[] rentedVehicles; }
};

int main() {
    user u;
    bool check = false;
    vehicle* vehicles[3];
    vehicles[0] = new vehicle("BMW", 1200, "learner");
    vehicles[1] = new vehicle("Corolla", 1330, "intermediate");
    vehicles[2] = new vehicle("Mehran", 1400, "full");

    u.registerUser();

    cout << "-----AVAILABLE VEHICLES-----" << endl;
    for (int i = 0; i < 3; i++) {
        vehicles[i]->display();
    }

    int choice;
    cout << "Enter the vehicle number you want to rent (1-3): ";
    cin >> choice;

    if (choice >= 1 && choice <= 3) {
        check = u.rentVehicle(vehicles[choice - 1] , check);
    } else {
        cout << "Invalid vehicle choice." << endl;
    }

    u.displayRentedVehicles();
    if(!check){
    u.updateUser();
    if (choice >= 1 && choice <= 3) {
       check= u.rentVehicle(vehicles[choice - 1],check);
    } else {
        cout << "Invalid vehicle choice." << endl;
    }
    u.displayRentedVehicles();
    }
    for (int i = 0; i < 3; i++) {
        delete vehicles[i];
    }
    return 0;
}
