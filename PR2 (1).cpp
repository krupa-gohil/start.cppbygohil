#include <iostream>
#include <cstring>
using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;

public:
    // default constructor
    Train()
    {
        this->trainNumber = 0;
        strcpy(this->trainName, "");
        strcpy(this->source, "");
        strcpy(this->destination, "");
        strcpy(this->trainTime, "");
    }

    // parameterized constructor

    Train(int trainNumber, char *trainName, char *source,
          char *destination, char *trainTime)
    {
        this->trainNumber = trainNumber;
        strcpy(this->trainName, trainName);
        strcpy(this->source, source);
        strcpy(this->destination, destination);
        strcpy(this->trainTime, trainTime);
        trainCount++;
    }

    // destructor

    ~Train()
    {
        trainCount--;
    }

    // setter

    void setTrainNumber(int trainNumber)
    {
        this->trainNumber = trainNumber;
    }

    void setTrainName(char *trainName)
    {
        strcpy(this->trainName, trainName);
    }

    void setSource(char *source)
    {
        strcpy(this->source, source);
    }

    void setDestination(char *destination)
    {
        strcpy(this->destination, destination);
    }

    void setTrainTime(char *trainTime)
    {
        strcpy(this->trainTime, trainTime);
    }

    // getter

    int getTrainNumber()
    {
        return this->trainNumber;
    }

    char *getTrainName()
    {
        return this->trainName;
    }

    char *getSource()
    {
        return this->source;
    }

    char *getDestination()
    {
        return this->destination;
    }

    char *getTrainTime()
    {
        return this->trainTime;
    }

    // input

    void inputTrainDetails()
    {
        cout << "Enter train number : ";
        cin >> this->trainNumber;
        fflush(stdin);
        cout << "Enter train name : ";
        gets(this->trainName);
        cout << "Enter source : ";
        gets(this->source);
        cout << "Enter destination : ";
        gets(this->destination);
        cout << "Enter train time: ";
        gets(this->trainTime);
    }

    // display

    void displayTrainDetails()
    {
        cout << "Train Number : " << this->trainNumber << endl;
        cout << "Train Name : " << this->trainName << endl;
        cout << "Source : " << this->source << endl;
        cout << "Destination : " << this->destination << endl;
        cout << "Train Time : " << this->trainTime << endl;
    }

    // static member function

    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    // default constructor

    RailwaySystem()
    {
        this->totalTrains = 0;
    }

    // add new train

    void addTrain()
    {
        if (this->totalTrains < 100)
        {
            this->trains[this->totalTrains].inputTrainDetails();
            this->totalTrains++;
            cout << "Train added successfully." << endl;
        }
        else
        {
            cout << "Cannot add more trains. Maximum limit reached." << endl;
        }
    }

    // display all trains

    void displayAllTrains()
    {
        if (this->totalTrains == 0)
        {
            cout << "No trains available." << endl;
            return;
        }

        for (int i = 0; i < this->totalTrains; i++)
        {
            cout << "Train " << (i + 1) << ":" << endl;
            this->trains[i].displayTrainDetails();
            cout << endl;
        }
    }

    // search train by number

    void searchTrainByNumber(int trainNumber)
    {
        for (int i = 0; i < this->totalTrains; i++)
        {
            if (this->trains[i].getTrainNumber() == trainNumber)
            {
                cout << "Train found:" << endl;
                this->trains[i].displayTrainDetails();
                cout << "train found" << endl;
            }
            else
            {
                cout << "Train with number " << trainNumber << " not found." << endl;
            }
        }
    }
};