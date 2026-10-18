// MEMBER 4: DEV KUMAR - MAIN MENU AND MODULE INTEGRATION
// Calls each member module using a beginner-friendly console menu.

#include <iostream>
#include "Vehicle.h"
#include "Parking.h"
#include "ReservationManager.h"
#include "FineAlert.h"
using namespace std;


int main() {
    VehicleManager vehicles;
    ParkingManager parking;
    ReservationManager reservations;
    FineManager fines;
    AlertSystem alerts;

    int choice = -1;
    while (choice != 0) {
        cout << "\n====== CAMPUS PARKING RESOLVER ======\n";
        cout << "Simulated hour: " << reservations.getCurrentHour() << "\n";
        cout << "1. Register vehicle\n";
        cout << "2. Book a slot / join waitlist\n";
        cout << "3. Check in\n";
        cout << "4. Check out\n";
        cout << "5. Advance time and check no-shows\n";
        cout << "6. Show parking blocks\n";
        cout << "7. Show registered vehicles\n";
        cout << "8. Show priority waitlist\n";
        cout << "9. Show fines\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, type;
            char owner[30];
            cout << "Enter vehicle ID: ";
            cin >> id;
            cout << "Enter owner's first name (one word): ";
            cin.width(30);
            cin >> owner;
            cout << "Type: 1 Two-wheeler, 2 Four-wheeler, 3 Emergency vehicle: ";
            cin >> type;
            if (id <= 0) cout << "Vehicle ID must be positive.\n";
            else if (type < 1 || type > 3) cout << "Invalid vehicle type.\n";
            else vehicles.addVehicle(id, owner, type);
        } else if (choice == 2) {
            int id, preferred;
            cout << "Enter registered vehicle ID: ";
            cin >> id;
            cout << "Preferred block (1-3): ";
            cin >> preferred;
            if (preferred < 1 || preferred > 3) {
                cout << "Invalid block. A block number from 1 to 3 is required.\n";
            } else {
                reservations.bookVehicle(id, preferred, vehicles, parking);
                alerts.checkParkingStatus(parking.getOccupiedSlots(), parking.getTotalSlots());
            }
        } else if (choice == 3) {
            int id;
            cout << "Enter vehicle ID to check in: ";
            cin >> id;
            reservations.checkIn(id, parking);
        } else if (choice == 4) {
            int id, hours;
            cout << "Enter vehicle ID to check out: ";
            cin >> id;
            cout << "Parking duration in hours: ";
            cin >> hours;
            reservations.checkOut(id, hours, vehicles, parking);
            alerts.checkParkingStatus(parking.getOccupiedSlots(), parking.getTotalSlots());
        } else if (choice == 5) {
            int hours;
            cout << "Advance simulated time by how many hours? ";
            cin >> hours;
            reservations.advanceTime(hours, vehicles, parking, fines);
            alerts.checkParkingStatus(parking.getOccupiedSlots(), parking.getTotalSlots());
        } else if (choice == 6) {
            parking.showAllBlocks();
        } else if (choice == 7) {
            vehicles.showVehicles();
        } else if (choice == 8) {
            reservations.showWaitlist();
        } else if (choice == 9) {
            fines.showFines();
        } else if (choice == 0) {
            cout << "Thank you for using Campus Parking Resolver.\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
