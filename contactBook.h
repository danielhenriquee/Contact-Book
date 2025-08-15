// Daniel Henrique da Silva, Lucas dos Santos Luckow, Samuel Alfonso Werner Stuhlert, Victor Menezes Ferreira

#include <iostream>
#include <locale.h>
#include <time.h>
#include <unistd.h>
using namespace std;

// Generic contactBook struct with a maximum size
template <typename T, int MAX> 
struct contactBook {
    T items[MAX]; // Contacts vector (structs)
    int counter;
};

// Personal contacts struct
struct personal  { 
    int ID, SSN, mobilePhone;
    string name;
};

// Business contacts struct
struct business { 
    int ID, CRN, companyPhone; // CRN = Company Registration Number
    string companyName;
};

// Boot contactBook
template <typename T, int MAX> 
bool contactBook_boot(contactBook<T, MAX> &cb) {
    cb.counter = 0;
    return true;
}

// Insert new contact
template <typename T, int MAX> 
bool contactBook_insert(contactBook<T, MAX> &cb, T dado) {
    if (cb.counter < MAX) { // CHeck if contact book is not full
        cb.items[cb.counter] = dado; // Insert
        cb.counter++;
        cout << "\nContact added successfully!" << endl;
        return true;
    } else {
        cout << "Unable to add a new contact, your contact book is full!" << endl;
        return false;
    }
}

// Delete by ID a contact
template <typename T, int MAX> 
bool contactBook_delete(contactBook<T, MAX> &cb, int ID) {
    int aux = -1; // Auxiliary variable to detect if contact was found
    for (int i = 0; i < cb.counter or aux == i; i++) {
        if (ID == cb.items[i].ID) {
            aux = i; // If found, saves contact position
        }
    }
    if (aux != -1) {
        for (int i = aux; i < cb.counter; i++) {
            cb.items[i] = cb.items[i + 1]; // Swift all contacts to the left
        }
        cb.counter--; 
        cout << "Contact successfully deleted.\n\n";
        return true;
    } else {
        cout << "Contact not found.\n\n";
        return false;
    }
}

// Generic bubblesort to sort contacts by name
template <typename T, int MAX>
void contactBook_sort(contactBook<T, MAX> &cb) { 
    int i, j, cond;
    T temp;
    cond = 1;
    for (i = cb.counter - 1; (i >= 1) && (cond == 1); i--) {
        cond = 0;
        for (j = 0; j < i; j++) {
            if ((cb.items[j + 1] < cb.items[j]) == true) {
                temp = cb.items[j];
                cb.items[j] = cb.items[j + 1];
                cb.items[j + 1] = temp;
                cond = 1;
            }
        }
    }
}
