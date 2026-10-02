#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d)
    {
        title = t;
        author = a;
        dueDate = d;
    }

    // Getters
    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getDueDate()
    {
        return dueDate;
    }

    // Setters
    void setTitle(string newTitle)
    {
        title = newTitle;
    }

    void setAuthor(string newAuthor)
    {
        author = newAuthor;
    }

    void setDueDate(string newDueDate)
    {
        dueDate = newDueDate;
    }

    // Pure Virtual Functions
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};
//---------------------- Book Class ----------------------

class Book : public LibraryItem
{
private:
    string isbn;

public:
    Book(string t, string a, string d, string i)
        : LibraryItem(t, a, d)
    {
        if (i.length() != 13)
            throw "Invalid ISBN! ISBN must contain 13 digits.";

        isbn = i;
    }

    void checkOut() override
    {
        cout << "Book \"" << getTitle() << "\" checked out successfully.\n";
    }

    void returnItem() override
    {
        cout << "Book \"" << getTitle() << "\" returned successfully.\n";
    }

    void displayDetails() override
    {
        cout << "\n----- Book Details -----\n";
        cout << "Title    : " << getTitle() << endl;
        cout << "Author   : " << getAuthor() << endl;
        cout << "Due Date : " << getDueDate() << endl;
        cout << "ISBN     : " << isbn << endl;
    }
};

//---------------------- DVD Class ----------------------

class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d)
    {
        if (dur <= 0)
            throw "Duration cannot be negative or zero.";

        duration = dur;
    }

    void checkOut() override
    {
        cout << "DVD \"" << getTitle() << "\" checked out successfully.\n";
    }

    void returnItem() override
    {
        cout << "DVD \"" << getTitle() << "\" returned successfully.\n";
    }

    void displayDetails() override
    {
        cout << "\n----- DVD Details -----\n";
        cout << "Title       : " << getTitle() << endl;
        cout << "Author      : " << getAuthor() << endl;
        cout << "Due Date    : " << getDueDate() << endl;
        cout << "Duration    : " << duration << " minutes" << endl;
    }
};

//---------------------- Magazine Class ----------------------

class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d)
    {
        if (issue <= 0)
            throw "Issue number cannot be negative or zero.";

        issueNumber = issue;
    }

    void checkOut() override
    {
        cout << "Magazine \"" << getTitle() << "\" checked out successfully.\n";
    }

    void returnItem() override
    {
        cout << "Magazine \"" << getTitle() << "\" returned successfully.\n";
    }

    void displayDetails() override
    {
        cout << "\n----- Magazine Details -----\n";
        cout << "Title        : " << getTitle() << endl;
        cout << "Author       : " << getAuthor() << endl;
        cout << "Due Date     : " << getDueDate() << endl;
        cout << "Issue Number : " << issueNumber << endl;
    }
};