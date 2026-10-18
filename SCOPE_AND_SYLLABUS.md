# Syllabus alignment and 50% scope checklist

## Basis used

This scope follows the uploaded Semester III syllabus and the team's stated classroom progress:

- **C++:** Unit 1 and Unit 2 foundations, Unit 3 inheritance, and Unit 4 virtual functions/polymorphism have been covered.
- **C Data Structures:** Unit 1 and Unit 2 have been covered, and only the introductory part of binary trees/BST has been taught.

For that reason the code uses ordinary classes, arrays, functions, inheritance, virtual functions, a C array-based priority queue, and a small C BST. It does not use STL containers, templates, `fstream`, a hash table, or graph traversal.

## What “50% for every member” means here

The original report defines each member's module but does not define a line-count target or split every module into equally-sized sub-features. This package therefore treats **50% as a half-scope prototype for each assigned module**: one core working slice per role is implemented, and advanced/pending parts of that same role are explicitly postponed below. It does **not** claim the source files are exactly half the lines of some unseen full implementation.

| Member | Assigned module | Included in this half-scope version | Reserved for a later version |
|---|---|---|---|
| **Devashish Singh** | Vehicle & Priority | Base/derived vehicle types; priority, rate and fine rules; virtual display; registration and vehicle list | Broader category rules, more vehicle types and additional validation/reporting |
| **Dhruv Rawat** | Parking Slot & Block | Fixed-size 3-block/5-slot model; free/reserved/occupied state; reserve, check-in, release and occupancy display | STL-based variable capacity, stream operator overloading and block sorting/searching/congestion ranking |
| **Pankaj Bisht** | Reservation & Resolver | Reservation records; booking, check-in/out; preferred-block then sequential alternate-block scan; timed no-show expiry; C priority waitlist | Graph adjacency list, BFS/DFS nearest-path resolver, hash-table double-booking index and custom exception handling |
| **Dev Kumar** | Fine, Alert & Integration | C BST for cumulative no-show fines; inorder display; 80% / full occupancy warning; main menu and module integration | Hash-table vehicle index, persistent reservation/fine logs, `fstream` serialization and advanced report generation |

## What is implemented and verifiable

- One compiled C++ console application calls all four member modules.
- All four team member names appear in the role guide and their own code section/header.
- The priority queue is implemented in plain C in `priority_queue.c` and is called from the C++ reservation module.
- The fine BST is implemented in plain C in `fine_bst.c` and is called from the C++ fine module.
- The app demonstrates vehicle-type polymorphism, slot reservation/release, a waitlist, no-show fines, BST output and occupancy alerts.

## What should be said in viva

Say: “This is our 50% prototype based on the topics completed in class. We have implemented the core working part of every assigned member module. Graph BFS/DFS, hash tables, file persistence and advanced reporting are planned for the remaining implementation.”

Do not say that the sequential scan is BFS, that the fine BST is a hash table, or that the current version saves logs to files.
