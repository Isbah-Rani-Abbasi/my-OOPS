# include<iostream>
# include<string>
using namespace std;

class Pastry
{
    protected:
    string name;
    string ingredients[3];
    int count;
    double productiocost;
    double totalcost;
    double retailprice;
    double retailprofit;

    public:
    Pastry(string n,string ing[],int c,double pc):name(n),count(c),
    productiocost(pc)
    {
        for(int i=0 ;i<count;i++)
        {
            ingredients[i]=ing[i];
        }
    }
    virtual void calculateTotalCost()=0;
    virtual void calulateRetailPrice()=0;
    virtual void calculateRetailProfit()=0;
    virtual void display()=0;
    double getretailprofit()
    {
        return retailprofit;
    }
    friend void Pastrycalculator(Pastry *obj);
    friend class PastryReport;

};
class SweetPastry:public Pastry
{
    public:
    SweetPastry(string n ,string ing[],int c,double pc):
    Pastry(n,ing,c,pc){}
    void calculateTotalCost()
    {
        totalcost=productiocost+(productiocost*0.1);
    }
    void calulateRetailPrice()
    {
        retailprice=totalcost+(totalcost*0.08);
    }
    void calculateRetailProfit()
    {
        retailprofit=totalcost*0.7;
    }
    void display()
    {
        cout<<"Name of pastry:"<<name<<endl;
        cout<<"Prodution cost of pastry:"<<productiocost<<endl;
        cout<<"Total cost of pastry:"<<totalcost<<endl;
        cout<<"Retail price of pastry:"<<retailprice<<endl;
        cout<<"Retail profit of pastry:"<<retailprofit<<endl;
    }

};
class SavourPastry:public Pastry
{
    public:
    SavourPastry(string n ,string ing[],int c,double pc):
    Pastry(n,ing,c,pc){}
    void calculateTotalCost()
    {
        totalcost=productiocost+(productiocost*0.1);
    }
    void calulateRetailPrice()
    {
        retailprice=totalcost+(totalcost*0.05);
    }
    void calculateRetailProfit()
    {
        retailprofit=totalcost*0.7;
    }
   
    void display()
    {
        cout<<"Name of pastry:"<<name<<endl;
        cout<<"Prodution cost of pastry:"<<productiocost<<endl;
        cout<<"Total cost of pastry:"<<totalcost<<endl;
        cout<<"Retail price of pastry:"<<retailprice<<endl;
        cout<<"Retail profit of pastry:"<<retailprofit<<endl;
    }

};
void Pastrycalculator(Pastry *obj)
{
    obj->calculateRetailProfit();
    obj->calculateTotalCost();
    obj->calulateRetailPrice();
}
class PastryReport
{
    public:
    void report(Pastry *obj)
    {
      obj->display();
    }
};
class PastryShop
{
    private:
    Pastry *p[10];
    int count;
    public:
    PastryShop():count(0){}
    void addPastry(Pastry *pa)
    {
        if(count<10)
        {
            p[count++]=pa;
        }
    }
    void calculateAll()
    {
        for(int i=0 ;i<count;i++)
        {
            Pastrycalculator(p[i]);
        }
    }
    void display()
    {
        calculateAll();
        for(int i=0 ;i<count;i++)
        {
            p[i]->display();
        }

    }
    void totalProfit()
    {
        calculateAll();
        double total=0;
        for(int i=0 ;i<count ; i++)
        {
           total+= p[i]->getretailprofit();
        }
    }
};
int main()
{
    string s1[1]={"sugar"};
    string s2[1]={"flour"};
    SweetPastry sw("sweet",s1,1,100);
    SavourPastry sv("savour",s2,1,200);
    Pastrycalculator(&sw);
    Pastrycalculator(&sv);
    PastryReport r;
    r.report(&sv);
    r.report(&sw);
    PastryShop s;
    s.addPastry(&sv);
    s.addPastry(&sw);
    s.display();
    s.totalProfit();
    
}