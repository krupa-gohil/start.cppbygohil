#include "PR4.cpp"

int main()
{
    SavingAccount savings(10101, "Krupa", 78000, 9.6);
    CheckingAccount chechking(10102, "Keval", 42000, 63000);
    FixedDepositeAccount fixedDeposit(10103, "Khushi", 230000, 18);

    int choice;
    double amount;

    do
    {
        cout << "---------------------------------------------" << endl;
        cout << "----------BANK ACCOUNT MANEGEMENT------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "1.Display Saving Account" << endl;
        cout << "2.Display Checking Account" << endl;
        cout << "3.Display Fixed Deposit Amount" << endl;
        cout << "4.Deposit in Saving Account" << endl;
        cout << "5.Withdraw from Saving Account" << endl;
        cout << "6.Withdraw from Checking account" << endl;
        cout << "7.Caculate Interest" << endl;
        cout << "8.Exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            savings.displaySavings();
            break;

        case 2:
            chechking.displayChecking();
            break;

        case 3:
            fixedDeposit.displayFixedDeposite();
            break;

        case 4:
            cout << "Enter amount to deposit : ";
            cin >> amount;
            savings.deposit(amount);
            break;

        case 5:
            cout << "Enter amount to withdraw :";
            cin >> amount;
            savings.withdraw(amount);
            break;

        case 6:
            cout << "Enter amount to withdraw :";
            cin >> amount;
            chechking.checkOverdraft(amount);
            break;

        case 7:
            cout << "------INTEREST CALCULATION------" << endl;

            // patent class pointer
            BankAccount *ptr;

            // savings account
            ptr = &savings;

            cout << "Savingd Account Interest = " << ptr->calculateInterest() << endl;

            // fixed deposit account
            ptr = &fixedDeposit;

            cout << "Fixed Deposit Interest = " << ptr->calculateInterest() << endl;
            cout << endl;
            break;

        case 8:
            cout << "Thank you for using Bank System!";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 8);
    return 0;
}