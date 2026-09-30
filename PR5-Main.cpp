#include <iostream>
#include "PR5.cpp"
using namespace std;

int main()
{
    LibraryItem* libraryItems[MAX_ITEMS];
    int count = 0;
    int choice;

    do
    {
        cout << "\n========== Library Management System ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Check Out Item\n";
        cout << "6. Return Item\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try
        {
            if (choice == 1)
            {
                string title, author, dueDate, isbn;

                cin.ignore();

                cout << "Enter Title: ";
                getline(cin, title);

                cout << "Enter Author: ";
                getline(cin, author);

                cout << "Enter Due Date (DD/MM/YYYY): ";
                getline(cin, dueDate);

                cout << "Enter 13-digit ISBN: ";
                getline(cin, isbn);

                libraryItems[count] = new Book(title, author, dueDate, isbn);
                count++;

                cout << "Book Added Successfully.\n";
            }

            else if (choice == 2)
            {
                string title, author, dueDate;
                int duration;

                cin.ignore();

                cout << "Enter Title: ";
                getline(cin, title);

                cout << "Enter Author: ";
                getline(cin, author);

                cout << "Enter Due Date (DD/MM/YYYY): ";
                getline(cin, dueDate);

                cout << "Enter Duration (minutes): ";
                cin >> duration;

                libraryItems[count] = new DVD(title, author, dueDate, duration);
                count++;

                cout << "DVD Added Successfully.\n";
            }

            else if (choice == 3)
            {
                string title, author, dueDate;
                int issue;

                cin.ignore();

                cout << "Enter Title: ";
                getline(cin, title);

                cout << "Enter Author: ";
                getline(cin, author);

                cout << "Enter Due Date (DD/MM/YYYY): ";
                getline(cin, dueDate);

                cout << "Enter Issue Number: ";
                cin >> issue;

                libraryItems[count] = new Magazine(title, author, dueDate, issue);
                count++;

                cout << "Magazine Added Successfully.\n";
            }

            else if (choice == 4)
            {
                if (count == 0)
                {
                    cout << "No Library Items Available.\n";
                }
                else
                {
                    for (int i = 0; i < count; i++)
                    {
                        cout << "\nItem " << i + 1 << endl;
                        libraryItems[i]->displayDetails();
                    }
                }
            }

            else if (choice == 5)
            {
                int item;

                if (count == 0)
                {
                    cout << "No Items Available.\n";
                }
                else
                {
                    cout << "Enter Item Number: ";
                    cin >> item;

                    if (item < 1 || item > count)
                        throw "Invalid Item Number.";

                    libraryItems[item - 1]->checkOut();
                }
            }

            else if (choice == 6)
            {
                int item;

                if (count == 0)
                {
                    cout << "No Items Available.\n";
                }
                else
                {
                    cout << "Enter Item Number: ";
                    cin >> item;

                    if (item < 1 || item > count)
                        throw "Invalid Item Number.";

                    libraryItems[item - 1]->returnItem();
                }
            }

            else if (choice == 7)
            {
                cout << "Exiting Program...\n";
            }

            else
            {
                cout << "Invalid Choice.\n";
            }
        }

        catch (const char* msg)
        {
            cout << "Error: " << msg << endl;
        }

        catch (...)
        {
            cout << "An unexpected error occurred.\n";
        }

    } while (choice != 7);

    for (int i = 0; i < count; i++)
    {
        delete libraryItems[i];
    }

    return 0;
}