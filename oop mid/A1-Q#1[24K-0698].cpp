#include <iostream>
#include <string>
using namespace std;

const int MAX_SPORTS = 20;
const int MAX_LEARNERS = 20;
const int MAX_SKILLS = 20;

// Forward declarations because we use all classe with each other
class Skill;
class Mentor;
class Student;
class Sport;

class Skill {
private:
    int skillID;
    string skillName;
    string description;

public:
    Skill(int sID, string sName, string sdesc) : skillID(sID), skillName(sName), description(sdesc) {}

    void showSkillDetails() {
        cout << "The skill ID is: " << skillID << endl;
        cout << "The skill name is: " << skillName << endl;
        cout << "The skill description is: " << description << endl;
    }

    void updateSkillDescription(string newDescription) {
        description = newDescription;
    }

    int getSkillID() const
    {
        return skillID;
    }
    string getSkillName() const
    {
        return skillName;
    }

};

class Sport {
private:
    int sportID;
    string name;
    string description;
    Skill* requiredSkill[MAX_SKILLS];
    int skillCount;

public:
    Sport() : skillCount(0) {}

    Sport(int id, string n, string desc) : sportID(id), name(n), description(desc), skillCount(0) {}

    int getSportID() const
    {
        return sportID;
    }
    string getSportName() const
    {
        return name;
    }

    void addSkill(Skill* s) {
        if (skillCount < MAX_SKILLS) {
            requiredSkill[skillCount++] = s;
        } else {
            cout << "Skill capacity is full!" << endl;
        }
    }

    void removeSkill(Skill* s) {
        for (int i = 0; i < skillCount; i++) {
            if (requiredSkill[i] == s) {
                for (int j = i; j < skillCount - 1; j++) {
                    requiredSkill[j] = requiredSkill[j + 1];
                }
                --skillCount;
                break;
            }
        }
    }
};

class Mentor {
private:
    int mentorID;
    string name;
    Sport* sportExpertise[MAX_SPORTS];
    int maxLearners;
    int learnerCount;
    Student* assignedLearners[MAX_LEARNERS];
    int sportCount; // Track the number of sports

public:
    Mentor(int id, string n, int max, Sport* expertise[], int expertiseCount)
        : mentorID(id), name(n), maxLearners(max), learnerCount(0), sportCount(expertiseCount) {
        for (int i = 0; i < expertiseCount; ++i) {
            sportExpertise[i] = expertise[i];
        }
    }

    bool assignLearner(Student* student) {
        if (learnerCount < maxLearners) {
            assignedLearners[learnerCount++] = student;
            return true;
        }
        return false;
    }

    void removeLearner(Student* student) {
        for (int i = 0; i < learnerCount; ++i) {
            if (assignedLearners[i] == student) {
                for (int j = i; j < learnerCount - 1; ++j) {
                    assignedLearners[j] = assignedLearners[j + 1];
                }
                --learnerCount;
                return;
            }
        }
    }

    void viewLearners() const;

    void provideGuidance() const {
        cout << "Mentor " << name << " is providing guidance." << endl;
    }

    string getName() const { return name; }
    int getMentorID() const { return mentorID; }
    int getSportCount() const { return sportCount; } // Return sportCount
    Sport* getSport(int index) const {
        if (index >= 0 && index < sportCount) { // Use sportCount
            return sportExpertise[index];
        }
        return nullptr;
    }
};

class Student {
private:
    int studentID;
    string name;
    float age;
    Sport* sportInterest[MAX_SPORTS];
    int interestcount;
    Mentor* mentorAssigned;

public:
    Student(int id, const string& Name, float Age, Sport* interests[], int interestsCount)
        : studentID(id), name(Name), age(Age), interestcount(interestsCount), mentorAssigned(nullptr) {
        for (int i = 0; i < interestsCount; i++) {
            sportInterest[i] = interests[i];
        }
    }

    void registerForMentorship(Mentor& mentor);
    void viewMentorDetails() const;
    void updateSportsInterest(Sport* sport);

    string getName() const { return name; }
};

void Student::registerForMentorship(Mentor& mentor) {
    if (mentor.assignLearner(this)) {
        mentorAssigned = &mentor;
        cout << name << " Registered for mentorship with " << mentor.getName() << "." << endl;
    } else {
        cout << "Mentor " << mentor.getName() << " is at full capacity." << endl;
    }
}

void Student::viewMentorDetails() const {
    if (mentorAssigned) {
        cout << "Mentor Details:" << endl;
        cout << "Name: " << mentorAssigned->getName() << endl;
        cout << "Mentor ID: " << mentorAssigned->getMentorID() << endl;
        cout << "Sports Expertise:" << endl;
        for (int i = 0; i < mentorAssigned->getSportCount(); ++i) {
            if (mentorAssigned->getSport(i))
                cout << "- " << mentorAssigned->getSport(i)->getSportName() << endl;
        }
    } else {
        cout << "No mentor assigned." << endl;
    }
}

void Student::updateSportsInterest(Sport* sport) {
    if (interestcount < MAX_SPORTS) {
        sportInterest[interestcount++] = sport;
    }
}

void Mentor::viewLearners() const {
    cout << "Assigned Learners for Mentor " << name << ":" << endl;
    for (int i = 0; i < learnerCount; ++i) {
        cout << "- " << assignedLearners[i]->getName() << endl;
    }
}

int main() {
    // Skill Objects
    Skill tennisSkill1(1, "Forehand", "Basic forehand technique.");
    Skill tennisSkill2(2, "Backhand", "Basic backhand technique.");

    // Sport Objects
    Sport tennis(1, "Tennis", "A racket sport.");
    tennis.addSkill(&tennisSkill1);
    tennis.addSkill(&tennisSkill2);

    Skill badmintonSkill1(3, "Serve", "Basic badminton serve.");
    Sport badminton(2, "Badminton", "Another racket sport.");
    badminton.addSkill(&badmintonSkill1);

    // Mentor and Student Initialization
    Sport* aliExpertise[] = { &tennis };
    Mentor ali(1, "Ali", 3, aliExpertise, 1);

    Sport* saadInterests[] = { &tennis };
    Student saad(101, "Saad", 20, saadInterests, 1);

    Sport* ahmedInterests[] = { &tennis, &badminton };
    Student ahmed(102, "Ahmed", 21, ahmedInterests, 2);

    Sport* omerInterests[] = { &tennis };
    Student omer(103, "Omer", 22, omerInterests, 1);

    Sport* usmanInterests[] = { &tennis };
    Student usman(104, "Usman", 23, usmanInterests, 1);

    // Registering for mentorship
    saad.registerForMentorship(ali);
    ahmed.registerForMentorship(ali);
    omer.registerForMentorship(ali);
    usman.registerForMentorship(ali);

    // Viewing Learners
    ali.viewLearners();
    saad.viewMentorDetails();

    // Removing a learner and registering a new one
    ali.removeLearner(&saad);
    usman.registerForMentorship(ali);
    ali.viewLearners();

    return 0;
}

