#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "admin.h"
#include"main_menu.h"
using namespace std;

void admin_menu()
{
    int choice;
    cout << ("\n1.New Admin \n2.Add vehicles \n3.Delete Vehicles \n4.Display \n5.Main Menu\n");
    cout << ("\nEnter your choice:");
    cin >> choice;
    if (choice == 2)
    {
        add_vehicle();
    }
    else if (choice == 5)
    {
       main_menu();
    }
}
int add_vehicle()
{
    ofstream out("Vehicle_data.txt");
    string data;
    cout<<"Enter the following datas:\n";
    cout<<"1.Type of vehicle \n2.Number of Vehicle \n3.Model No \n4.Capacity \n5.Fare \n6.Tansmission\n";
    cin>>data;
    out<<data;
    out.close();
    return 0;
}