#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "admin.h"
#include "user_menu.h"
#include "main_menu.h"
#include "new_user.h"
#include "existing_user.h"
#include <sstream>
using namespace std;

int existing_user()
{
     string phone_number;
    cout<<"\nEnter phone number"<<endl;
    getline(cin,phone_number);
    checking_user("user_data.txt","vehicle_data.txt",phone_number);
}
void checking_user(string filename,string file2,string phone_number)
{
    string line,extract;
    int count=0;
    ifstream file(filename,ios::in|ios::app);
    while(getline(file,line))
    {
        verification(line,phone_number,&count);
    }
    file.close();
     if(count==0)
    {
        cout<<"\nNot registered";
        return;
    }
    if(count!=0)
    {
        vehicle_detail(file2);
        return;
    }
}
void verification(string line,string phone_number,int *count)
{
    stringstream ss(line);
    string word;
    //extracting each deatil liike name,phone number and addrress
    while (ss >> word) 
    {
        if(word==phone_number)
        {
             ++(*count);
           cout<<(*count);
           cout<<"User found"<<endl;
        }
    }
}
void vehicle_detail(string file2)
{
    string vehicle_name,line_d,time_for_rent,confirmation_detail;
    cout<<"Avialabel vehicle"<<endl;
    ifstream file(file2,ios::out|ios::in);
    while(file.good())
    {
        getline(file,line_d);
        cout<<line_d<<endl;
    }
    file.close();
    cout<<"Fill detail for vehicle rent:"<<endl;
    cout<<"Enter vehicle name:";
    cin>>vehicle_name;
    cout<<"\nEnter time for rent in hours:";
    cin>>time_for_rent;
    cout<<"Confirm details:"<<endl;
    cout<<"Vehicle name"<<vehicle_name<<endl;
    cout<<"Time for rent:"<<time_for_rent<<endl;
    cout<<"Enter YES/NO:";
    cin>>confirmation_detail;
    if(confirmation_detail=="NO")
    {
        cout<<"Login again"<<endl;
        return;
    }
    cout<<"Vehicle alloted detail:"<<endl;
    cout<<"Vehicle name: "<<vehicle_name<<endl;
    cout<<"Time for rent: "<<time_for_rent<<endl;
    cout<<"Thank you"<<endl;
}