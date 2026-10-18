// MEMBER 4: DEV KUMAR - FINE, ALERT & INTEGRATION MODULE
// Uses basic class functions and the C BST fine-record module. No file persistence or hash table.

#include <iostream>
#include "FineAlert.h"
#include "fine_bst.h"
using namespace std;

void FineManager::addNoShowFine(int vehicleID, int amount) {
    if (amount <= 0) {
        cout << "No fine charged for this vehicle type.\n";
        return;
    }
    addFineRecord(vehicleID, amount);
    cout << "No-show fine of Rs. " << amount << " recorded for vehicle " << vehicleID << ".\n";
}

void FineManager::showFines() {
    displayFineRecords();
}

void AlertSystem::checkParkingStatus(int occupied, int total) {
    cout << "Parking occupancy: " << occupied << "/" << total << " slots.\n";
    if (occupied == total) {
        cout << "ALERT: All parking slots are full.\n";
    } else if (occupied * 100 >= total * 80) {
        cout << "ALERT: Parking is almost full (80% or more occupied).\n";
    }
}
