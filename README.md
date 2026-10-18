# Campus Parking Overcrowding Resolver - Syllabus-Aligned 50% Prototype

This is a **half-scope implementation of the four assigned modules**, prepared for the topics the team said have been taught so far. It is not a claim that exactly 50% of source-code lines are present; line counts do not measure feature completion. The `SCOPE_AND_SYLLABUS.md` file names the implemented and postponed parts for each role.

## Correct team roles and code ownership

1. **Devashish Singh - Vehicle & Priority Module**
   - `Vehicle.h`, `Vehicle.cpp`
   - Vehicle base class, derived two-wheeler/four-wheeler/emergency classes, virtual functions, priorities, parking rates, no-show fine rates, vehicle registration/display.

2. **Dhruv Rawat - Parking Slot & Block Module**
   - `Parking.h`, `Parking.cpp`
   - Three blocks, five slots per block, free/reserved/occupied states, reserve, check-in, release, occupancy count, display.

3. **Pankaj Bisht - Reservation & Overcrowding Resolver Module**
   - `ReservationManager.h`, `ReservationManager.cpp`, `priority_queue.c`, `priority_queue.h`
   - Reservation records, duplicate-active-reservation prevention, check-in/check-out, alternative-block sequential scan, simulated time, no-show expiry, C priority queue for waiting vehicles.

4. **Dev Kumar - Fine, Alert & Integration Module**
   - `fine_bst.c`, `fine_bst.h`, `FineAlert.h`, `FineAlert.cpp`, `main.cpp`
   - No-show fine records in a simple BST, ascending fine report, occupancy alert, main menu and integration.

## Language / syllabus alignment

### C++ topics used
- Classes and objects
- Constructors
- Arrays, loops, conditions and functions
- Inheritance and overriding
- Virtual functions and runtime polymorphism
- Pointers to base-class objects and dynamic objects

These match C++ Units 1-4 up to inheritance, virtual functions and polymorphism, as described by the team.

### C data-structure topics used
- Arrays and functions
- Array-based priority queue
- `struct`, pointers and recursion for the basic BST fine record
- BST insertion and inorder traversal

The queue stays within the covered queue material, and the BST is limited to the basic binary-search-tree work the team says the teacher has started.

## Deliberately not included yet

The report's bigger design includes graph BFS/DFS, hash table, C++ file persistence (`fstream`), STL containers/algorithms, function templates and structured exception handling. These are excluded from this simplified version because the team said they have not been covered or are beyond the current required level. The alternate-block resolver scans blocks in order; **it is not BFS and must not be presented as graph traversal**.

## Build and run on Windows (VS Code)

Install/configure GCC/MinGW first. Extract the ZIP, open this folder in VS Code, then in the terminal run:

```powershell
cmd /c build.bat
.\CampusParkingResolver.exe
```

If the build fails because `gcc` or `g++` is not recognized, install/configure a C/C++ compiler first.

## Basic demo

1. Select `1` and register a two-wheeler: ID `101`, owner `Pankaj`, type `1`.
2. Select `2`, vehicle ID `101`, preferred block `1`.
3. Select `3` and check in vehicle `101`.
4. Select `4`, vehicle ID `101`, duration `2` hours. A two-wheeler fee is Rs. 20.
5. For a no-show, register another vehicle and book it, but do not check in. Select `5` and advance time by `1` hour; then select `9` to see the fine record.
6. Select `6` to display the three blocks and their slot states.

## Important

`main.cpp` is the application entry point and menu, **not the whole project**. The four members' code is in their named source modules; the C queue and C BST are compiled separately and linked into the same application.
