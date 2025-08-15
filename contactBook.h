// Daniel Henrique da Silva, Lucas dos Santos Luckow, Samuel Alfonso Werner Stuhlert, Victor Menezes Ferreira
using namespace std;

// Generic contactBook struct with a maximum size
template <typename T, int MAX> 
struct contactBook {
    T items[MAX]; // Contacts vector (structs)
    int counter;
};

// Personal contacts struct
struct personal  { 
    int ID, SSN, mobilePhone; // SSN = Social Security Number
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
bool contactBook_insert(contactBook<T, MAX> &cb, const T &dado) {
    if (cb.counter < MAX) { // CHeck if contact book is not full
        cb.items[cb.counter] = dado; // Insert
        cb.counter++;
        return true;
    } else {
        return false;
    }
}

// Delete by ID a contact
template <typename T, int MAX> 
bool contactBook_delete(contactBook<T, MAX> &cb, int ID) {
    int aux = -1; // Auxiliary variable to detect if contact was found
    for (int i = 0; i < cb.counter; i++) {
        if (ID == cb.items[i].ID) {
            aux = i; // If found, saves contact position
            break;
        }
    }
    if (aux != -1) {
        for (int i = aux; i < cb.counter -1; i++) {
            cb.items[i] = cb.items[i + 1]; // Swift all contacts to the left
        }
        cb.counter--; 
        return true;
    } else {
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
