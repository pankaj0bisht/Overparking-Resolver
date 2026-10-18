#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include "Vehicle.h"
#include "Parking.h"
#include "FineAlert.h"

// MEMBER: PANKAJ BISHT - reservation and alternate-block resolver.

class ReservationManager {
private:
    struct Reservation {
        int vehicleID;
        int block;
        int slot;
        int bookingHour;
        int active;
        int checkedIn;
    };

    Reservation records[50];
    int currentHour;
    int findActiveRecord(int vehicleID);
    int findFreeRecord();
    bool createRecord(int vehicleID, int block, int slot);
    void assignWaitingVehicles(VehicleManager &vehicles, ParkingManager &parking);

public:
    ReservationManager();
    int getCurrentHour();
    bool hasActiveReservation(int vehicleID);
    void bookVehicle(int vehicleID, int preferredBlock, VehicleManager &vehicles, ParkingManager &parking);
    void checkIn(int vehicleID, ParkingManager &parking);
    void checkOut(int vehicleID, int hours, VehicleManager &vehicles, ParkingManager &parking);
    void advanceTime(int hours, VehicleManager &vehicles, ParkingManager &parking, FineManager &fines);
    void showWaitlist();
};

#endif
