# include<iostream>
# include<string>
using namespace std;
class BankAccount
{
    private:
    string accountNumber;
    double balance;
   
    public:
     BankAccount()
    {
        balance=0;
    }
    void deposit(double amount)
    {
       balance=amount;
    }
    double getdeposit()
    {
        return balance;
    }
     double checkbalance(double amount)
    {
      if(balance>amount)
      {
        double draw= balance-amount;
        return draw;
      }
      else
      {
        return -1;
      }
    }
     
    void setAccountNumber(string ACnumber)
    {
        accountNumber=ACnumber;
        
    }
    string getAccountNumber()
    {
      return accountNumber;
    }
};
int main()
{
    BankAccount b1;
    string accNumber;
    cout<<"Enter your account number: ";
    cin>>accNumber;
    b1.setAccountNumber(accNumber);
    string Anumber=b1.getAccountNumber();
    double deposit,withdraw,remaining;
    cout<<"Enter the amount you want to depsit: ";
    cin>>deposit;
    cout<<"Enter the amount you want to withdraw: ";
    cin>>withdraw;
    b1.deposit(deposit);
    deposit=b1.getdeposit();
    remaining=b1.checkbalance(withdraw);

    cout<<"Your account number is "<<Anumber<< endl;
    cout<<"Your total deposit  was "<<deposit<< endl;
    if (remaining>0)
    {
        cout<<"Remaining amount is "<<remaining<< endl;
    }
    else
    {
    cout<<"Insufficient amount for withdrawal! "<<endl;

    }
    
    
      return 0;
   


}