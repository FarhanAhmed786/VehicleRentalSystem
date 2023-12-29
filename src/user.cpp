#include <iostream>
#include<stdlib.h>
#include<fstream>
#include"user.h"
#include"main_menu.h"
using namespace std;

void user_menu()
{
    int user_choice;
    cout<<"\n \t\t USER MENU \t\t \n";
    cout<<"\n1.New User\n2.Existing User\n3.Back\n";
    cout<<"\n Enter your Coice \n";
    cin>>user_choice;
    if(user_choice == 1)
        printf("new user menu");
    else if (user_choice == 2)
        printf("Existing user operation");  
    else if (user_choice == 3)
        main_menu();
    else
        exit(0);    
    
}
