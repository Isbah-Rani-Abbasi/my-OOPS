#include <iostream>
using namespace std;

class A {
public:
    int data;
    A(int d) : data(d) {}  // Constructor
    void display() { cout << "Data: " << data << endl; }
};

int main() {
    A *ptr[5]; // Array of 5 pointers of A objects

    // Allocating memory for each object
    for (int i = 0; i < 5; i++) {
        ptr[i] = new A(i * 10);  // Assigning different values
    }

    // Accessing the objects
    for (int i = 0; i < 5; i++) {
        ptr[i]->display();
    }

    // Freeing allocated memory
    for (int i = 0; i < 5; i++) {
        delete ptr[i];  // Deleting each object
    }

    return 0;
}
