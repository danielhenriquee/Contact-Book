// Daniel Henrique da Silva, Lucas dos Santos Luckow, Samuel Alfonso Werner
// Stuhlert, Victor Menezes Ferreira
#include "biblioteca.h"
#include <iostream>
#include <locale.h>
#include <time.h>
#include <unistd.h>
using namespace std;

// Sobrecarga de operador para exibir todos os itens da agenda pessoal
ostream &operator << (ostream &os, agenda<pessoal, 50> ag) { 
    for (int i = 0; i < ag.quantidade; i++) { // laço que mostra os itens da agenda pessoal
        os << "ID: " << ag.itens[i].ID << endl;
        os << "Nome: " << ag.itens[i].Nome << endl;
        os << "CPF: " << ag.itens[i].CPF << endl;
        os << "Celular: " << ag.itens[i].Celular << endl;
        cout << endl;
    }
    return os;
}

// Sobrecarga de operador para exibir todos os itens da agenda comercial
ostream &operator << (ostream &os, agenda<comercial, 50> ag) { 
    for (int i = 0; i < ag.quantidade; i++) { // laço que mostra os itens da agenda comercial
        os << "ID: " << ag.itens[i].ID << endl;
        os << "Nome da Empresa: " << ag.itens[i].Nome_empresa << endl;
        os << "CNPJ: " << ag.itens[i].CNPJ << endl;
        os << "Telefone Comercial: " << ag.itens[i].Tel_comercial << endl;
        cout << endl;
    }
    return os;
}

// Sobrecarga de operador para comparar contatos pessoais por Nome
bool operator < (pessoal c1, pessoal c2) { 
    if (c1.Nome < c2.Nome) // Retorna true se Nome de c1 for menor (vem antes na ordem alfabética) que Nome de c2
        return true; 
    return false;
}

// Sobrecarga de operador para comparar contatos comerciais por Nome_empresa
bool operator < (comercial c1, comercial c2) { 
    if (c1.Nome_empresa < c2.Nome_empresa)
        return true; // Retorna true se Nome_empresa de c1 for menor (vem antes na ordem alfabética) que Nome_empresa de c2
    return false;
}

// Preencher contato para agenda pessoal
void preencher(pessoal &contato) { 
    for (int i = -1; i < 0;) {
        cout << "Digite o ID: " << endl;
        cin >> contato.ID;
        i++;
        if (contato.ID <= 0) { // condição que impede o ID inserido pelo usuario seja invalido
            cout << "ID inválido, o ID deve ser um número natural !=0" << endl;
            i = -1;
        }
    }

    for (int i = -1; i < 0;) {
        cout << "Digite o CPF: " << endl;
        cin >> contato.CPF;
        i++;
        if (contato.CPF <= 0) { // condição que impede o CPF inserido pelo usuario seja invalido
            cout << "CPF inválido, o CPF deve ser um número natural !=0" << endl;
            i = -1;
        }
    }

    for (int i = -1; i < 0;) {
        cout << "Digite o número do celular: " << endl;
        cin >> contato.Celular;
        i++;
        if (contato.Celular <= 0) { // condição que impede que o Celular inserido pelo usuario seja invalido
            cout << "Numéro do celular inválido, o número do celular deve ser um número natural !=0" << endl;
            i = -1;
        }
    }

    cout << "Digite o nome: " << endl;
    cin >> contato.Nome;
}

// Preencher contato para agenda comercial
void preencher(comercial &contato) { 
    for (int i = -1; i < 0;) {
        cout << "Digite o ID: " << endl;
        cin >> contato.ID;
        i++;
        if (contato.ID <= 0) { // condição que impede que o ID inserido pelo usuario seja invalido
            cout << "ID inválido, o ID deve ser um número natural !=0" << endl;
            i = -1;
        }
    }

    for (int i = -1; i < 0;) {
        cout << "Digite o CNPJ: " << endl;
        cin >> contato.CNPJ;
        i++;
        if (contato.CNPJ <= 0) { // condição que impede que o CNPJ inserido pelo usuario seja invalido
            cout << "CNPJ inválido, o CNPJ deve ser um número natural !=0" << endl;
            i = -1;
        }
    }

    for (int i = -1; i < 0;) { // condição que impede que o Telefone Comercial inserido pelo usuario seja invalido
        cout << "Digite o número do telefone comercial: " << endl;
        cin >> contato.Tel_comercial;
        i++;
        if (contato.Tel_comercial <= 0) {
            cout << "Telefone comercial inválido, o telefone comercial deve ser um número natural !=0" << endl;
            i = -1;
        }
    }

    cout << "Digite o nome da empresa: " << endl;
    cin >> contato.Nome_empresa;
}

// Função para pesquisar um contato pessoal por Nome
int pesquisaNome(agenda<pessoal, 50> &ag, string Nome) { 
    for (int i = 0; i < ag.quantidade; i++) {
        if (ag.itens[i].Nome == Nome)
            return ag.itens[i].ID; // Se encontrado, retorna o ID do contato
    }
    return -1; // Retorna -1 para indicar que o contato não foi encontrado.
}

// Função para pesquisar um contato comercial por Nome_empresa
int pesquisaNome(agenda<comercial, 50> &ag, string Nome_empresa) { 
    for (int i = 0; i < ag.quantidade; i++) {
        if (ag.itens[i].Nome_empresa == Nome_empresa)
            return ag.itens[i].ID; //  Se encontrado, retorna o ID do contato
    }
    return -1; // Retorna -1 para indicar que o contato não foi encontrado
}

void pesquisar(agenda<pessoal, 50> &ag, int ID) { // Função para pesquisar um contato pessoal por ID
    int aux = -1; // Inicializa uma variável auxiliar para indicar se o contato foi encontrado
    for (int i = 0; i < ag.quantidade; i++) {
        if (ID == ag.itens[i].ID) {
            aux = i; // Armazena a posição do contato a ser pesquisado
            cout << "Contato encontrado! " << endl;
            cout << "ID: " << ag.itens[aux].ID << endl;
            cout << "Nome: " << ag.itens[aux].Nome << endl;
            cout << "CPF: " << ag.itens[aux].CPF << endl;
            cout << "Celular: " << ag.itens[aux].Celular << endl;
        } else {
            cout << "Contato não encontrado";
        }
    }
}

// Função para pesquisar um contato comercial por ID
void pesquisar(agenda<comercial, 50> &ag, int ID) { 
    int aux = -1; // Inicializa uma variável auxiliar para indicar se o contato foi encontrado
    for (int i = 0; i < ag.quantidade; i++) {
        if (ID == ag.itens[i].ID) {
            aux = i; // Armazena a posição do contato a ser pesquisado
            cout << "Contato encontrado! " << endl;
            cout << "ID: " << ag.itens[aux].ID << endl;
            cout << "Nome da empresa: " << ag.itens[aux].Nome_empresa << endl;
            cout << "CNPJ: " << ag.itens[aux].CNPJ << endl;
            cout << "Telefone comercial: " << ag.itens[aux].Tel_comercial << endl;
        } else {
            cout << "Contato não encontrado";
        }
    }
}

// Exibe o menu de opções
void menu() { 
    cout << "Digite a opção desejada \n" << endl;
    cout << " 1. Inserir um novo item na agenda" << endl;
    cout << " 2. Remover um item da agenda (por ID ou nome)" << endl;
    cout << " 3. Pesquisar um item na agenda (por ID ou nome)" << endl;
    cout << " 4. Ordenar a agenda por nome" << endl;
    cout << " 5. Mostrar todos os itens da agenda" << endl;
    cout << " 6. Encerrar o programa" << endl;
}

// Exibe o pc ligando
void pcDesligado() { 
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

void apareceAgenda() { // Exibe a agenda abrindo

  cout
      << "          ________________________________________________________\n";
  cout << "         /                                                         "
          "#\n";
  cout << "        |    ____________________________________________________   "
          " |\n";
  cout << "        |   |                                                   |   "
          " |\n";
  cout << "        |   |                                                   |   "
          " |\n";
  cout << "        |   |                                                   |   "
          " |\n";
  cout << "        |   |                                                   |   "
          " |\n";
  cout << "        |   | █████╗  ██████╗ ███████╗███╗   ██╗██████╗  █████╗ |   "
          " |\n";
  cout << "        |   |██╔══██╗██╔════╝ ██╔════╝████╗  ██║██╔══██╗██╔══██╗|   "
          " |\n";
  cout << "        |   |███████║██║  ███╗█████╗  ██╔██╗ ██║██║  ██║███████║|   "
          " |\n";
  cout << "        |   |██╔══██║██║   ██║██╔══╝  ██║╚██╗██║██║  ██║██╔══██║|   "
          " |\n";
  cout << "        |   |██║  ██║╚██████╔╝███████╗██║ ╚████║██████╔╝██║  ██║|   "
          " |\n";
  cout << "        |   |╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝|   "
          " |\n";
  cout << "        |   |                                                   |   "
          " |\n";
  cout << "        |   |                                                   |   "
          " |\n";
  cout << "        |   |                                                   |   "
          " |\n";
  cout << "        |   |___________________________________________________|   "
          " |\n";
  cout << "        |                                                           "
          " |\n";
  cout << "        "
          "#____________________________________________________________/\n";
  cout << "                      #___________________________________/\n";
  cout << "                   ___________________________________________\n";
  cout
      << "                _ -'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n";
  cout << "             _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  "
          ".-.-.`-_\n";
  cout << "          _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. "
          ".-.-.-.`-_\n";
  cout << "       _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. "
          ".-.-.-.-.`-_\n";
  cout << "   _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. "
          ".---.-.-.-.`-_\n";
  cout << "   "
          ":-------------------------------------------------------------------"
          "------:\n";
  cout << "   "
          "`---._.-------------------------------------------------------------"
          "._.---'\n";
}

void encerraPrograma() { // Exibe a tela de encerramento

  cout
      << "          ________________________________________________________\n";
  cout << "         /                                                         "
          "#\n";
  cout << "        |    ____________________________________________________   "
          " |\n";
  cout << "        |   |                                                   |   "
          " |\n";
  cout << "        |   | Programa encerrando em 3 segundos...              |   "
          " |\n";
  cout << "        |   |                                                   |   "
          " |\n";
  cout << "        |   |                                                   |   "
          " |\n";
  cout << "        |   |                                                   |   "
          " |\n";
  cout << "        |   |                                                   |   "
          " |\n";
  cout << "        |   |                                                   |   "
          " |\n";
  cout << "        |   | Professor: Rafael Ballottin Martins               |   "
          " |\n";
  cout << "        |   |                                                   |   "
          " |\n";
  cout << "        |   | Programadores: Daniel Henrique da Silva           |   "
          " |\n";
  cout << "        |   |                Lucas dos Santos Luckow            |   "
          " |\n";
  cout << "        |   |                Samuel Alfonso Werner Stuhlert     |   "
          " |\n";
  cout << "        |   |                Victor Menezes Ferreira            |   "
          " |\n";
  cout << "        |   |___________________________________________________|   "
          " |\n";
  cout << "        |                                                           "
          " |\n";
  cout << "        "
          "#____________________________________________________________/\n";
  cout << "                      #___________________________________/\n";
  cout << "                   ___________________________________________\n";
  cout
      << "                _ -'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n";
  cout << "             _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  "
          ".-.-.`-_\n";
  cout << "          _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. "
          ".-.-.-.`-_\n";
  cout << "       _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. "
          ".-.-.-.-.`-_\n";
  cout << "   _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. "
          ".---.-.-.-.`-_\n";
  cout << "   "
          ":-------------------------------------------------------------------"
          "------:\n";
  cout << "   "
          "`---._.-------------------------------------------------------------"
          "._.---'\n";
}

void clear() {                // Função clear
  cout << "\033[2J\033[1;1H"; // Limpa a tela no console ANSI
}

void delay(unsigned long t) { // Para controlar tempo de delay entre cada número
                              // sorteado, t em segundos
  sleep(t);
}

void voltarMenu(int *pmenu) { // Para voltar ao menu
  *pmenu = 0;
  string aux;
  cin.ignore();
  cout << "\nDigite qualquer tecla para voltar ao menu\n";
  getline(cin, aux);
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  int ID;
  string nome;
  int *pmenu = new int; // Faz alocação de memoria para um inteiro e atribui o
                        // endereço a um ponteiro pmenu
  int *opcao = new int; // Faz alocação de memoria para um inteiro e atribui o
                        // endereço a um ponteiro opcao

  agenda<pessoal, 50>
      agenda_pessoal; // Cria uma agenda pessoal com um máximo de 50 contatos
  agenda<comercial, 50> agenda_comercial; // Cria uma agenda comercial com um
                                          // máximo de 50 contatos
  inicializa_agenda(agenda_pessoal);      // Inicializa a agenda pessoal
  inicializa_agenda(agenda_comercial);    // Inicializa a agenda comercial
  pessoal contato_pessoal; // Cria uma struct para armazenar um contato pessoal
  comercial
      contato_comercial; // Cria uma struct para armazenar um contato comercial

  pcDesligado();
  delay(3); // Exibe o pc desligado por 3 segundos
  clear();
  apareceAgenda();
  delay(3); // Exibe a agenda abrindo por 3 segundos
  clear();

  do {
    clear();
    menu();
    cin >> *pmenu;

    switch (*pmenu) {
    case 1: // Inserir um novo item na agenda
      clear();
      cout << "1. Agenda pessoal" << endl;
      cout << "2. Agenda comercial" << endl;
      cin >> *opcao;
      if (*opcao == 1) { // Inserir um contato pessoal
        clear();
        preencher(contato_pessoal);
        inserir(agenda_pessoal, contato_pessoal);
        voltarMenu(pmenu);
      } else if (*opcao == 2) { // Inserir um contato comercial
        clear();
        preencher(contato_comercial);
        inserir(agenda_comercial, contato_comercial);
        voltarMenu(pmenu);
      } else { // Volta para o menu
        clear();
        voltarMenu(pmenu);
      }
      break;

    case 2: // Remover um item da agenda
      clear();
      cout << "1. Remover contato da agenda pessoal por ID" << endl;
      cout << "2. Remover contato da agenda pessoal por nome" << endl;
      cout << "3. Remover contato da agenda comercial por ID" << endl;
      cout << "4. Remover contato da agenda comercial por nome" << endl;
      cin >> *opcao;
      if (*opcao == 1) { // Remover um contato da agenda pessoal por ID
        clear();
        cout << "Digite o ID: " << endl;
        cin >> ID;
        remover(agenda_pessoal, ID);
        voltarMenu(pmenu);
      } else if (*opcao == 2) { // Remover um contato da agenda pessoal por Nome
        clear();
        cin.ignore();
        cout << "Digite o nome: " << endl;
        getline(cin, nome);
        remover(agenda_pessoal, pesquisaNome(agenda_pessoal, nome));
        voltarMenu(pmenu);
      } else if (*opcao == 3) { // Remover um contato da agenda comercial por ID
        clear();
        cout << "Digite o ID: " << endl;
        cin >> ID;
        remover(agenda_comercial, ID);
        voltarMenu(pmenu);
      } else if (*opcao ==
                 4) { // Remover um contato da agenda comercial por Nome_empresa
        clear();
        cin.ignore();
        cout << "Digite o nome: " << endl;
        getline(cin, nome);
        remover(agenda_comercial, pesquisaNome(agenda_comercial, nome));
        voltarMenu(pmenu);
      } else { // Volta para o menu
        clear();
        voltarMenu(pmenu);
      }
      break;

    case 3: // Pesquisar um contato na agenda
      clear();
      cout << "1. Pesquisar um contato na agenda pessoal por ID" << endl;
      cout << "2. Pesquisar um contato na agenda pessoal por nome" << endl;
      cout << "3. Pesquisar um contato na agenda comercial por ID" << endl;
      cout << "4. Pesquisar um contato na agenda comercial por nome" << endl;
      cin >> *opcao;
      if (*opcao == 1) { // Pesquisar um contato pessoal por ID
        clear();
        cout << "Digite o ID: " << endl;
        cin >> ID;
        pesquisar(agenda_pessoal, ID);
        voltarMenu(pmenu);
      } else if (*opcao == 2) { // Pesquisar um contato pessoal por Nome
        clear();
        cin.ignore();
        cout << "Digite o nome: " << endl;
        getline(cin, nome);
        pesquisar(agenda_pessoal, pesquisaNome(agenda_pessoal, nome));
        voltarMenu(pmenu);
      } else if (*opcao == 3) { // Pesquisar um contato comercial por ID
        clear();
        cout << "Digite o ID: " << endl;
        cin >> ID;
        pesquisar(agenda_comercial, ID);
        voltarMenu(pmenu);
      } else if (*opcao ==
                 4) { // Pesquisar um contato comercial por Nome_empresa
        clear();
        cin.ignore();
        cout << "Digite o nome da empresa: " << endl;
        getline(cin, nome);
        pesquisar(agenda_comercial, pesquisaNome(agenda_comercial, nome));
        voltarMenu(pmenu);
      } else { // Volta para o menu
        clear();
        voltarMenu(pmenu);
      }
      break;

    case 4: // Ordenar os contatos da agenda
      clear();
      cout << "1. Ordenar os contatos da agenda pessoal " << endl;
      cout << "2. Ordenar os contatos da agenda comercial " << endl;
      cin >> *opcao;
      if (*opcao == 1) { // Ordenar os contatos da agenda pessoal por Nome
        ordenar(agenda_pessoal);
        clear();
        voltarMenu(pmenu);
      } else if (*opcao == 2) {
        ordenar(agenda_comercial); // Ordenar os contatos da agenda comercial
                                   // por Nome_empresa
        clear();
        voltarMenu(pmenu);
      } else { // Volta para o menu
        clear();
        voltarMenu(pmenu);
      }
      break;

    case 5: // Mostrar todos os itens da agenda
      clear();
      cout << "1. Mostrar todos os contatos da agenda pessoal" << endl;
      cout << "2. Mostrar todos os contatos da agenda comercial" << endl;
      cin >> *opcao;
      if (*opcao == 1) {
        clear();
        if (agenda_pessoal.quantidade == 0) {
          cout << "Não há contatos salvos na agenda pessoal." << endl << endl;
          voltarMenu(pmenu);
        } else {
          cout << agenda_pessoal; // Exibe todos os contatos da agenda pessoal
          voltarMenu(pmenu);
        }
      } else if (*opcao == 2) {
        clear();
        if (agenda_comercial.quantidade == 0) {
          cout << "Não há contatos salvos na agenda comercial." << endl << endl;
          voltarMenu(pmenu);
        } else {
          cout << agenda_comercial; // Exibe todos os contatos da agenda
                                    // comercial
          voltarMenu(pmenu);
        }
      }
      break;
    }
  } while (*pmenu != 6); // Continua o loop até que a opção 6 (Encerrar o
                         // programa) seja escolhida
  clear();
  encerraPrograma();
  delay(3); // Exibe a tela de saida por 3 segundos
  clear();
  pcDesligado();
  delay(3); // Exibe o pc desligado por 3 segundos
  clear();

  delete pmenu; // Libera a memória alocada dinamicamente para o ponteiro pmenu
  delete opcao; // Libera a memória alocada dinamicamente para o ponteiro opcao

  return 0; // Encerra o programa
}
