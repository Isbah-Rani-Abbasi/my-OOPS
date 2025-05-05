#include <iostream>
#include <string>
using namespace std;

class Course {
protected:
    string name;
    string courseCode;
    int creditHours;

public:
    Course(string name, string courseCode, int creditHours)
        : name(name), courseCode(courseCode), creditHours(creditHours) {}

    virtual string getName() const = 0;
    virtual string getCourseCode() const = 0;
    virtual int getCreditHours() const = 0;
    virtual ~Course() {}
};

class CoreCourse : public Course {
public:
    CoreCourse(string name, string courseCode, int creditHours)
        : Course(name, courseCode, creditHours) {}

    string getName() const override { return name; }
    string getCourseCode() const override { return courseCode; }
    int getCreditHours() const override { return creditHours; }
};

class ElectiveCourse : public Course {
public:
    ElectiveCourse(string name, string courseCode, int creditHours)
        : Course(name, courseCode, creditHours) {}

    string getName() const override { return name; }
    string getCourseCode() const override { return courseCode; }
    int getCreditHours() const override { return creditHours; }
};

class Prerequisite {
    string requiredCourses[3];

public:
    Prerequisite() {
        requiredCourses[0] = "ENG101";
        requiredCourses[1] = "SCI101";
        requiredCourses[2] = "PF101";
    }

    void checkPrerequisite(const Course* course, const string completedCourses[], int numCompleted) {
        if (course->getCourseCode() == "CS201") {
            bool found = false;
            for (int i = 0; i < numCompleted; ++i) {
                if (completedCourses[i] == "PF101") {
                    found = true;
                    break;
                }
            }
            if (found)
                cout << course->getName() << " - Eligible (Prerequisite met)" << endl;
            else
                cout << course->getName() << " - Not eligible (PF101 required)" << endl;
        }
    }
};

class ComputerScienceCoreCourse : public CoreCourse {
public:
    ComputerScienceCoreCourse()
        : CoreCourse("Computer Science", "CS201", 3) {}
};

class MathematicsCoreCourse : public CoreCourse {
public:
    MathematicsCoreCourse()
        : CoreCourse("Mathematics", "MATH201", 3) {}
};

template <typename T>
class CourseCatalog {
    T** courses;
    int count;
    int capacity;

public:
    CourseCatalog() : courses(nullptr), count(0), capacity(0) {}

    ~CourseCatalog() {
        for (int i = 0; i < count; ++i)
            delete courses[i];
        delete[] courses;
    }

    void addCourse(T* course) {
        if (count == capacity) {
            capacity = (capacity == 0) ? 2 : 2 * capacity;
            T** temp = new T*[capacity];
            for (int i = 0; i < count; ++i)
                temp[i] = courses[i];
            delete[] courses;
            courses = temp;
        }
        courses[count++] = course;
    }

    void displayCourses() const {
        cout << "Courses in Catalog:\n";
        for (int i = 0; i < count; ++i) {
            cout << "- " << courses[i]->getName() << " (" << courses[i]->getCourseCode()
                 << "), Credit Hours: " << courses[i]->getCreditHours() << endl;
        }
    }

    void totalCreditHours() const {
        int total = 0;
        for (int i = 0; i < count; ++i)
            total += courses[i]->getCreditHours();
        cout << "Total Credit Hours: " << total << endl;
    }

    void checkEligibility(const string completed[], int numCompleted) const {
        Prerequisite pre;
        for (int i = 0; i < count; ++i)
            pre.checkPrerequisite(courses[i], completed, numCompleted);
    }
};

// MAIN FUNCTION
int main() {
    CourseCatalog<Course> catalog;

    catalog.addCourse(new ComputerScienceCoreCourse());
    catalog.addCourse(new MathematicsCoreCourse());
    catalog.addCourse(new ElectiveCourse("Philosophy", "HUM101", 2));

    catalog.displayCourses();
    catalog.totalCreditHours();

    string completedCourses[] = { "ENG101", "PF101" };
    catalog.checkEligibility(completedCourses, 2);

    return 0;
}
