// MEMBER 2: DHRUV RAWAT - PARKING SLOT & BLOCK MODULE
// Uses fixed-size arrays, loops, conditions and class methods. No STL containers.

#include <iostream>
#include "Parking.h"
using namespace std;

ParkingBlock::ParkingBlock(int id) {
    blockID = id;
    int i;
    for (i = 0; i < SLOTS_PER_BLOCK; i++) {
        vehicleIDs[i] = 0;
        status[i] = 0;
    }
}

void ParkingBlock::setBlockID(int id) { blockID = id; }

bool ParkingBlock::reserve(int id, int &slotNumber) {
    int i;
    for (i = 0; i < SLOTS_PER_BLOCK; i++) {
        if (vehicleIDs[i] == 0) {
            vehicleIDs[i] = id;
            status[i] = 1;
            slotNumber = i + 1;
            return true;
        }
    }
    return false;
}

bool ParkingBlock::checkIn(int id) {
    int i;
    for (i = 0; i < SLOTS_PER_BLOCK; i++) {
        if (vehicleIDs[i] == id) {
            status[i] = 2;
            return true;
        }
    }
    return false;
}

bool ParkingBlock::release(int id) {
    int i;
    for (i = 0; i < SLOTS_PER_BLOCK; i++) {
        if (vehicleIDs[i] == id) {
            vehicleIDs[i] = 0;
            status[i] = 0;
            return true;
        }
    }
    return false;
}

bool ParkingBlock::contains(int id) {
    int i;
    for (i = 0; i < SLOTS_PER_BLOCK; i++) {
        if (vehicleIDs[i] == id) return true;
    }
    return false;
}

int ParkingBlock::occupiedCount() {
    int i, count = 0;
    for (i = 0; i < SLOTS_PER_BLOCK; i++) {
        if (vehicleIDs[i] != 0) count++;
    }
    return count;
}

void ParkingBlock::showBlock() {
    cout << "\nBlock " << blockID << ":\n";
    int i;
    for (i = 0; i < SLOTS_PER_BLOCK; i++) {
        cout << "  Slot " << i + 1 << ": ";
        if (status[i] == 0) cout << "FREE";
        else if (status[i] == 1) cout << "RESERVED by vehicle " << vehicleIDs[i];
        else cout << "OCCUPIED by vehicle " << vehicleIDs[i];
        cout << endl;
    }
}

ParkingManager::ParkingManager() {
    blocks[0].setBlockID(1);
    blocks[1].setBlockID(2);
    blocks[2].setBlockID(3);
}

bool ParkingManager::reserveVehicle(int id, int preferredBlock, int &actualBlock, int &slotNumber) {
    int index;
    if (preferredBlock >= 1 && preferredBlock <= BLOCK_COUNT) {
        index = preferredBlock - 1;
        if (blocks[index].reserve(id, slotNumber)) {
            actualBlock = index + 1;
            return true;
        }
    }

    // Simple alternative-block search: scan blocks one by one.
    // It avoids graph/BFS syntax which has not been covered yet.
    int i;
    for (i = 0; i < BLOCK_COUNT; i++) {
        if (i == preferredBlock - 1) continue;
        if (blocks[i].reserve(id, slotNumber)) {
            actualBlock = i + 1;
            return true;
        }
    }
    return false;
}

bool ParkingManager::checkInVehicle(int id) {
    int i;
    for (i = 0; i < BLOCK_COUNT; i++) {
        if (blocks[i].checkIn(id)) return true;
    }
    return false;
}

bool ParkingManager::releaseVehicle(int id) {
    int i;
    for (i = 0; i < BLOCK_COUNT; i++) {
        if (blocks[i].release(id)) return true;
    }
    return false;
}

bool ParkingManager::containsVehicle(int id) {
    int i;
    for (i = 0; i < BLOCK_COUNT; i++) {
        if (blocks[i].contains(id)) return true;
    }
    return false;
}

int ParkingManager::getOccupiedSlots() {
    int i, count = 0;
    for (i = 0; i < BLOCK_COUNT; i++) count += blocks[i].occupiedCount();
    return count;
}

int ParkingManager::getTotalSlots() { return BLOCK_COUNT * SLOTS_PER_BLOCK; }
bool ParkingManager::hasFreeSlot() { return getOccupiedSlots() < getTotalSlots(); }

void ParkingManager::showAllBlocks() {
    int i;
    for (i = 0; i < BLOCK_COUNT; i++) blocks[i].showBlock();
}
