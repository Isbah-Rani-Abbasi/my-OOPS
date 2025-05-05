#include <iostream>
#include <string>
using namespace std;

class sort {
    int n;
    int *ptr;

public:
    sort() : n(0), ptr(nullptr) {}

    sort(int n) : n(n) {
        ptr = new int[n];
        for (int i = 0; i < n; i++) {
            ptr[i] = 0;
        }
    }

    // Destructor
    ~sort() {
        delete[] ptr;
    }

    // Copy Constructor
    sort(const sort &obj) {
        n = obj.n;
        ptr = new int[n];
        for (int i = 0; i < n; i++) {
            ptr[i] = obj.ptr[i];
        }
    }

    // Copy Assignment
    sort &operator=(const sort &obj) {
        if (this == &obj)
            return *this;

        delete[] ptr;
        n = obj.n;
        ptr = new int[n];
        for (int i = 0; i < n; i++) {
            ptr[i] = obj.ptr[i];
        }

        return *this;
    }

    // Move Constructor
    sort(sort &&obj) noexcept {
        n = obj.n;
        ptr = obj.ptr;
        obj.ptr = nullptr;
        obj.n = 0;
    }

    // Move Assignment
    sort &operator=(sort &&obj) noexcept {
        if (this == &obj)
            return *this;

        delete[] ptr;
        n = obj.n;
        ptr = obj.ptr;

        obj.n = 0;
        obj.ptr = nullptr;

        return *this;
    }

    void setarray(int *arr, int size) {
        if (size == n) {
            for (int i = 0; i < n; i++) {
                ptr[i] = arr[i];
            }
        } else {
            cout << "Size of array is wrong" << endl;
        }
    }

    void sortarray() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (ptr[j] > ptr[j + 1]) {
                    int temp = ptr[j];
                    ptr[j] = ptr[j + 1];
                    ptr[j + 1] = temp;
                }
            }
        }
    }

    void display() const {
        for (int i = 0; i < n; i++) {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

    int *getarray() {
        return ptr;
    }
};

int main() {
    sort s(3);
    sort s1(4);

    int arr[3] = {3, 2, 1};
    int arr1[4] = {4, 3, 2, 1};

    s.setarray(arr, 3);
    s1.setarray(arr1, 4);

    s.sortarray();
    s.display(); // Output: 1 2 3

    s = s1;
    s.display(); // Output: 4 3 2 1 (copied from s1)

    return 0;
}
