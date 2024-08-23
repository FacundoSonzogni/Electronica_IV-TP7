#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include <stdbool.h>

typedef struct NodoListaEnlazada NodoListaEnlazada;

typedef NodoListaEnlazada *ListaEnlazada;


struct  NodoListaEnlazada
{
    int valor;
    NodoListaEnlazada *siguiente;
};

/**
 * @brief Inicializa un nuevo nodo de lista enlazada. 
 * 
 * @note Si se utiliza sobre un
 * nodo en uso se perderá su contendio y acceso a todos los nodos siguientes en
 * la lista donde se encuentre
 * 
 * @param nodo Puntero al nodo
 * @param valor Valor del nodo inicializado
 */
void NodoListaEnlazada_inicializa(NodoListaEnlazada *nodo,int valor);

/**
 * @brief Inicializa una lista enlazada nueva.
 * 
 * @note Si se usa sobre una lista
 * existente se perderá el acceso a su contenido
 * 
 * @param lista Puntero a lista a inicializar
 */
void ListaEnlazada_inicializa(ListaEnlazada *lista);

/**
 * @brief Inserta un nodo al principio de la lista enlazada
 * 
 * @note El nodo debe ser inicializado antes de insertarlo. Si se hiciese
 * después se perdería el acceso al resto de la lista.
 * 
 * @param lista Puntero a lista a modificar 
 * @param nodo Puntero a nuevo nodo previamente inicializado
 */
void ListaEnlazada_inserta(ListaEnlazada *lista, NodoListaEnlazada *nodo);

/**
 * @brief Determina si una lista está vacía (no tiene elementos)
 * 
 * @param lista Puntero a lista
 * @return true Lista vacía
 * @return false Lista no vacía
 */
bool ListaEnlazada_esVacia(ListaEnlazada *lista);

/**
 * @brief Obtiene el nodo a la cabeza de la lista enlazada
 * 
 * @param lista Puntero a la lista enlazada
 * @return NodoListaEnlazada* Puntero a nodo a la cabeza, NULL si la lista está
 *         vacía
 */
NodoListaEnlazada *ListaEnlazada_obtNodoCabeza(ListaEnlazada *lista);

/**
 * @brief Obtiene el valor a la cabeza de la lista enlazada
 * 
 * @param lista Puntero a lista enlazada
 * @param valor Puntero a variable donde almacenar el valor obtenido
 * @return int 0 si obtuvo el valor, -1 si la lista está vacía
 */
int ListaEnlazada_obtCabeza(ListaEnlazada *lista, int *valor);

/**
 * @brief Obtiene la cola de la lista enlazada. La cola es otra lista que inicia
 * en el nodo siguiente a la cabeza. Puede estar vacía si no hay más nodos
 * 
 * @note La cola de una lista vacía es la misma lista
 * 
 * @param lista Puntero a lista
 * @return ListaEnlazada* Puntero a cola de la lista
 */
ListaEnlazada *ListaEnlazada_obtCola(ListaEnlazada *lista);

/**
 * @brief Remueve el nodo a la cabeza de la lista y retorna una referencia al
 * mismo (para reutilizar o liberar memoria)
 * 
 * @param lista Puntero a lista enlazada
 * @return NodoListaEnlazada* Puntero al nodo removido, NULL si la lista está
 *         vacía 
 */
NodoListaEnlazada *ListaEnlazada_remueveCabeza(ListaEnlazada *lista);

#endif
