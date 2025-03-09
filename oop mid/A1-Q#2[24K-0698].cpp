#include <iostream>
#include <string>
using namespace std;

class Ball {
private:
    int x, y;

public:
    Ball() : x(0), y(0) {} 


    int getX() const { return x; }

 
    int getY() const { return y; }
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
    void resetPosition() {
        x = 0;
        y = 0;
    }
};

class Goal {
private:
    int x, y;

public:
    Goal() : x(3), y(3) {}

    
    bool isGoalReached(int ballX, int ballY) const {
        return ballX == x && ballY == y;
    }
};

class Robot {
private:
    string name;
    int hits;

public:
    Robot(string n) : name(n), hits(0) {}

    
    string getName() const { return name; }

   
    int getHits() const { return hits; }
  
    void hitBall(Ball &ball, const string &direction) {
        if (direction == "up" || direction == "UP") {
            ball.move(0, 1);
        } else if (direction == "down" || direction == "DOWN") {
            ball.move(0, -1); 
        } else if (direction == "left" || direction == "LEFT") {
            ball.move(-1, 0); 
        } else if (direction == "right" || direction == "RIGHT") {
            ball.move(1, 0); 
        }
        hits++; 
    }
};

class Team {
private:
    string name;
    Robot *robot;

public:
    Team() : robot(nullptr) {}
    Team(string n, Robot *r) : name(n), robot(r) {}

   
    string getName() const { return name; }

  
    Robot* getRobot() const { return robot; }
};

class Game {
private:
    Team *team1;
    Team *team2;
    Ball ball;
    Goal goal;

   
    void play(Team *team) {
        Robot *robot = team->getRobot();
        cout << team->getName() << " is playing!" << endl;

       
        ball.resetPosition();

      
        while (!goal.isGoalReached(ball.getX(), ball.getY())) {
            string direction;
            cout << "Enter the direction for " << robot->getName() << " (up/down/left/right): ";
            cin >> direction;

        
            while (direction != "up" && direction != "down" && direction != "left" && direction != "right" &&
                   direction != "UP" && direction != "DOWN" && direction != "LEFT" && direction != "RIGHT") {
                cout << "Invalid direction! Please enter (up/down/left/right): ";
                cin >> direction;
            }

            robot->hitBall(ball, direction);
            cout << robot->getName() << " hits the ball! Ball position: (" << ball.getX() << ", " << ball.getY() << ")" << endl;
        }

        cout << robot->getName() << " has reached the goal with " << robot->getHits() << " hits!" << endl << endl;
    }

public:
    Game(Team *T1, Team *T2) : team1(T1), team2(T2) {}

 
    void startGame() {
   
        play(team1);
        play(team2);

        declareWinner();
    }

  
    void declareWinner() {
        int hitsTeam1 = team1->getRobot()->getHits();
        int hitsTeam2 = team2->getRobot()->getHits();

        if (hitsTeam1 < hitsTeam2) {
            cout << team1->getName() << " wins the game with fewer hits!" << endl;
        } else if (hitsTeam1 > hitsTeam2) {
            cout << team2->getName() << " wins the game with fewer hits!" << endl;
        } else {
            cout << "The match is a tie! Both teams took the same number of hits." << endl;
        }
    }
};

int main() {
    string t1Name, t2Name, r1Name, r2Name;

    
    cout << "Enter name for Team 1: ";
    cin >> t1Name;
    cout << "Enter name for Robot in Team 1: ";
    cin >> r1Name;

    cout << "Enter name for Team 2: ";
    cin >> t2Name;
    cout << "Enter name for Robot in Team 2: ";
    cin >> r2Name;

    
    Robot r1(r1Name);
    Robot r2(r2Name);

    
    Team team1(t1Name, &r1);
    Team team2(t2Name, &r2);

    
    Game game(&team1, &team2);

 
    game.startGame();

    return 0;
}
