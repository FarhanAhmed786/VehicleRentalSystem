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
    char type[20], trans[5], model[20], number[20], id[10],cap[10],fare[20];
    //ISsue : 
    // Issue : vehicle id not reading skips to vechile type
    cout << "Vehicle ID:";
    cin.ignore(0,'\n');
    cin.getline(id, 10);
    cout << "Vehicle type:";
    cin.ignore(0,'\n');
    cin.getline(type, 20);
    cout << "Vehicle Number:";
    cin.getline(number, 20);
    cin.ignore();
    cout << "Model No:";
    cin.getline(model, 20);
    cin.ignore();
    cout << "Capacity:";
    // cin>>cap;
    cin.getline(cap, 10);
    cin.ignore();
    cout << "Fare:";
    // cin>>fare;
    cin.getline(fare, 20);
    cin.ignore();

    // Issue : transmission  not reading skips admin menu
    cout << "Tansmission:";
    cin.getline(trans, 5);
    out << id << "\t\t" << type << "\t\t" << number << "\t\t" << model << "\t\t" << cap << "\t\t" << fare << "\t\t"
        << trans << endl;
    out.close();
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
    // need to fix
    printf("delete vechile data ");
}