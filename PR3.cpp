#include <iostream>
#include <string>
using namespace std;

// Base Class : Vehicle

class Vehicle
{
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
        totalVehicles++;
    }

    Vehicle(int id, string manu, string mod, int y)
    {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = y;
        totalVehicles++;
    }

    ~Vehicle()
    {
        totalVehicles--;
    }

    void setVehicleID(int id)
    {
        vehicleID = id;
    }

    int getVehicleID()
    {
        return vehicleID;
    }

    void setManufacturer(string manu)
    {
        manufacturer = manu;
    }

    string getManufacturer()
    {
        return manufacturer;
    }

    void setModel(string mod)
    {
        model = mod;
    }

    string getModel()
    {
        return model;
    }

    void setYear(int y)
    {
        year = y;
    }

    int getYear()
    {
        return year;
    }
};

int Vehicle::totalVehicles = 0;

// Car (Single Inheritance)

class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car() : Vehicle()
    {
        fuelType = "";
    }

    Car(int id, string manu, string mod, int y, string fuel)
        : Vehicle(id, manu, mod, y)
    {
        fuelType = fuel;
    }

    ~Car()
    {
    }

    void setFuelType(string fuel)
    {
        fuelType = fuel;
    }

    string getFuelType()
    {
        return fuelType;
    }
};

// ElectricCar(Multilevel Inheritance)

class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    ElectricCar() : Car()
    {
        batteryCapacity = 0;
    }

    ElectricCar(int id, string manu, string mod, int y,
                string fuel, int battery)
        : Car(id, manu, mod, y, fuel)
    {
        batteryCapacity = battery;
    }

    ~ElectricCar()
    {
    }

    void setBatteryCapacity(int battery)
    {
        batteryCapacity = battery;
    }

    int getBatteryCapacity()
    {
        return batteryCapacity;
    }
};

// Aircraft

class Aircraft
{
protected:
    int flightRange;

public:
    Aircraft()
    {
        flightRange = 0;
    }

    Aircraft(int range)
    {
        flightRange = range;
    }

    ~Aircraft()
    {
    }

    void setFlightRange(int range)
    {
        flightRange = range;
    }

    int getFlightRange()
    {
        return flightRange;
    }
};

// FlyingCar(Multiple Inheritance)

class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar() : Car(), Aircraft()
    {
    }

    FlyingCar(int id, string manu, string mod, int y,
              string fuel, int range)
        : Car(id, manu, mod, y, fuel), Aircraft(range)
    {
    }

    ~FlyingCar()
    {
    }
};

// SportsCar(Multilevel Inheritance)

class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    SportsCar() : ElectricCar()
    {
        topSpeed = 0;
    }

    SportsCar(int id, string manu, string mod, int y,
              string fuel, int battery, int speed)
        : ElectricCar(id, manu, mod, y, fuel, battery)
    {
        topSpeed = speed;
    }

    ~SportsCar()
    {
    }

    void setTopSpeed(int speed)
    {
        topSpeed = speed;
    }

    int getTopSpeed()
    {
        return topSpeed;
    }
};

// Sedan(Hierarchical Inheritance)
class Sedan : public Car
{
public:
    Sedan() : Car()
    {
    }

    Sedan(int id, string manu, string mod,
          int y, string fuel)
        : Car(id, manu, mod, y, fuel)
    {
    }

    ~Sedan()
    {
    }
};

// SUV(Hierarchical Inheritance)

class SUV : public Car
{
public:
    SUV() : Car()
    {
    }

    SUV(int id, string manu, string mod,
        int y, string fuel)
        : Car(id, manu, mod, y, fuel)
    {
    }

    ~SUV()
    {
    }
};

// VehicleRegistry Class

class VehicleRegistry
{
private:
    Vehicle vehicles[100];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }

    void addVehicle(Vehicle v)
    {
        if (count < 100)
        {
            vehicles[count] = v;
            count++;
        }
        else
        {
            cout << "Registry is Full!" << endl;
        }
    }

    void displayVehicles()
    {
        if (count == 0)
        {
            cout << "No Vehicles Found!" << endl;
            return;
        }

        cout << "\n========== Vehicle List ==========\n";

        for (int i = 0; i < count; i++)
        {
            cout << "Vehicle " << i + 1 << endl;
            cout << "ID : " << vehicles[i].getVehicleID() << endl;
            cout << "Manufacturer : " << vehicles[i].getManufacturer() << endl;
            cout << "Model : " << vehicles[i].getModel() << endl;
            cout << "Year : " << vehicles[i].getYear() << endl;
            cout << "-----------------------------" << endl;
        }
    }

    void searchVehicle(int id)
    {
        bool found = false;

        for (int i = 0; i < count; i++)
        {
            if (vehicles[i].getVehicleID() == id)
            {
                cout << "\nVehicle Found\n";
                cout << "ID : " << vehicles[i].getVehicleID() << endl;
                cout << "Manufacturer : " << vehicles[i].getManufacturer() << endl;
                cout << "Model : " << vehicles[i].getModel() << endl;
                cout << "Year : " << vehicles[i].getYear() << endl;

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Vehicle Not Found!" << endl;
        }
    }
};