#ifndef VEHICLE_H
#define VEHICLE_H

// MEMBER: DEVASHISH SINGH
// Vehicle hierarchy and priority rules.

class Vehicle {
protected:
    int vehicleID;
    char ownerName[30];

public:
    Vehicle(int id, const char name[]);
    int getID();
    virtual int getPriority() = 0;
    virtual int getHourlyRate() = 0;
    virtual int getNoShowFine() = 0;
    virtual void showDetails() = 0;
    virtual ~Vehicle();
};

class TwoWheeler : public Vehicle {
public:
    TwoWheeler(int id, const char name[]);
    int getPriority();
    int getHourlyRate();
    int getNoShowFine();
    void showDetails();
};

class FourWheeler : public Vehicle {
public:
    FourWheeler(int id, const char name[]);
    int getPriority();
    int getHourlyRate();
    int getNoShowFine();
    void showDetails();
};

class EmergencyVehicle : public Vehicle {
public:
    EmergencyVehicle(int id, const char name[]);
    int getPriority();
    int getHourlyRate();
    int getNoShowFine();
    void showDetails();
};

class VehicleManager {
private:
    Vehicle *vehicles[50];
    int count;

public:
    VehicleManager();
    ~VehicleManager();
    bool addVehicle(int id, const char name[], int type);
    Vehicle* findVehicle(int id);
    void showVehicles();
};

#endif
