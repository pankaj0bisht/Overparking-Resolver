#ifndef PARKING_H
#define PARKING_H

const int BLOCK_COUNT = 3;
const int SLOTS_PER_BLOCK = 5;

// MEMBER: DHRUV RAWAT
// Parking blocks and slot states. Status: 0 free, 1 reserved, 2 occupied.

class ParkingBlock {
private:
    int blockID;
    int vehicleIDs[SLOTS_PER_BLOCK];
    int status[SLOTS_PER_BLOCK];

public:
    ParkingBlock(int id = 0);
    void setBlockID(int id);
    bool reserve(int vehicleID, int &slotNumber);
    bool checkIn(int vehicleID);
    bool release(int vehicleID);
    bool contains(int vehicleID);
    int occupiedCount();
    void showBlock();
};

class ParkingManager {
private:
    ParkingBlock blocks[BLOCK_COUNT];

public:
    ParkingManager();
    bool reserveVehicle(int vehicleID, int preferredBlock, int &actualBlock, int &slotNumber);
    bool checkInVehicle(int vehicleID);
    bool releaseVehicle(int vehicleID);
    bool containsVehicle(int vehicleID);
    int getOccupiedSlots();
    int getTotalSlots();
    bool hasFreeSlot();
    void showAllBlocks();
};

#endif
