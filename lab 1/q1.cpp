#include <iostream>
using namespace std;
class bankaccount
{
private:
    float balance;

public:
    bankaccount()
    {
        balance = 100;
    }
    bankaccount(float a)
    {
        balance = a;
    }
    bankaccount(bankaccount &other)
    {
        balance = other.balance;
    }
    void remove(float a)
    {
        if (a <= balance)
        {
            balance -= a;
        }
        else
            cout << "error";
            cout<<endl<<"balance of acc 3 is:"<<balance<<endl;
    }
    float getbalance()
    {
        return balance;
    }
};
int main()
{
    bankaccount account1;
    cout <<"balance of acc1 is:"<< account1.getbalance() << endl;
    bankaccount account2(1000);
    bankaccount account3(account2);
    account3.remove(200);
    cout << "balance of acc2 is:"<<account2.getbalance();

   
}