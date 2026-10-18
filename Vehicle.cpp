// MEMBER 1: DEVASHISH SINGH - VEHICLE & PRIORITY MODULE
// Uses classes, inheritance, overriding and virtual functions covered in C++ Units 1-4.

#include <iostream>
#include <cstring>
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle(int id, const char name[]) {
    vehicleID = id;
    strncpy(ownerName, name, 29);
    ownerName[29] = '\0';
}

int Vehicle::getID() {
    return vehicleID;
}

Vehicle::~Vehicle() { }

TwoWheeler::TwoWheeler(int id, const char name[]) : Vehicle(id, name) { }
int TwoWheeler::getPriority() { return 2; }
int TwoWheeler::getHourlyRate() { return 10; }
int TwoWheeler::getNoShowFine() { return 50; }
void TwoWheeler::showDetails() {
    cout << "ID: " << vehicleID << ", Owner: " << ownerName
         << ", Type: Two-wheeler, Priority: 2, Rate: Rs. 10/hour" << endl;
}

FourWheeler::FourWheeler(int id, const char name[]) : Vehicle(id, name) { }
int FourWheeler::getPriority() { return 1; }
int FourWheeler::getHourlyRate() { return 20; }
int FourWheeler::getNoShowFine() { return 100; }
void FourWheeler::showDetails() {
    cout << "ID: " << vehicleID << ", Owner: " << ownerName
         << ", Type: Four-wheeler, Priority: 1, Rate: Rs. 20/hour" << endl;
}

EmergencyVehicle::EmergencyVehicle(int id, const char name[]) : Vehicle(id, name) { }
int EmergencyVehicle::getPriority() { return 0; }
int EmergencyVehicle::getHourlyRate() { return 0; }
int EmergencyVehicle::getNoShowFine() { return 0; }
void EmergencyVehicle::showDetails() {
    cout << "ID: " << vehicleID << ", Owner: " << ownerName
         << ", Type: Emergency vehicle, Priority: 0, No-show fine: Rs. 0" << endl;
}

VehicleManager::VehicleManager() {
    count = 0;
    int i;
    for (i = 0; i < 50; i++) vehicles[i] = NULL;
}

VehicleManager::~VehicleManager() {
    int i;
    for (i = 0; i < count; i++) delete vehicles[i];
}

Vehicle* VehicleManager::findVehicle(int id) {
    int i;
    for (i = 0; i < count; i++) {
        if (vehicles[i]->getID() == id) return vehicles[i];
    }
    return NULL;
}

bool VehicleManager::addVehicle(int id, const char name[], int type) {
    if (count == 50) {
        cout << "Vehicle register is full.\n";
        return false;
    }
    if (findVehicle(id) != NULL) {
        cout << "This vehicle ID is already registered.\n";
        return false;
    }

    if (type == 1) vehicles[count] = new TwoWheeler(id, name);
    else if (type == 2) vehicles[count] = new FourWheeler(id, name);
    else if (type == 3) vehicles[count] = new EmergencyVehicle(id, name);
    else return false;

    count++;
    cout << "Vehicle registered successfully.\n";
    return true;
}

void VehicleManager::showVehicles() {
    if (count == 0) {
        cout << "No registered vehicles.\n";
        return;
    }
    cout << "\n--- VEHICLE REGISTER ---\n";
    int i;
    for (i = 0; i < count; i++) {
        // Runtime polymorphism: the derived class version is called.
        vehicles[i]->showDetails();
    }
}
