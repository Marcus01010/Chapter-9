#include
using namespace std;

class BankAccount
{
private:
float balance;

public:
BankAccount()
{
balance = 0;
}

void deposit(float amount)
{
    if (amount > 0)
    {
        balance += amount;
    }
}

void withdraw(float amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
    }
    else
    {
        cout << "Insufficient balance!" << endl;
    }
}

void display_balance()
{
    cout << "Current Balance: " << balance << endl;
}
};

int main()
{
BankAccount account_1;

account_1.deposit(500);
account_1.display_balance();

account_1.withdraw(200);
account_1.display_balance();

account_1.withdraw(1000);

return 0;
}
