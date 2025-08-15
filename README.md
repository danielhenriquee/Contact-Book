# Contact-Book
Contact Book - Project for Algorithms and Programming II - 2023/2

This repository contains a simple, template-based Contact Book system, developed to manage personal or business contacts directly in a C++ environment.
It is designed as a lightweight and easily adaptable project for educational purposes, focusing on practicing data structures and templates.

**Project Structure**
- contactBook.h — Header file containing the Contact structure and the ContactBook struct definition/implementation.
- main.cpp — Main program file to interact with the Contact Book via console interface.

**Features**
- Template-based implementation for flexibility with different contact types
- main.cpp: Add personal and business contacts
- Search contacts by name or ID
- Delete contacts by name or ID.
- List all contacts in alphabetical order.
- Clean, modular code for easy maintenance and scalability.

**Usage**

The program can be compiled and run directly from a terminal or within a development environment:
- g++ main.cpp -o contact_book
- ./contact_book

**Notes**
- Contacts are stored in memory during execution but can be easily adapted for file persistence
- Educational project with a solid foundation for expanding into more complex contact management systems.
- The template design allows adapting the structure to store additional information or different data types.
- Input handling supports full names (including spaces) to prevent data truncation.
