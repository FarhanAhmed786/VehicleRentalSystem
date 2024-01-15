#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "admin.h"
#include "main_menu.h"
using namespace std;

/*function declaration*/
int add_vehicle();
void delete_vehicle();
void display();

/*function declaration*/

void admin_menu()
{
    int choice;
    cout << ("\n1.New Admin \n2.Add vehicles \n3.Delete Vehicles \n4.Display \n5.Main Menu\n");
    cout << ("\nEnter your choice:");
    cin >> choice;
    if (choice == 1)
    {
        printf("in new admin");
    }
    else if (choice == 2)
    {
        add_vehicle();
        admin_menu();
    }
    else if (choice == 3)
    {
        delete_vehicle();
        admin_menu();
    }
    else if (choice == 4)
    {
        display();
        admin_menu();
    }
    else if (choice == 5)
    {
        main_menu();
    }
}
int add_vehicle()
{
    fstream out("vehicle_data.txt", ios::out | ios::app);
    string type, trans, model, cap, fare, id, number;
    cout << "Vehicle ID:";
    cin >> id;
    cout << "vehicle Type:";
    cin >> type;
    cout << "Vehicle Number:";
    cin >> number;
    cout << "Model No:";
    cin >> model;
    cout << "Capacity:";
    cin >> cap;
    cout << "Fare:";
    cin >> fare;
    cout << "Tansmission:";
    cin >> trans;
    out << id << "\t\t" << type << "\t\t" << number << "\t\t" << model << "\t\t" << cap << "\t\t" << fare << "\t\t" << trans << endl;
    out.close();
    return 0;
}
void display()
{
    int dis;
    string read;
    cout << "\n1.Display Data \n2.Display Available Vehicles\n";
    cout << "Enter your choice:";
    cin >> dis;
    if (dis == 1)
    {
        cout << "\nVehicle Id"
             << "\t"
             << "Vehicle Type"
             << "\t"
             << "Vehicle Number"
             << "\t"
             << "Model Number"
             << "\t"
             << "Capacity"
             << "\t"
             << "Fare"
             << "\t"
             << "Transmission" << endl;
        fstream in("vehicle_data.txt", ios::in);
        while (in.eof() == 0)
        {
            getline(in, read);
            cout << "\n"
                 << read << endl;
        }
        in.close();
    } // incomplete display func
    else
        printf("Wrong Choice!!!!");
}

void delete_vehicle()
{
    printf("in delete vechiles \n ");
}