// Daniel Henrique da Silva, Lucas dos Santos Luckow, Samuel Alfonso Werner Stuhlert, Victor Menezes Ferreira

#include <iostream>
#include <locale.h>
#include <time.h>
#include <unistd.h>
using namespace std;

// Template que permite criar uma struct agenda genérica (no caso do trabalho, pessoal ou comercial) e com um tamanho máximo
template <typename TIPO, int MAX> 
struct agenda {
    TIPO itens[MAX]; // Vetor de itens (no caso do trabalho, struct pessoal ou comercial)
    int quantidade;
};

// Struct de contatos pessoais
struct pessoal { 
    int ID, CPF, Celular;
    string Nome;
};

// Struct de contatos comerciais
struct comercial { 
    int ID, CNPJ, Tel_comercial;
    string Nome_empresa;
};

// Função para inicializar a agenda
template <typename TIPO, int MAX> 
bool inicializa_agenda(agenda<TIPO, MAX> &ag) {
    ag.quantidade = 0; // Inicializa a quantidade de contatos na agenda como zero
    return true;
}

// Função para inserir um contato na agenda
template <typename TIPO, int MAX> 
bool inserir(agenda<TIPO, MAX> &ag, TIPO dado) {
    if (ag.quantidade < MAX) { // Verifica se tem espaço na agenda
        ag.itens[ag.quantidade] = dado; // Insere o contato na próxima posição disponível na agenda
        ag.quantidade++; // Aumenta a contagem de contatos na agenda
        cout << "\nContato inserido com sucesso!" << endl;
        return true;
    } else {
        cout << "Impossível inserir um novo contato, sua agenda está cheia!" << endl;
        return false;
    }
}

// Função para remover um contato da agenda por ID
template <typename TIPO, int MAX> 
bool remover(agenda<TIPO, MAX> &ag, int ID) {
    int aux = -1; // Inicializa uma variável auxiliar para indicar se o contato foi encontrado
    for (int i = 0; i < ag.quantidade or aux == i; i++) {
        if (ID == ag.itens[i].ID) {
            aux = i; // Se encontrado, armazena a posição do contato a ser removido
        }
    }
    if (aux != -1) {
        for (int i = aux; i < ag.quantidade; i++) {
            ag.itens[i] = ag.itens[i + 1]; // A partir da posição do contato a ser removido, todos os contatos recebem os dados do contato seguinte, a posição onde ficava o último contato vira lixa de memória
        }
        ag.quantidade--; // Reduz a quantidade de contatos na agenda
        cout << "Contato removido com sucesso.\n\n";
        return true;
    } else {
        cout << "Contato não encontrado.\n\n";
        return false;
    }
}

// Função que utiliza um bubblesort genérico para ordenar os contatos da agenda por nome
template <typename TIPO, int MAX>
void ordenar(agenda<TIPO, MAX> &ag) { 
    int i, j, cond;
    TIPO temp;
    cond = 1; // Inicializa a variável "cond" como 1 para entrar no primeiro loop
    for (i = ag.quantidade - 1; (i >= 1) && (cond == 1); i--) { // Percorre a agenda a partir do último elemento até o primeiro
        cond = 0;
        for (j = 0; j < i; j++) { // Compara e, se necessário, troca elementos adjacentes
            if ((ag.itens[j + 1] < ag.itens[j]) == true) {
                temp = ag.itens[j];
                ag.itens[j] = ag.itens[j + 1];
                ag.itens[j + 1] = temp;
                cond = 1; // Define "cond" como 1 para indicar que houve uma troca
            }
        }
    }
}
