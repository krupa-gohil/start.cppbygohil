#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // constructor
    BankAccount(int accNo, string name, double bal)
    {
        this->accountNumber = accNo;
        this->accountHolderName = name;
        this->balance = bal;
    }

    // deposit
    virtual void deposit(double amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;
            cout << "Amount deposited sucessfully!" << endl;
        }
        else
        {
            cout << "Invalid amount!" << endl;
        }
    }

    // withdraw
    virtual void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount withdraw sucessfully!" << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    // get balance
    double getBalance()
    {
        return balance;
    }

    // display account information
    void displayAccountInfo()
    {
        cout << "--------------------------------------" << endl;
        cout << "Account Number : " << this->accountNumber << endl;
        cout << "Account Holder : " << this->accountHolderName << endl;
        cout << "Balance : " << this->balance << endl;
        cout << "---------------------------------------" << endl;
    }

    // virtual function for polymorphism
    virtual double calculateInterest()
    {
        return 0;
    }

    // virtual destructor
    virtual ~BankAccount()
    {
    }
};

// child class : saving account

class SavingAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingAccount(int accNo, string name, double bal, double rate) : BankAccount(accNo, name, bal)
    {
        interestRate = rate;
    }

    // calculate interest
    double calculateInterest() override
    {
        return balance * interestRate / 100;
    }

    void displaySavings()
    {
        displayAccountInfo();
        cout << "Interest Rate : " << this->interestRate << endl;
        cout << "Interest : " << calculateInterest() << endl;
    }
};

// child class : checking account
class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit) : BankAccount(accNo, name, bal)
    {
        overdraftLimit = limit;
    }

    // chech overdraft
    void checkOverdraft(double amount)
    {
        if (amount = balance + overdraftLimit)
        {
            cout << "Withdrawal exceeds overdraft limit!" << endl;
        }
    }

    void displayChecking()
    {
        displayAccountInfo();
        cout << "Overdraft Limit : " << this->overdraftLimit << endl;
    }
};

// child class : fixed deposite
class FixedDepositeAccount : public BankAccount
{
private:
    int term;

public:
    FixedDepositeAccount(int accNo, string name, double bal, int months) : BankAccount(accNo, name, bal)
    {
        term = months;
    }

    // calculate fixed deposite interest
    double calculateInterest() override
    {
        double rate = 7.0;

        return balance * rate * term / (12 * 100);
    }

    void displayFixedDeposite()
    {
        displayAccountInfo();
        cout << "Term : " << this->term << "months" << endl;
        cout << "Interest : " << calculateInterest() << endl;
    }
};