# Team role and viva guide

## Devashish Singh - Vehicle & Priority Module
**Owns:** `Vehicle.h`, `Vehicle.cpp`.

**What the code does:** `Vehicle` is the base class. `TwoWheeler`, `FourWheeler` and `EmergencyVehicle` inherit from it and override virtual functions. A vehicle has a priority, hourly charge, no-show fine and a detail display. `VehicleManager` stores registered vehicle objects in a fixed array.

**Viva answer:** “Inheritance allows the three vehicle types to reuse common ID and owner details from `Vehicle`. The methods are virtual, so `vehicles[i]->showDetails()` calls the correct derived-class function at runtime. Priority 0 is the highest, so emergency vehicles are considered first in the waitlist.”

## Dhruv Rawat - Parking Slot & Block Module
**Owns:** `Parking.h`, `Parking.cpp`.

**What the code does:** stores 3 blocks with 5 slots each in fixed arrays. State values are 0 = free, 1 = reserved, and 2 = occupied. Methods reserve a free slot, check in, release, count used slots and print every slot.

**Viva answer:** “An array stores the vehicle ID for each slot. ID 0 means the slot is free. The class keeps slot data private and exposes methods so the reservation manager does not need to directly modify each array.”

## Pankaj Bisht - Reservation & Overcrowding Resolver Module
**Owns:** `ReservationManager.h`, `ReservationManager.cpp`, `priority_queue.c`, `priority_queue.h`.

**What the code does:** keeps fixed-array reservation records; prevents an active vehicle from reserving again; handles check-in and check-out; expires an unchecked reservation after one simulated hour; tries the preferred block first, then checks other blocks; uses a C array-based priority queue when every block is full.

**Viva answer:** “The preferred block is checked first. If it has no free slot, the program scans the other blocks one by one. If no block is available, the vehicle ID and priority go to the C priority queue. A lower number means higher priority; equal priorities keep arrival order.”

**Limitation:** this is sequential scanning, not graph BFS/DFS. The graph resolver is postponed because graph traversal is not in the stated completed C topics.

## Dev Kumar - Fine, Alert & Integration Module
**Owns:** `fine_bst.c`, `fine_bst.h`, `FineAlert.h`, `FineAlert.cpp`, `main.cpp`.

**What the code does:** calculates/records the no-show fine, stores cumulative fines in a C BST, displays fine records in ascending vehicle ID order with inorder traversal, warns when occupancy reaches 80% or the car park is full, and connects the modules through the menu.

**Viva answer:** “The BST is ordered by vehicle ID. Smaller IDs go to the left and larger IDs go to the right. Inorder traversal prints IDs in ascending order. The AlertSystem counts occupied or reserved slots and prints a warning when occupancy reaches the chosen threshold.”

## How to demonstrate it

1. Register a two-wheeler, vehicle ID `101`, owner `Pankaj`, type `1`.
2. Book vehicle `101` in block `1` and check in.
3. Check it out for two hours; its fee is Rs. 20.
4. Register and book another vehicle without checking in. Advance simulated time one hour to demonstrate the no-show fine.
5. Show the fine records and parking slots.

## Shared viva questions

**Why C and C++ both?** The project report separates the DSA implementations (C priority queue and C BST) from the OOP classes (C++).

**Why no vector/map?** The team asked to stay within the taught syntax; fixed arrays are sufficient for this prototype.

**Why no graph BFS/DFS?** The classroom progress stated for C stops before the graph unit, so this version uses the simpler sequential scan and leaves the graph version for later.

**Why is `main.cpp` short?** It is only the menu and integration point; each member's actual implementation lives in their own files.
