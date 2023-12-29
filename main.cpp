#include <iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void admin_menu();
int  add_vehicle();

int main()
{
    admin_menu();

    return 0;
}

void admin_menu()
{
    int choice;
   cout<<("\n1.New Admin \n2.Add vehicles \n3.Delete Vehicles \n4.Display \n5.log out\n");
 cout<<("\nEnter your choice:");
 cin>>choice;
    if(choice==2)
    {
        add_vehicle();

    }
     else if(choice==5)
    {
         exit(0);
    }
}

int add_vehicle()
{

    ofstream out("abc.txt");
    string data;
    cout<<"Enter the following datas:\n";
    cout<<"1.Type of vehicle \n2.Number of Vehicle \n3.Model No \n4.Capacity \n5.Fare \n6.Tansmission\n";
    cin>>data;
    out<<data;
    out.close();
    return 0;

}