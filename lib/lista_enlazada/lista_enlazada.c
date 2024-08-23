#include "lista_enlazada.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

void NodoListaEnlazada_inicializa(NodoListaEnlazada *nodo,int valor)
{
    if (nodo != NULL) {
        nodo->valor = valor;
        nodo->siguiente = NULL;
    }
}

void ListaEnlazada_inicializa(ListaEnlazada *lista)
{
    if (lista != NULL) {
        *lista = NULL;
    }
}

void ListaEnlazada_inserta(ListaEnlazada *lista, NodoListaEnlazada *nodo)
{
    if (lista != NULL && nodo != NULL) {
        nodo->siguiente = *lista;
        *lista = nodo;
    }
}

NodoListaEnlazada *ListaEnlazada_obtNodoCabeza(ListaEnlazada *lista)
{
    if (lista != NULL) {
        return *lista;
    }
    return NULL;
}

bool ListaEnlazada_esVacia(ListaEnlazada *lista)
{
  return (lista != NULL && *lista == NULL);
}

int ListaEnlazada_obtCabeza(ListaEnlazada *lista, int *valor)
{
    if (lista != NULL && *lista != NULL && valor != NULL) {
        *valor = (*lista)->valor;
        return 0;  
    }
    return -1;  
}

ListaEnlazada *ListaEnlazada_obtCola(ListaEnlazada *lista)
{
    if (ListaEnlazada_esVacia(lista)) {
        return lista;
    }
    return &((*lista)->siguiente);
}

NodoListaEnlazada *ListaEnlazada_remueveCabeza(ListaEnlazada *lista)
{
    if (lista != NULL && *lista != NULL) {
        NodoListaEnlazada *nodoRemovido = *lista;
        *lista = (*lista)->siguiente;
        nodoRemovido->siguiente = NULL;
        return nodoRemovido;
    }
    return NULL;
}
