#include<iostream>
#include<string>
using namespace std;

class HauntedHouse; // Forward declaration

class Ghost {
protected:
    string PlayeName;
    int HorrorLevel;

public:
    Ghost() {
        HorrorLevel = 0;
        PlayeName = "xyz";
    }

    Ghost(string n, int h) {
        PlayeName = n;
        if (h > 0 && h <= 10) {
            HorrorLevel = h;
        }
        else {
            HorrorLevel = 0;
        }
    }

    void setHorrorLevel(int h) {
        if (h > 0 && h <= 10) {
            HorrorLevel = h;
        }
        else {
            cout << "Please Enter valid horror level from 1-10!" << endl;
        }
    }

    void setName(string n) {
        PlayeName = n;
    }

    virtual void haunt() {
        cout << PlayeName << " with generic ghost makes awwwwww noise!" << endl;
    }

    int getHorrorLevel() {
        return HorrorLevel;
    }

    // Operator to add two ghosts
    Ghost operator +(const Ghost& obj) {
        Ghost temp;
        if (HorrorLevel + obj.HorrorLevel <= 10) {
            temp.HorrorLevel = HorrorLevel + obj.HorrorLevel;
            temp.PlayeName = PlayeName; // Keeping the name of the first ghost
            return temp;
        }
        else {
            cout << "Can't add two ghosts" << endl;
            return temp;
        }
    }

    friend ostream& operator <<(ostream& out, const Ghost& obj);
};

ostream& operator <<(ostream& out, const Ghost& obj) {
    out << "The name of Ghost: " << obj.PlayeName << endl;
    out << "The Horror Level of Ghost: " << obj.HorrorLevel << endl;
    return out;
}

class ShadowPoltergeist : public Ghost {
public:
    ShadowPoltergeist(string n, int h) : Ghost(n, h) {}
    void haunt() override {
        cout << PlayeName << " using Shadow Poltergeist which haunts by moving objects!" << endl;
    }
};

class Banshees : public Ghost {
public:
    Banshees(string n, int h) : Ghost(n, h) {}
    void haunt() override {
        cout << PlayeName << " using Banshees which haunts by screaming loudly!" << endl;
    }
};

class ShadowGhost : public Ghost {
public:
    ShadowGhost(string n, int h) : Ghost(n, h) {}
    void haunt() override {
        cout << PlayeName << " using Shadow Ghost which haunts by whispering creepily!" << endl;
    }
};

class Visitor {
protected:
    string visitorName;
    int bravery;

public:
    Visitor() : bravery(5) {}  // Default bravery level

    void setBravery(int level) {
        bravery = level;
    }

    void ScaringVisitor(int scareLevel) {
        if (scareLevel < bravery) {
            cout << "Hahahahaha! Do you think you can scare me, you dumb ghost!" << endl;
        }
        else if (scareLevel > bravery) {
            cout << "AAAAAAAAAAA! God Save me!" << endl;
        }
        else {
            cout << "EEEEEEEEEE! Stay away from me!" << endl;
        }
    }

    friend void Visit(Visitor* v, int count, HauntedHouse& h);
};

class HauntedHouse {
protected:
    string name;
    Ghost** gh;
    int ghostcount;
    int ghostcapacity;

public:
    HauntedHouse(string n) : name(n), ghostcount(0), ghostcapacity(0) {
        gh = nullptr;
    }

    void addGhost(Ghost* g) {
        if (ghostcapacity == ghostcount) {
            ghostcapacity = (ghostcapacity == 0) ? 1 : 2 * ghostcapacity;
            Ghost** temp = new Ghost * [ghostcapacity];
            for (int i = 0; i < ghostcount; i++) {
                temp[i] = gh[i];
            }
            delete[] gh;
            gh = temp;
        }
        gh[ghostcount++] = g;
    }

    void HauntVisitor(Visitor v[], int n) {
        cout << "Welcome to " << name << ", Free therapy after you leave, you will need it :)" << endl;
        for (int i = 0; i < ghostcount; i++) {
            gh[i]->haunt();
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            v[i].ScaringVisitor(gh[i]->getHorrorLevel());
        }
    }
};

void Visit(Visitor v[], int count, HauntedHouse& h) {
    h.HauntVisitor(v, count);
}

int main() {
    cout<<"The biggest ghost out there "<<" Isbah Rani Abbasi"<<endl<<"K24-0698"<<endl;
    
    Ghost g1("Ghost1", 5);
    Ghost g2("Ghost2", 7);

   
    Ghost g3 = g1 + g2; 

    cout << "Combined Ghost g3: " << endl;
    cout << g3 << endl; 

   
    ShadowPoltergeist sp1("Poltergeist1", 6);
    Banshees b1("Banshee1", 8);
    ShadowGhost sg1("ShadowGhost1", 3);

   
    HauntedHouse hh("Haunted Mansion");

    
    hh.addGhost(&g1);
    hh.addGhost(&g2);
    hh.addGhost(&sp1);
    hh.addGhost(&b1);
    hh.addGhost(&sg1);

    
    Visitor v1, v2, v3;

   
    v1.setBravery(4);
    v2.setBravery(6);
    v3.setBravery(9);


    Visitor visitors[] = { v1, v2, v3 };

   
    Visit(visitors, 3, hh);

    return 0;
}
