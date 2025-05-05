# include<iostream>
# include<string>
using namespace std;

class Wallet
{
    private:
    double balance;
    public:
    Wallet()
    {
        balance=0.0;
    }
    void deposit(double amount)
    {
        if(amount<=0)
        {
          cout<<"Invalid amount to deposit"<<endl;
        }
        else
        {
            balance+=amount;
        }
    }
    double withdraw(double amount)
    {
        if(amount<=0 ||amount>balance)
        {
          cout<<"Invalid amount to withdraw"<<endl;
          return 0;
        } 
        else
        {   balance-=amount;
           return  balance;
        }
    }
};
class User
{
    private:
    Wallet w;
    string name;
    string id;
    public:
    User(string n, string id):id(id),name(n){}
    double userwithdrwa(double amount)
    {
       double v=w.withdraw(amount);
       return v;
    }
    double userdeposit(double amount)
    {
       w.deposit(amount);
    }
   
   
};
int main()
{
    User u("isbah","k24-0698");
    u.userdeposit(100);
    double withdraw=u.userwithdrwa(20);
    cout<<"remaining amount"<<withdraw;
}