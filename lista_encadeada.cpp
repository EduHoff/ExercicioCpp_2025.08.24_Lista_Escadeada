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

//ainda vou dá um nome mais apropriado para isso visto que eu haverá outras funções assim como no exercício de lista sequencial
void add_lista(pessoa *&lista, string nome, int cpf) {
    if (lista == NULL) {
        lista = new pessoa;
        lista->nome = nome;
        lista->cpf = cpf;
        lista->proximo = NULL;
    }else {
        pessoa *novo_valor = new pessoa;
        novo_valor->nome = nome;
        novo_valor->cpf = cpf;
        novo_valor->proximo = NULL;

        pessoa *aux = lista;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = novo_valor;
    }
}


void imprimir_lista(pessoa *lista) {
    while (lista != NULL) {
        cout << "Nome: " << lista->nome
             << " | CPF: " << lista->cpf << endl;
        lista = lista->proximo;
    }
    cout << "--------------------------------\n";
}

void liberar_lista(pessoa *&lista) {
    while (lista != NULL) {
        pessoa *aux = lista;
        lista = lista->proximo;
        delete aux;
    }
}

int main(){
    pessoa *lista = NULL;
    //int tamanho;

    Clear();
    add_lista(lista, "Eduardo", 3);
    add_lista(lista, "Edward", 56);
    add_lista(lista, "Ed", 78);

    imprimir_lista(lista);


    liberar_lista(lista);
    return 0;
}