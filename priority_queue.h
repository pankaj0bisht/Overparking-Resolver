#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

int addWaitingVehicle(int vehicleID, int priority);
int removeNextWaitingVehicle(int *vehicleID);
int waitingListContains(int vehicleID);
int waitingListIsEmpty(void);
void showWaitingList(void);

#ifdef __cplusplus
}
#endif

#endif
