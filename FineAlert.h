#ifndef FINE_ALERT_H
#define FINE_ALERT_H

// MEMBER: DEV KUMAR - fine and capacity-alert interface.

class FineManager {
public:
    void addNoShowFine(int vehicleID, int amount);
    void showFines();
};

class AlertSystem {
public:
    void checkParkingStatus(int occupied, int total);
};

#endif
