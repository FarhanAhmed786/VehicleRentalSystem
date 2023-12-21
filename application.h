//
// Created by acerphoenix on 21/12/23.
//

#ifndef VEHICLE_RENTAL_SYSTEM_APPLICATION_H
#define VEHICLE_RENTAL_SYSTEM_APPLICATION_H
#include "vehicle.h"
#include "trip.h"
#include "database.h"

#include <fstream>
extern const char DELIMITTER;
class Application{
private:
    Database *db;
    void renderMenu();
    void welcome();
    void gotoXY(int x, int y) const;

   /* Render Menus*/
   void renderAddNewTripMenu() const;
   void renderViewTripMenu () const;
   void renderStartTripMenu() const;
   void renderCompleteTripMenu() const;
   void showDialog (string message, string id="") const;
   void cleanMemory();

};
#endif //VEHICLE_RENTAL_SYSTEM_APPLICATION_H
