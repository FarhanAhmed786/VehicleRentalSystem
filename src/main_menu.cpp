#include<iostream>
#include<stdlib.h>
#include<fstream>
#include"main_menu.h"
#include"user_menu.h"
#include"admin.h"
using namespace std;

int main_menu()
{
    int choice;
    do
    {
        cout<<"\n \t\t Main Menu \t\t \n ";
        cout<<"\n1.Admin\n2.User\n3.Exit\n";
        cout<<"\n Enter your choice \n";
        cin>>choice;
        
        if (choice == 1)
            admin_menu();
        else if (choice == 2)
            user_menu();
        else if (choice == 3)
            exit(0);  
    } while (choice>=3);   
}