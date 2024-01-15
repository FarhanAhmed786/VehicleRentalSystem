#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "main_menu.h"
#include "user_menu.h"
#include "admin.h"
#include <cstring>
#include <ctime>
using namespace std;

int main_menu()
{
    int choice;
    do
    {
        cout << endl
             << "\n\t   \t\t\t\t\t\t\t ----------------------------" << endl;
        cout << endl
             << "\n\t   \t\t\t\t\t\t\t\t\t   Main Menu   " << endl;
        time_t now = time(nullptr);
        string dt = ctime(&now);
        cout << "\n\t   \t\t\t\t\t\t\t\t   Current Date:/time: " << dt << endl;
        cout << endl
             << "\n\t   \t\t\t\t\t\t\t ----------------------------" << endl;
        cout << "\n\t   \t\t\t\t\t\t\t\t     1.  ADMIN   " << endl;
        cout << "\n\t   \t\t\t\t\t\t\t\t     2.  USER   " << endl;
        cout << "\n\t   \t\t\t\t\t\t\t\t     3.  EXIT   " << endl;

        cout << "\n\t   \t\t\t\t\t\t\t\t   ENTER YOUR CHOICE :    ";
        cin >> choice;

        if (choice == 1)
            admin_menu();
        else if (choice == 2)
            user_menu();
        else if (choice == 3)
            exit(0);
    } while (choice >= 3);
}