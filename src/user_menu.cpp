#include <iostream>
#include<stdlib.h>
#include<fstream>
#include"user_menu.h"
#include"main_menu.h"
#include"new_user.h"
#include"existing_user.h"

using namespace std;

void user_menu()
{
    
    int choice;
    while(1)
    {
        cout<<"\n1.New user\n2.Existing user\n3.Main Menu\nSelect option:";
        cin>>choice;
        cin.ignore();
        switch(choice)
        {
            case 1: new_user();
                    break;
            case 2:existing_user();
                        break;
            case 3:main_menu();
                   break;
            default:cout<<"wrong choice!";
        }
    }
    return ;
}
