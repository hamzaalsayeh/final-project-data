# Warehouse Management System

A C++ application designed to manage inventory and warehouse organization using advanced data structures. This system allows for a hierarchical classification of products within nested categories, simulating a real-world supply chain or storage facility.

---

## Overview
This project focuses on organizing items into a tree-like structure where each category can have multiple sub-categories and a list of specific products. It is built to demonstrate the practical application of Trees, Linked Lists, and Stacks in a single integrated system.

## Key Technical Features
* **General Tree Structure**: Uses a tree to represent the relationship between parent and child categories (e.g., Electronics > Smartphones > iPhones).
* **Singly Linked Lists**: Each category node contains a linked list to store and manage products dynamically without pre-defining the number of items.
* **Activity History (Stack)**: Implements a Stack to keep track of the last 5 product additions, ensuring quick access to the most recent inventory updates.
* **Recursive Search & Display**: Utilizes recursive algorithms to traverse the hierarchy for searching specific departments or printing the entire warehouse map.

## How it Works
The program provides an interactive menu with the following capabilities:
1. **Add Category**: Define a new section and link it to an existing parent category.
2. **Add Product**: Insert a new item (with Serial and Date) into a specific category.
3. **Search**: Find a specific category and view only its contents and sub-sections.
4. **Display All**: Visualize the entire warehouse structure with indented levels.
5. **Recent Activity**: View a history log of the last 5 items added to the system.

## Requirements
* A C++ compiler (e.g., GCC, Clang, or MSVC).
* Standard C++ libraries: `<iostream>`, `<vector>`, `<stack>`, and `<string>`.

---
*Developed to showcase the implementation of hierarchical data structures and dynamic memory management in C++.*
