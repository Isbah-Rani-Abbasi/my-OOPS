#include <iostream>
#include <string>
using namespace std;

class matrix {
private:
    int rows;
    int cols;
    int **arr;

public:
    // Constructor
    matrix(int rows = 0, int cols = 0) : rows(rows), cols(cols) {
        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = 0; // Initialize elements to 0
            }
        }
    }

    // Copy constructor (deep copy)
    matrix(const matrix& m) {
        rows = m.rows;
        cols = m.cols;
        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = m.arr[i][j];
            }
        }
    }

    // Assignment operator (deep copy)
    matrix& operator=(const matrix& other) {
        if (this == &other) return *this; // Self-assignment check

        // Clean up old memory
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;

        // Allocate new memory and copy data
        rows = other.rows;
        cols = other.cols;
        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                arr[i][j] = other.arr[i][j];
            }
        }

        return *this;
    }

    void setrows(int r) {
        rows = r;
    }

    void setcols(int c) {
        cols = c;
    }

    int getrows() {
        return rows;
    }

    int getcols() {
        return cols;
    }

    void setelement(int i, int j, int element) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            arr[i][j] = element;
        } else {
            cerr << "Index out of bounds!" << endl;
        }
    }

    matrix add(const matrix& m) {
        if (m.rows != rows || m.cols != cols) {
            cerr << "Matrix sizes do not match for addition!" << endl;
            return matrix(0, 0);
        }

        matrix temp(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp.arr[i][j] = arr[i][j] + m.arr[i][j];
            }
        }
        return temp;
    }

    matrix multiply(const matrix& m) {
        if (cols != m.rows) {
            cerr << "Matrix sizes do not match for multiplication!" << endl;
            return matrix(0, 0);
        }

        matrix temp(rows, m.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                temp.arr[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    temp.arr[i][j] += arr[i][k] * m.arr[k][j];
                }
            }
        }
        return temp;
    }

    void display() {
        if (rows == 0 || cols == 0) {
            cout << "Empty matrix" << endl;
            return;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Destructor
    ~matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

int main() {
    // Create two matrices dynamically
    matrix* m = new matrix[2]{matrix(2, 2), matrix(2, 2)};

    // Fill matrix m[0]
    m[0].setelement(0, 0, 1);
    m[0].setelement(0, 1, 2);
    m[0].setelement(1, 0, 3);
    m[0].setelement(1, 1, 4);

    // Fill matrix m[1]
    m[1].setelement(0, 0, 5);
    m[1].setelement(0, 1, 6);
    m[1].setelement(1, 0, 7);
    m[1].setelement(1, 1, 8);

    // Display both matrices
    cout << "Matrix 1:" << endl;
    m[0].display();

    cout << "Matrix 2:" << endl;
    m[1].display();

    // Perform addition
    matrix sum = m[0].add(m[1]);
    cout << "Sum of matrices:" << endl;
    sum.display();

    // Perform multiplication
    matrix product = m[0].multiply(m[1]);
    cout << "Product of matrices:" << endl;
    product.display();

    // Clean up memory
    delete[] m;

    return 0;
}
