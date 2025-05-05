#include <iostream>
#include <string>
using namespace std;

class Pastry {
protected:
    string name;
    string ingredients[3];
    int ingredientCount;
    double productionCost;
    double totalCostValue;
    double retailPriceValue;
    double retailProfitValue;

public:
    Pastry() {}
    Pastry(string n, string ingr[], int count, double cost)
        : name(n), ingredientCount(count), productionCost(cost) {
        for (int i = 0; i < count && i < 3; i++) {
            ingredients[i] = ingr[i];
        }
    }

    virtual void calculateTotalCost() = 0;
    virtual void calculateRetailPrice() = 0;
    virtual void calculateProfit() = 0;
    virtual void display() = 0;

    double getRetailProfitValue() const {
        return retailProfitValue;
    }

    friend void PastryCalculator(Pastry& obj);
    friend class PastryReport;
};

class SweetPastry : public Pastry {
public:
    SweetPastry(string n, string ingr[], int count, double cost)
        : Pastry(n, ingr, count, cost) {}

    void calculateTotalCost() override {
        totalCostValue = productionCost * 1.10;
    }

    void calculateRetailPrice() override {
        retailPriceValue = totalCostValue * 1.14;
    }

    void calculateProfit() override {
        retailProfitValue = (retailPriceValue - totalCostValue) * 0.70;
    }

    void display() override {
        cout << "Sweet Pastry: " << name << "\n"
             << "Total Cost: " << totalCostValue << "\n"
             << "Retail Price: " << retailPriceValue << "\n"
             << "Profit (70% retained): " << retailProfitValue << "\n\n";
    }
};

class SavoryPastry : public Pastry {
public:
    SavoryPastry(string n, string ingr[], int count, double cost)
        : Pastry(n, ingr, count, cost) {}

    void calculateTotalCost() override {
        totalCostValue = productionCost * 1.10;
    }

    void calculateRetailPrice() override {
        retailPriceValue = totalCostValue * 1.11;
    }

    void calculateProfit() override {
        retailProfitValue = (retailPriceValue - totalCostValue) * 0.70;
    }

    void display() override {
        cout << "Savory Pastry: " << name << "\n"
             << "Total Cost: " << totalCostValue << "\n"
             << "Retail Price: " << retailPriceValue << "\n"
             << "Profit (70% retained): " << retailProfitValue << "\n\n";
    }
};

void PastryCalculator(Pastry& obj) {
    obj.calculateTotalCost();
    obj.calculateRetailPrice();
    obj.calculateProfit();
}

class PastryReport {
public:
    void generateReport(Pastry& obj) {
        obj.display();
    }
};

class PastryShop {
    Pastry* pastries[10];
    int count;

public:
    PastryShop() : count(0) {}

    void addPastry(Pastry* p) {
        if (count < 10) {
            pastries[count++] = p;
        }
    }

    void calculateAll() {
        for (int i = 0; i < count; i++) {
            PastryCalculator(*pastries[i]);
        }
    }

    void displayAll() {
        calculateAll();
        for (int i = 0; i < count; i++) {
            pastries[i]->display();
        }
    }

    void totalProfit() {
        calculateAll();
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += pastries[i]->getRetailProfitValue();
        }
        cout << "🔸 Total Profit from All Pastries: AED " << total << endl;
    }
};

int main() {
    string ingredients1[3] = { "Flour", "Sugar", "Butter" };
    string ingredients2[3] = { "Cheese", "Salt", "Dough" };

    SweetPastry sweet("Chocolate Tart", ingredients1, 3, 20.0);
    SavoryPastry savory("Spinach Pie", ingredients2, 3, 15.0);

    PastryCalculator(sweet);
    PastryCalculator(savory);

    PastryReport report;
    report.generateReport(sweet);
    report.generateReport(savory);

    PastryShop shop;
    shop.addPastry(&sweet);
    shop.addPastry(&savory);

    cout << "\n🎂 All Pastry Details:\n";
    shop.displayAll();

    shop.totalProfit();

    return 0;
}