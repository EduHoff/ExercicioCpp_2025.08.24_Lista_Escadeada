#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "portable_utils.h"

using namespace std;

typedef struct pessoa {
    string nome;
    int cpf;
    pessoa *proximo;
}pessoa;


void criar_lista(pessoa *&lista, string nome, int cpf) {
    lista = new pessoa;
    lista->nome = nome;
    lista->cpf = cpf;
    lista->proximo = nullptr;
}

int tamanho_lista(pessoa *lista) {
    int tamanho = 0;
    pessoa *aux = lista;

    while (aux != nullptr) {
        aux = aux->proximo;
        tamanho = tamanho + 1;
    }
    return  tamanho;
}

void add_inicio_lista(pessoa *&lista, string nome, int cpf) {
    if (lista == nullptr) {
        criar_lista(lista, nome, cpf);
    }else {
        pessoa *novo_valor = new pessoa;
        novo_valor->nome = nome;
        novo_valor->cpf = cpf;

        novo_valor->proximo = lista;
        lista = novo_valor;
    }
}

void add_fim_lista(pessoa *&lista, string nome, int cpf) {
    if (lista == nullptr) {
        criar_lista(lista, nome, cpf);
    }else {
        pessoa *novo_valor = new pessoa;
        novo_valor->nome = nome;
        novo_valor->cpf = cpf;
        novo_valor->proximo = nullptr;

        pessoa *aux = lista;
        while (aux->proximo != nullptr) {
            aux = aux->proximo;
        }
        aux->proximo = novo_valor;
    }
}

void add_lista_index(int index, pessoa *&lista, string nome, int cpf) {
    if (index < 0 || index > tamanho_lista(lista)) {
        cout << "\nIndex " << index << ": posicao invalida!\n";
        return;
    }

    if (lista == nullptr) {
        criar_lista(lista, nome, cpf);
        return;
    }

    if (index == 0) {
        add_inicio_lista(lista, nome, cpf);
        return;
    }

    if (index == tamanho_lista(lista)) {
        add_fim_lista(lista, nome, cpf);
        return;
    }

    pessoa *novo_valor = new pessoa;
    novo_valor->nome = nome;
    novo_valor->cpf = cpf;

    pessoa *proximo_valor = lista;
    pessoa *valor_anterior = nullptr;

    int i=0;
    while (proximo_valor != nullptr && i < index) {
        valor_anterior = proximo_valor;
        proximo_valor = proximo_valor->proximo;
        i++;
    }

    valor_anterior->proximo = novo_valor;
    novo_valor->proximo = proximo_valor;
}


void remove_inicio_lista(pessoa *&lista) {
    if (lista == nullptr) {
        cout << "\nLista ja esta vazia!";
    }else {
        pessoa *aux = lista;
        lista = lista->proximo;
        delete aux;
     }
}

void remove_fim_lista(pessoa *&lista) {
    if (lista == nullptr) {
        cout << "\nLista ja esta vazia!";
    }else {

        if (tamanho_lista(lista) == 1) {
            remove_inicio_lista(lista);
            return;
        }

        //preciso de dois ponteiros, vou continar a fazer isso outro dia
        pessoa *aux1 = lista;
        pessoa *aux2 = nullptr;

        int i=0;
        while (aux1->proximo != nullptr) {
            if (i == tamanho_lista(lista) - 2) {
                cout << "\nAqui: "<< aux1->nome << endl;
                break;
            }
            aux1 = aux1->proximo;
            i++;
        }

        aux2 = aux1->proximo;
        aux1->proximo = nullptr;
        delete aux2;
    }
}

void imprimir_lista(pessoa *lista) {
    int i=0;
    while (lista != nullptr) {
        cout << "Valor: " << i
             << " Nome: " << lista->nome
             << " | CPF: " << lista->cpf << endl;
        lista = lista->proximo;
        i++;
    }
    cout << "--------------------------------\n";
}

void liberar_lista(pessoa *&lista) {
    while (lista != nullptr) {
        pessoa *aux = lista;
        lista = lista->proximo;
        delete aux;
    }
}

int main(){
    pessoa *lista = nullptr;



    Clear();
    add_fim_lista(lista, "Eduardo", 3);
    add_fim_lista(lista, "Edward", 56);
    add_fim_lista(lista, "Ed", 78);
    add_inicio_lista(lista, "Sim", 1);
    add_lista_index(4, lista, "Meio", 22);
    imprimir_lista(lista);

    remove_inicio_lista(lista);
    remove_fim_lista(lista);
    imprimir_lista(lista);

    liberar_lista(lista);
    return 0;
}