#include "application.h"
#include "database_templates.cpp"
/*Include Standard CPP Headers*/
#include "iostream"
#include <cstdio>
#include <cstdlib>
Application::Application() {
    try {
        this -> db = new Database();

    }catch(Error e){
        cout<<e.getMessage();
        exit(EXIT_FAILURE);
    };
}
void Application::gotoXY(int x, int y) const {
    printf("%c[%d;%df",Ox1B,y,x);
}
void Application::renderMenu() {
    unsigned char choice=1;
    while(true)
    {
        system("clear");
        gotoXY(25,4);
        cout<<"Select any option from below";
        gotoXY(25,5);
        cout<<"1. Add new trip";
        gotoXY(25,6);
        cout<<"2. View trip";
        gotoXY(25,7);
        cout<<"3. Start trip";
        gotoXY(25,8);
        cout<<"4. Complete trip";
        gotoXY(25,9);
        cout<<"5. Complete trip";
        gotoXY(30,15);
        cout<<("Enter your choice: ");
        gotoXY(50,15);
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        switch (choice) {
            case '1':
                this->renderAddNewTripMenu();
                break;
            case '2':
                this->renderStartTripMenu();
                break;
            case '3':
                this->renderCompleteTripMenu();
                break;
            case '4':
                this->renderViewTripMenu();
                break;
            case '5':
                this->cleanMemory();
                system("clear");
                exit(EXIT_SUCCESS);
                break;
            default:
                this->cleanMemory();
                system("clear");
                exit(EXIT_SUCCESS);
                break;

        }

    }
}

/*Add new vehicle menu are remaining*/

void Application::renderAddNewTripMenu() const {
    string header="Enter details of trip (All fields are required) ";
    string userContactlabel= "Enter contact no of user: ";
    string startDateLabel = "Enter start date of trip (d/m/yyyy): ";
    string endDateLabel = "Enter end date of trip (d/m/yyyy): ";
    string vehicleTypeLabel= "Enter vehicle type: ";
    string vehicleOptionLabel = "(1. Bike, 2. Car, 3. Towera)";
    string registrationNolabel = "Enter registeration no vehicle: ";
    string contactNo;
    string startDate;
    string endDate;
    int vehicleType;
    string registrationNo;
    const User* user;
    const Vehicle*vehicle;
    system("clear");
    gotoXY(0,1);
    cout<<userContactlabel;
    gotoXY(int(userContactlabel.length()),1);
    getline(cin,contactNo);

    try {
        user = this->db->getUser(contactNo);
        gotoXY(0, 3);
        cout << "User found: " << user->getName();

    }catch(Error e)
    {
        this->showDialog(e.getMessage());
    }

    gotoXY(0,5);
    cout<<header;
    gotoXY(0,7);
    cout<<startDateLabel;
    gotoXY(0,8);
    cout<<endDateLabel;
    gotoXY(0.9);
    cout<<vehicleTypeLabel;
    gotoXY(0,10);
    cout<<vehicleOptionLabel;
    gotoXY(int(startDateLabel.length()),7);
    getline(cin,startDate);
    gotoXY(int(endDateLabel.length()),8);
    getline(cin,endDate);
    gotoXY(int(vehicleTypeLabel.length()),9);
    cin>>vehicleType;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    /*Find vehicle as per user's requirements and if not found , ask the user to change the input*/
    auto freeVehicles=this>db->getVehicle(Date(startDate)),Date(endDate),VehicleType(vehicleType));
    if(freeVehicles.size()==0)
    {
        this->showDialog("No Vehicles are free in given date range");
        return;
    }
    gotoXY(0,12);
    cout << "|Registeration no |" << "Seats |" << "Price per Km |" <<endl;
    for(auto & vehicle: freeVehicles)
    {
        string registrationNo=vehicle->getRegisterationNumber();
        string seats = to_string(vehicle->getSeats());
        stringstream ss;
        ss<<std::fixed;
        ss<<std:setprecision(2);
        ss<vehicle->getPricepeKm();
        string price=ss.str()+ "Rs/Km";
        cout << "|" registerationNo <<|" << "Seats |" << "Price per Km |" <<endl;
    }



}
