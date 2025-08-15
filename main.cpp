// Daniel Henrique da Silva, Lucas dos Santos Luckow, Samuel Alfonso Werner Stuhlert, Victor Menezes Ferreira
#include "contactBook.h"
#include <iostream>
#include <locale.h>
#include <time.h>
#include <unistd.h>
using namespace std;

// Operator overload to print all personal contacts
ostream &operator << (ostream &os, const contactBook<personal, 50> &cb) { 
    for (int i = 0; i < cb.counter; i++) {
        os << "ID: " << cb.items[i].ID << endl;
        os << "Name: " << cb.items[i].name << endl;
        os << "SSN: " << cb.items[i].SSN << endl;
        os << "Mobile phone: " << cb.items[i].mobilePhone << endl;
        cout << endl;
    }
    return os;
}

// Operator overload to print all business contacts
ostream &operator << (ostream &os, const contactBook<business, 50> &cb) { 
    for (int i = 0; i < cb.counter; i++) {
        os << "ID: " << cb.items[i].ID << endl;
        os << "Company name: " << cb.items[i].companyName << endl;
        os << "CRN: " << cb.items[i].CRN << endl;
        os << "Company phone: " << cb.items[i].companyPhone << endl;
        cout << endl;
    }
    return os;
}

// Operator overloading to compare personal contacts by name
bool operator < (personal c1, personal c2) { 
    if (c1.name < c2.name)
        return true; 
    return false;
}

// Operator overloading to compare business contacts by company name
bool operator < (business c1, business c2) { 
    if (c1.companyName < c2.companyName)
        return true;
    return false;
}

// Fill in contact information for personal contact book
void fill(personal &c) { 
    do {
        cout << "Type the ID (must be a natural number): ";
        cin >> c.ID;
    } while (c.ID <= 0);

    do {
        cout << "Type the SSN (must be a natural number): ";
        cin >> c.SSN;
    } while (c.SSN <= 0);

    do {
        cout << "Type the mobile phone number (must be a natural number): ";
        cin >> c.mobilePhone;
    } while (c.mobilePhone <= 0);

    cout << "Type the contact name: " << endl;
    cin >> c.name;
}

// Fill in contact information for business contact book
void fill(business &c) { 
    do {
        cout << "Type the ID (must be a natural number): ";
        cin >> c.ID;
    } while (c.ID <= 0);

    do {
        cout << "Type the CRN (must be a natural number): ";
        cin >> c.CRN;
    } while (c.CRN <= 0);

    do {
        cout << "Type the company phone number (must be a natural number): ";
        cin >> c.companyPhone;
    } while (c.companyPhone <= 0);

    cout << "Type the company name: " << endl;
    cin >> c.companyName;
}

// Function to search for a personal contact by name
int searchByName(contactBook<personal, 50> &cb, string name) { 
    for (int i = 0; i < cb.counter; i++) {
        if (cb.items[i].name == name)
            return cb.items[i].ID; // If found, return contact ID
    }
    return -1; // If not found, returns -1
}

// Function to search for a business contact by name
int searchByName(contactBook<business, 50> &cb, string companyName) { 
    for (int i = 0; i < cb.counter; i++) {
        if (cb.items[i].companyName == companyName)
            return cb.items[i].ID; // If found, return company ID
    }
    return -1; // If not found, returns -1
}

// Function to search a personal contact by ID
int searchByID(contactBook<personal, 50> &cb, int ID) { 
    for (int i = 0; i < cb.counter; i++) {
        if (ID == cb.items[i].ID)
            return i;
    }
    return -1;
}

// Function to search a business contact by ID
int searchByID(contactBook<business, 50> &cb, int ID) { 
    for (int i = 0; i < cb.counter; i++) {
        if (ID == cb.items[i].ID)
            return i;
    }
    return -1;
}

// Print menu
void menu() { 
    cout << "Type an option!\n" << endl;
    cout << " 1. Save new contact" << endl;
    cout << " 2. Delete a contact (by name or ID)" << endl;
    cout << " 3. Search a contact (by name or ID)" << endl;
    cout << " 4. Sort contacts by name" << endl;
    cout << " 5. Show all contacts saved" << endl;
    cout << " 6. Exit" << endl;
}

void animation01() { 
    cout << "          ________________________________________________________\n";
    cout << "         /                                                         #\n";
    cout << "        |    ____________________________________________________    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |___________________________________________________|    |\n";
    cout << "        |                                                            |\n";
    cout << "        #____________________________________________________________/\n";
    cout << "                      #___________________________________/\n";
    cout << "                   ___________________________________________\n";
    cout << "                _ -'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n";
    cout << "             _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n";
    cout << "          _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n";
    cout << "       _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n";
    cout << "   _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n";
    cout << "   :-------------------------------------------------------------------------:\n";
    cout << "   `---._.-------------------------------------------------------------._.---'\n";
}

void animation02() {
    cout << "          ________________________________________________________\n";
    cout << "         /                                                         #\n";
    cout << "        |    ____________________________________________________    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |               ╔═╗╔═╗╔╗╔╔╦╗╔═╗╔═╗╔╦╗               |    |\n";
    cout << "        |   |               ║  ║ ║║║║ ║ ╠═╣║   ║                |    |\n";
    cout << "        |   |               ╚═╝╚═╝╝╚╝ ╩ ╩ ╩╚═╝ ╩                |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                    ╔╗ ╔═╗╔═╗╦╔═                   |    |\n";
    cout << "        |   |                    ╠╩╗║ ║║ ║╠╩╗                   |    |\n";
    cout << "        |   |                    ╚═╝╚═╝╚═╝╩ ╩                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |___________________________________________________|    |\n";
    cout << "        |                                                            |\n";
    cout << "        #____________________________________________________________/\n";
    cout << "                      #___________________________________/\n";
    cout << "                   ___________________________________________\n";
    cout << "                _ -'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n";
    cout << "             _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n";
    cout << "          _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n";
    cout << "       _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n";
    cout << "   _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n";
    cout << "   :-------------------------------------------------------------------------:\n";
    cout << "   `---._.-------------------------------------------------------------._.---'\n";
}

void animation03() {
    cout << "          ________________________________________________________\n";
    cout << "         /                                                         #\n";
    cout << "        |    ____________________________________________________    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   | Program exiting in 3 seconds...                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   | Professor: Rafael Ballottin Martins               |    |\n";
    cout << "        |   |                                                   |    |\n";
    cout << "        |   | Developers: Daniel Henrique da Silva              |    |\n";
    cout << "        |   |             Lucas dos Santos Luckow               |    |\n";
    cout << "        |   |             Samuel Alfonso Werner Stuhlert        |    |\n";
    cout << "        |   |             Victor Menezes Ferreira               |    |\n";
    cout << "        |   |___________________________________________________|    |\n";
    cout << "        |                                                            |\n";
    cout << "        #____________________________________________________________/\n";
    cout << "                      #___________________________________/\n";
    cout << "                   ___________________________________________\n";
    cout << "                _ -'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n";
    cout << "             _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n";
    cout << "          _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n";
    cout << "       _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n";
    cout << "   _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n";
    cout << "   :-------------------------------------------------------------------------:\n";
    cout << "   `---._.-------------------------------------------------------------._.---'\n";
}

void clear() {                
    cout << "\033[2J\033[1;1H"; // Clear the screen on ANSI console
}

void delay(unsigned long t) { 
    sleep(t); // t in seconds
}

void back2menu(int *pmenu) { 
    *pmenu = 0;
    string aux;
    cin.ignore();
    cout << "\nPress enter to go back to the main menu\n";
    getline(cin, aux);
}

int main() {
    int ID;
    string name;
    int *pmenu = new int; // Professor demanded to be a pointer to force students to use it properly
    int *option = new int; // Professor demanded to be a pointer to force students to use it properly

    contactBook<personal, 50> personalCB; // Personal contact book with a maximum of 50 contacts
    contactBook<business, 50> businessCB; // Business contact book with a maximum of 50 contacts
    contactBook_boot(personalCB);
    contactBook_boot(businessCB);
    personal personalContact; // Struct to store a personal contact
    business businessContact; // Struct to store a business contact
    animation01();
    delay(3);
    clear();
    animation02();
    delay(3);
    clear();

    do {
        clear();
        menu();
        cin >> *pmenu;

        switch (*pmenu) {
            case 1: // Insert
                clear();
                cout << "1. Personal contact book" << endl;
                cout << "2. Business contact book" << endl;
                cin >> *option;
                if (*option == 1) { // Insert personal contact
                    clear();
                    fill(personalContact);
                    if (contactBook_insert(personalCB, personalContact))
                        cout << "\nContact added successfully!" << endl;
                    else
                        cout << "Unable to add a new contact, your contact book is full!" << endl;
                    back2menu(pmenu);
                } else if (*option == 2) { // Insert business contact
                    clear();
                    fill(businessContact);
                    if (contactBook_insert(businessCB, businessContact))
                        cout << "\nContact added successfully!" << endl;
                    else
                        cout << "Unable to add a new contact, your contact book is full!" << endl;
                    back2menu(pmenu);
                } else {
                    clear();
                    back2menu(pmenu);
                }
                break;
    
            case 2: // Remove
                clear();
                cout << "1. Delete contact from personal contact book by ID" << endl;
                cout << "2. Delete contact from personal contact book by name" << endl;
                cout << "3. Delete contact from business contact book by ID" << endl;
                cout << "4. Delete contact from business contact book by name" << endl;
                cin >> *option;
                if (*option == 1) { // Remove personal contact by ID
                    clear();
                    cout << "Type the ID: " << endl;
                    cin >> ID;
                    if (contactBook_delete(personalCB, ID))
                        cout << "Contact successfully deleted.\n\n";
                    else
                        cout << "Contact not found.\n\n";
                    back2menu(pmenu);
                } else if (*option == 2) { // Remove personal contact by name
                    clear();
                    cin.ignore();
                    cout << "Type the name: " << endl;
                    getline(cin, name);
                    if (contactBook_delete(personalCB, searchByName(personalCB, name)))
                        cout << "Contact successfully deleted.\n\n";
                    else
                        cout << "Contact not found.\n\n";
                    back2menu(pmenu);
                } else if (*option == 3) { // Remove business contact by ID
                    clear();
                    cout << "Type the ID: " << endl;
                    cin >> ID;
                    if (contactBook_delete(businessCB, ID)) 
                        cout << "Contact successfully deleted.\n\n";
                    else
                        cout << "Contact not found.\n\n";
                    back2menu(pmenu);
                } else if (*option == 4) { // Remove business contact by name
                    clear();
                    cin.ignore();
                    cout << "Type the name: " << endl;
                    getline(cin, name);
                    if (contactBook_delete(businessCB, searchByName(businessCB, name)))
                        cout << "Contact successfully deleted.\n\n";
                    else
                        cout << "Contact not found.\n\n";
                    back2menu(pmenu);
                } else {
                    clear();
                    back2menu(pmenu);
                }
                break;
    
            case 3: // Search contact
                clear();
                cout << "1. Search personal contact by ID" << endl;
                cout << "2. Search personal contact by name" << endl;
                cout << "3. Search business contact by ID" << endl;
                cout << "4. Search business contact by name" << endl;
                cin >> *option;
                if (*option == 1) { // Search personal contact by ID
                    clear();
                    cout << "Type the ID: " << endl;
                    cin >> ID;
                    int idx = searchByID(personalCB, ID);
                    if (idx != -1) {
                        cout << "Contact found!\n";
                        cout << "ID: " << personalCB.items[idx].ID << endl;
                        cout << "Name: " << personalCB.items[idx].name << endl;
                        cout << "SSN: " << personalCB.items[idx].SSN << endl;
                        cout << "Mobile phone number: " << personalCB.items[idx].mobilePhone << endl;
                    } else
                        cout << "Contact not found\n";
                    back2menu(pmenu);
                } else if (*option == 2) { // Search personal contact by name
                    clear();
                    cin.ignore();
                    cout << "Type the name: " << endl;
                    getline(cin, name);
                    int idx = searchByID(personalCB, searchByName(personalCB, name));
                    if (idx != -1) {
                        cout << "Contact found!\n";
                        cout << "ID: " << personalCB.items[idx].ID << endl;
                        cout << "Name: " << personalCB.items[idx].name << endl;
                        cout << "SSN: " << personalCB.items[idx].SSN << endl;
                        cout << "Mobile phone number: " << personalCB.items[idx].mobilePhone << endl;
                    } else
                        cout << "Contact not found\n";
                    back2menu(pmenu);
                } else if (*option == 3) { // Search business contact by ID
                    clear();
                    cout << "Type the ID: " << endl;
                    cin >> ID;
                    int idx = searchByID(businessCB, ID);
                    if (idx != -1) {
                        cout << "Contact found!\n";
                        cout << "ID: " << businessCB.items[idx].ID << endl;
                        cout << "Company name: " << businessCB.items[idx].companyName << endl;
                        cout << "CRN: " << businessCB.items[idx].CRN << endl;
                        cout << "Company phone number: " << businessCB.items[idx].companyPhone << endl;
                    } else
                        cout << "Contact not found\n";
                    back2menu(pmenu);
                } else if (*option == 4) { // Search business contact by name
                    clear();
                    cin.ignore();
                    cout << "Type the name: " << endl;
                    getline(cin, name);
                    int idx = searchByID(businessCB, searchByName(businessCB, name));
                    if (idx != -1) {
                        cout << "Contact found!\n";
                        cout << "ID: " << businessCB.items[idx].ID << endl;
                        cout << "Company name: " << businessCB.items[idx].companyName << endl;
                        cout << "CRN: " << businessCB.items[idx].CRN << endl;
                        cout << "Company phone number: " << businessCB.items[idx].companyPhone << endl;
                    } else
                        cout << "Contact not found\n";
                    back2menu(pmenu);
                } else {
                    clear();
                    back2menu(pmenu);
                }
                break;
    
            case 4: // Sort
                clear();
                cout << "1. Sort personal contacts " << endl;
                cout << "2. Sort business contacts " << endl;
                cin >> *option;
                if (*option == 1) { // Sort personal contacts by name
                    contactBook_sort(personalCB);
                    clear();
                    back2menu(pmenu);
                } else if (*option == 2) {
                    contactBook_sort(businessCB); // Sort business contacts by name
                    clear();
                    back2menu(pmenu);
                } else {
                    clear();
                    back2menu(pmenu);
                }
                break;
    
            case 5: // Show all contacts
                clear();
                cout << "1. Show all personal contacts saved" << endl;
                cout << "2. Show all business contacts saved" << endl;
                cin >> *option;
                if (*option == 1) {
                    clear();
                    if (personalCB.counter == 0) {
                        cout << "There are no contacts saved in the personal contact book." << endl << endl;
                        back2menu(pmenu);
                    } else {
                        cout << personalCB; // Print all personal contacts saved
                        back2menu(pmenu);
                    }
                } else if (*option == 2) {
                    clear();
                    if (businessCB.counter == 0) {
                        cout << "There are no contacts saved in the business contact book." << endl << endl;
                        back2menu(pmenu);
                    } else {
                        cout << businessCB; // Print all business contacts saved
                        back2menu(pmenu);
                    }
                }
                break;
        }
    } while (*pmenu != 6);
    clear();
    animation03();
    delay(3);
    clear();
    animation01();
    delay(3);
    clear();

    delete pmenu;
    delete option;
    return 0; 
}
