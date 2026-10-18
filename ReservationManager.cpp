// MEMBER 3: PANKAJ BISHT - RESERVATION & OVERCROWDING RESOLVER MODULE
// Uses arrays, simple sequential block scanning and a C array-based priority queue.
// Graph BFS/DFS and exception handling are intentionally not included in this half-scope version.

#include <iostream>
#include "ReservationManager.h"
#include "priority_queue.h"
using namespace std;

ReservationManager::ReservationManager() {
    currentHour = 0;
    int i;
    for (i = 0; i < 50; i++) {
        records[i].vehicleID = 0;
        records[i].block = 0;
        records[i].slot = 0;
        records[i].bookingHour = 0;
        records[i].active = 0;
        records[i].checkedIn = 0;
    }
}

int ReservationManager::getCurrentHour() { return currentHour; }

int ReservationManager::findActiveRecord(int id) {
    int i;
    for (i = 0; i < 50; i++) {
        if (records[i].active == 1 && records[i].vehicleID == id) return i;
    }
    return -1;
}

int ReservationManager::findFreeRecord() {
    int i;
    for (i = 0; i < 50; i++) {
        if (records[i].active == 0) return i;
    }
    return -1;
}

bool ReservationManager::createRecord(int id, int block, int slot) {
    int index = findFreeRecord();
    if (index == -1) return false;
    records[index].vehicleID = id;
    records[index].block = block;
    records[index].slot = slot;
    records[index].bookingHour = currentHour;
    records[index].active = 1;
    records[index].checkedIn = 0;
    return true;
}

bool ReservationManager::hasActiveReservation(int id) {
    return findActiveRecord(id) != -1;
}

void ReservationManager::bookVehicle(int id, int preferredBlock,
                                     VehicleManager &vehicles, ParkingManager &parking) {
    Vehicle *vehicle = vehicles.findVehicle(id);
    if (vehicle == NULL) {
        cout << "Register this vehicle first.\n";
        return;
    }
    if (hasActiveReservation(id) || parking.containsVehicle(id) || waitingListContains(id)) {
        cout << "This vehicle already has a reservation, slot, or waitlist entry.\n";
        return;
    }
    if (findFreeRecord() == -1) {
        cout << "Reservation list is full.\n";
        return;
    }

    int block = 0, slot = 0;
    if (parking.reserveVehicle(id, preferredBlock, block, slot)) {
        if (createRecord(id, block, slot)) {
            cout << "Reservation successful: Block " << block << ", Slot " << slot << ".\n";
            cout << "Please check in within 1 simulated hour.\n";
        } else {
            parking.releaseVehicle(id);
            cout << "Reservation list is full.\n";
        }
    } else {
        int result = addWaitingVehicle(id, vehicle->getPriority());
        if (result == 1) {
            cout << "No block has a free slot. Vehicle added to the priority waitlist.\n";
        } else {
            cout << "Could not add vehicle to the waitlist.\n";
        }
    }
}

void ReservationManager::checkIn(int id, ParkingManager &parking) {
    int index = findActiveRecord(id);
    if (index == -1) {
        cout << "No active reservation found for this vehicle.\n";
        return;
    }
    if (records[index].checkedIn == 1) {
        cout << "Vehicle is already checked in.\n";
        return;
    }
    if (parking.checkInVehicle(id)) {
        records[index].checkedIn = 1;
        cout << "Check-in successful for Block " << records[index].block
             << ", Slot " << records[index].slot << ".\n";
    } else {
        cout << "Could not find the vehicle's reserved slot.\n";
    }
}

void ReservationManager::checkOut(int id, int hours,
                                  VehicleManager &vehicles, ParkingManager &parking) {
    int index = findActiveRecord(id);
    if (index == -1) {
        cout << "No active reservation found for this vehicle.\n";
        return;
    }
    if (records[index].checkedIn == 0) {
        cout << "Check-in is required before checkout.\n";
        return;
    }
    if (hours < 1) {
        cout << "Parking duration must be at least 1 hour.\n";
        return;
    }

    Vehicle *vehicle = vehicles.findVehicle(id);
    if (vehicle != NULL) {
        int fee = vehicle->getHourlyRate() * hours;
        parking.releaseVehicle(id);
        records[index].active = 0;
        cout << "Parking fee: Rs. " << fee << ". Vehicle checked out.\n";
        assignWaitingVehicles(vehicles, parking);
    }
}

void ReservationManager::advanceTime(int hours, VehicleManager &vehicles,
                                     ParkingManager &parking, FineManager &fines) {
    if (hours < 1) {
        cout << "Enter at least 1 hour.\n";
        return;
    }
    currentHour += hours;
    cout << "Simulated time is now hour " << currentHour << ".\n";

    int i;
    for (i = 0; i < 50; i++) {
        if (records[i].active == 1 && records[i].checkedIn == 0 &&
            currentHour - records[i].bookingHour >= 1) {
            int id = records[i].vehicleID;
            Vehicle *vehicle = vehicles.findVehicle(id);
            parking.releaseVehicle(id);
            records[i].active = 0;
            cout << "Reservation for vehicle " << id << " expired because of a no-show.\n";
            if (vehicle != NULL) fines.addNoShowFine(id, vehicle->getNoShowFine());
        }
    }
    assignWaitingVehicles(vehicles, parking);
}

void ReservationManager::assignWaitingVehicles(VehicleManager &vehicles, ParkingManager &parking) {
    while (parking.hasFreeSlot() && !waitingListIsEmpty()) {
        int id;
        if (!removeNextWaitingVehicle(&id)) return;
        Vehicle *vehicle = vehicles.findVehicle(id);
        if (vehicle == NULL) continue;

        int block = 0, slot = 0;
        if (!parking.reserveVehicle(id, 1, block, slot)) {
            addWaitingVehicle(id, vehicle->getPriority());
            return;
        }
        if (!createRecord(id, block, slot)) {
            parking.releaseVehicle(id);
            addWaitingVehicle(id, vehicle->getPriority());
            return;
        }
        cout << "Waitlist vehicle " << id << " received Block " << block
             << ", Slot " << slot << ". Check in within 1 simulated hour.\n";
    }
}

void ReservationManager::showWaitlist() { showWaitingList(); }
