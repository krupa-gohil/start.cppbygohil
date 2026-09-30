#include "PR3.cpp"

int main()
{
    VehicleRegistry registry;

    int choice;

    do
    {
        cout << "\n========== Vehicle Registry ==========\n";
        cout << "1. Add Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Search by ID\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int type;

            cout << "\nSelect Vehicle Type\n";
            cout << "1. Car\n";
            cout << "2. Electric Car\n";
            cout << "3. Flying Car\n";
            cout << "4. Sports Car\n";
            cout << "5. Sedan\n";
            cout << "6. SUV\n";
            cout << "Enter Choice: ";
            cin >> type;

            int id, year;
            string manufacturer, model, fuel;

            cout << "Enter Vehicle ID: ";
            cin >> id;

            cout << "Enter Manufacturer: ";
            cin >> manufacturer;

            cout << "Enter Model: ";
            cin >> model;

            cout << "Enter Year: ";
            cin >> year;

            if (type == 1)
            {
                cout << "Enter Fuel Type: ";
                cin >> fuel;

                Car c(id, manufacturer, model, year, fuel);
                registry.addVehicle(c);
            }
            else if (type == 2)
            {
                int battery;

                cout << "Enter Fuel Type: ";
                cin >> fuel;

                cout << "Enter Battery Capacity: ";
                cin >> battery;

                ElectricCar e(id, manufacturer, model, year, fuel, battery);
                registry.addVehicle(e);
            }
            else if (type == 3)
            {
                int range;

                cout << "Enter Fuel Type: ";
                cin >> fuel;

                cout << "Enter Flight Range: ";
                cin >> range;

                FlyingCar f(id, manufacturer, model, year, fuel, range);
                registry.addVehicle(f);
            }
            else if (type == 4)
            {
                int battery, speed;

                cout << "Enter Fuel Type: ";
                cin >> fuel;

                cout << "Enter Battery Capacity: ";
                cin >> battery;

                cout << "Enter Top Speed: ";
                cin >> speed;

                SportsCar s(id, manufacturer, model, year, fuel, battery, speed);
                registry.addVehicle(s);
            }
            else if (type == 5)
            {
                cout << "Enter Fuel Type: ";
                cin >> fuel;

                Sedan s(id, manufacturer, model, year, fuel);
                registry.addVehicle(s);
            }
            else if (type == 6)
            {
                cout << "Enter Fuel Type: ";
                cin >> fuel;

                SUV s(id, manufacturer, model, year, fuel);
                registry.addVehicle(s);
            }
            else
            {
                cout << "Invalid Vehicle Type!\n";
            }

            break;
        }

        case 2:
            registry.displayVehicles();
            break;

        case 3:
        {
            int id;
            cout << "Enter Vehicle ID: ";
            cin >> id;

            registry.searchVehicle(id);
            break;
        }

        case 4:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}