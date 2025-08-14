// Daniel Henrique da Silva, Lucas dos Santos Luckow, Samuel Alfonso Werner Stuhlert, Victor Menezes Ferreira

#include <iostream>
#include <locale.h>
#include <time.h>
#include <unistd.h>
using namespace std;

// Template que permite criar uma struct contactBook genérica (no caso do trabalho, personal  ou business) e com um tamanho máximo
template <typename T, int MAX> 
struct contactBook {
    T items[MAX]; // Vetor de items (no caso do trabalho, struct personal  ou business)
    int counter;
};

// Struct de contatos pessoais
struct personal  { 
    int ID, SSN, mobilePhone;
    string name;
};

// Struct de contatos comerciais
struct business { 
    int ID, CNPJ, companyPhone;
    string companyName;
};

// Função para inicializar a contactBook
template <typename T, int MAX> 
bool contactBook_boot(contactBook<T, MAX> &cb) {
    cb.counter = 0; // Inicializa a counter de contatos na contactBook como zero
    return true;
}

// Função para contactBook_insert um contato na contactBook
template <typename T, int MAX> 
bool contactBook_insert(contactBook<T, MAX> &cb, T dado) {
    if (cb.counter < MAX) { // Verifica se tem espaço na contactBook
        cb.items[cb.counter] = dado; // Insere o contato na próxima posição disponível na contactBook
        cb.counter++; // Aumenta a contcbem de contatos na contactBook
        cout << "\nContato inserido com sucesso!" << endl;
        return true;
    } else {
        cout << "Impossível contactBook_insert um novo contato, sua contactBook está cheia!" << endl;
        return false;
    }
}

// Função para contactBook_delete um contato da contactBook por ID
template <typename T, int MAX> 
bool contactBook_delete(contactBook<T, MAX> &cb, int ID) {
    int aux = -1; // Inicializa uma variável auxiliar para indicar se o contato foi encontrado
    for (int i = 0; i < cb.counter or aux == i; i++) {
        if (ID == cb.items[i].ID) {
            aux = i; // Se encontrado, armazena a posição do contato a ser removido
        }
    }
    if (aux != -1) {
        for (int i = aux; i < cb.counter; i++) {
            cb.items[i] = cb.items[i + 1]; // A partir da posição do contato a ser removido, todos os contatos recebem os dados do contato seguinte, a posição onde ficava o último contato vira lixa de memória
        }
        cb.counter--; // Reduz a counter de contatos na contactBook
        cout << "Contato removido com sucesso.\n\n";
        return true;
    } else {
        cout << "Contato não encontrado.\n\n";
        return false;
    }
}

// Função que utiliza um bubblesort genérico para contactBook_sort os contatos da contactBook por name
template <typename T, int MAX>
void contactBook_sort(contactBook<T, MAX> &cb) { 
    int i, j, cond;
    T temp;
    cond = 1; // Inicializa a variável "cond" como 1 para entrar no primeiro loop
    for (i = cb.counter - 1; (i >= 1) && (cond == 1); i--) { // Percorre a contactBook a partir do último elemento até o primeiro
        cond = 0;
        for (j = 0; j < i; j++) { // Compara e, se necessário, troca elementos adjacentes
            if ((cb.items[j + 1] < cb.items[j]) == true) {
                temp = cb.items[j];
                cb.items[j] = cb.items[j + 1];
                cb.items[j + 1] = temp;
                cond = 1; // Define "cond" como 1 para indicar que houve uma troca
            }
        }
    }
}
