/* MEMBER 3: PANKAJ BISHT - C ARRAY-BASED PRIORITY QUEUE.
   Uses arrays, loops and functions from the C data-structures portion covered in class. */
#include <stdio.h>

#define MAX_WAITING 50

static int vehicleIDs[MAX_WAITING];
static int priorities[MAX_WAITING];
static int waitingCount = 0;

int addWaitingVehicle(int vehicleID, int priority) {
    int i;
    if (waitingCount == MAX_WAITING) return 0;
    for (i = 0; i < waitingCount; i++) {
        if (vehicleIDs[i] == vehicleID) return -1;
    }
    vehicleIDs[waitingCount] = vehicleID;
    priorities[waitingCount] = priority;
    waitingCount++;
    return 1;
}

int removeNextWaitingVehicle(int *vehicleID) {
    int i, best = 0;
    if (waitingCount == 0) return 0;

    /* Smaller priority number means higher priority. Equal priorities keep order. */
    for (i = 1; i < waitingCount; i++) {
        if (priorities[i] < priorities[best]) best = i;
    }
    *vehicleID = vehicleIDs[best];

    for (i = best; i < waitingCount - 1; i++) {
        vehicleIDs[i] = vehicleIDs[i + 1];
        priorities[i] = priorities[i + 1];
    }
    waitingCount--;
    return 1;
}

int waitingListContains(int vehicleID) {
    int i;
    for (i = 0; i < waitingCount; i++) {
        if (vehicleIDs[i] == vehicleID) return 1;
    }
    return 0;
}

int waitingListIsEmpty(void) { return waitingCount == 0; }

void showWaitingList(void) {
    int i;
    if (waitingCount == 0) {
        printf("Waitlist is empty.\n");
        return;
    }
    printf("Waitlist (priority 0 is highest):\n");
    for (i = 0; i < waitingCount; i++) {
        printf("Vehicle %d - priority %d\n", vehicleIDs[i], priorities[i]);
    }
}
