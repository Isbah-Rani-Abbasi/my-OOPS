#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string id;
    double speed;
    double capacity;
    double energyEfficiency; // just an xtra variable for logic designing of efficiency comparison/ai system
    static int deliveries;

public:
    Vehicle(string id, double spd, double cap, double efficiency) 
        : id(id), speed(spd), capacity(cap), energyEfficiency(efficiency) {
        deliveries++;
    }

    virtual ~Vehicle() { deliveries--; }

    virtual void calculateRoute() {
        cout << "Calculating optimal delivery route for vehicle: " << id << endl;
    }

    virtual void estimatedDeliveryTime() {
        cout << "Estimating delivery time for vehicle: " << id << endl;
    }

    virtual void selection(string action, string packageID) {
        cout << "Executing command '" << action << "' for package " << packageID << " using vehicle: " << id << endl;
    }

    virtual void selection(string action, string packageID, string urgency) {
        cout << "Executing urgent command '" << action << "' for package " << packageID << " with urgency: " << urgency << " using vehicle: " << id << endl;
    }

    friend bool efficiencyComparison(Vehicle &v1, Vehicle &v2); 
    bool operator==(const Vehicle &v) {
        return (speed == v.speed && capacity == v.capacity && energyEfficiency == v.energyEfficiency);
    }

    virtual string getType() const { return "Vehicle"; }
};

int Vehicle::deliveries = 0;

class Drone : public Vehicle {
public:
    Drone(string id) : Vehicle(id, 100.0, 5.0, 95.0) {}
    void calculateRoute() override {
        cout << "Calculating aerial route for high-speed iftar delivery..." << endl;
        cout << "Drone is avoiding urban areas and calculating direct flight path." << endl;
    }
    string getType() const override { return "Drone"; }
};

class TimeShip : public Vehicle {
public:
    TimeShip(string id) : Vehicle(id, 80.0, 10.0, 90.0) {}
    void calculateRoute() override {
        cout << "Verifying historical accuracy before transport..." << endl;
        cout << "TimeShip is confirming the time period and ensuring that no historical events are altered." << endl;
    }
    string getType() const override { return "TimeShip"; }
};

class HyperPod : public Vehicle {
public:
    HyperPod(string id) : Vehicle(id, 200.0, 50.0, 85.0) {}
    void calculateRoute() override {
        cout << "Navigating underground hyperloop tunnel for bulk delivery..." << endl;
        cout << "HyperPod is selecting the best underground route with high-speed hyperloop tunnels." << endl;
    }
    string getType() const override { return "HyperPod"; }
};

bool efficiencyComparison(Vehicle &v1, Vehicle &v2) {
    if (v1 == v2) {
        cout << "The Same is assigned the order twice!" << endl;
        return false;
    }

    int ve1 = 0, ve2 = 0;

    if (v1.speed > v2.speed) {
        cout << "In terms of speed, Vehicle " << v1.id << " is better!" << endl;
        ve1++;
    } else {
        cout << "In terms of speed, Vehicle " << v2.id << " is better!" << endl;
        ve2++;
    }

    if (v1.capacity > v2.capacity) {
        cout << "In terms of capacity, Vehicle " << v1.id << " is better!" << endl;
        ve1++;
    } else {
        cout << "In terms of capacity, Vehicle " << v2.id << " is better!" << endl;
        ve2++;
    }

    if (v1.energyEfficiency > v2.energyEfficiency) {
        cout << "In terms of Energy Efficiency, Vehicle " << v1.id << " is better!" << endl;
        ve1++;
    } else {
        cout << "In terms of Energy Efficiency, Vehicle " << v2.id << " is better!" << endl;
        ve2++;
    }

    if (ve1 > ve2) {
        cout << "AC to AI Conflict Resolution System, Vehicle " << v1.id << " is more suitable for perfroming the task!" << endl;
        return true;
    } else {
        cout << "AC to AI Conflict Resolution System, Vehicle " << v2.id << " is more suitable for performing the task!" << endl;
        return false;
    }
}

int main() {
    Drone drone("D-001");
    TimeShip timeship("T-001");
    HyperPod hyperpod("H-001");

    drone.selection("Deliver", "PKG123", "Iftar");
    cout<<endl;
    timeship.selection("Deliver", "PKG456", "Sehri");
    cout<<endl;
    hyperpod.selection("Deliver", "PKG789");
    cout<<endl;

    drone.calculateRoute();
    cout<<endl;
    timeship.calculateRoute();
    cout<<endl;
    hyperpod.calculateRoute();
    cout<<endl;

    efficiencyComparison(drone, hyperpod);
    cout<<endl;

    return 0;
}
