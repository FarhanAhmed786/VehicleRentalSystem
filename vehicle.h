#ifndef vehicle_h
#define vehicle_h

/* Include custom headers */

#include "date.h"
#include "storable.cpp"

/* Include standard cpp headers */

#include <string>

using namespace std;
/* support for different kinds of vehicles for different purpose */

typedef enum{bike=1 , car=2, towera=3} VehicleType;
/* vehicle class which helps to manage vehicle-related data */

    class Vehicle : public storable{

        private:
              /* Registration number given by RTO */

              string registrationNumber;

              /* Type of vehicle given by 'vehicleType' enum */

              VehicleType  type;

              /* No. of seats this vehicle has */

              int seats;

              /* Name of the vehicle manufacturer */

              string companyName;

              /* Each vehicle has different price per km */
              /* This will be requried to calculate fare when trip ends */

              double priceperkm;

              /* This is the date when PUC will expire */

              Date PUCExpirationDate;

        public :
            /*
             constructor
             input : Registration number of vehicle
             input : vehicle type
             input : No. of seats
             input : company name
             input : price per km
             input : PUC Expiration date
             input : recordId (defaults to 0)
             */

             Vehicle( string registrationNumber, VehicleType type, int seats, string companyName, double pricePerKm, Date PUCExpirationDate, long recordId=0 );

             /*
                Getter methods with const attribute i.e. This method is not changing any data of the current object.
                  If this method is not marked as constant,then it cannot be called from constant object of this class.

                   Following snippet will give an error if 'getRegistrationNumber' is not marked with const keyword.

                    const Vehicle * object = new vehicle(...);
                    auto registrationNo = object->getRegistrationNumber ();
             */

             string getRegistrationNumber () const;
             VehicleType getVehicleType   () const;
             string  getVehicleTypeName   () const;
             int getseats  () const;
             string getCompanyName     () const;
             double   getPricePerKm    () const;
             Date getPUCExpirationDate () const;

             /*
              Function which sets new price of the vehicle
              input : New price of vehicle
             */

             void setPricePerkm (double newPrice);

             /* Display recorded on screen */

             void display () const;

             /* overridden virtual method */

             string toString  () const;

             void setDataFrom  (Storable * s);

    };

#endif