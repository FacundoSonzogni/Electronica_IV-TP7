#include "monticulo.h"
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

//DECLARACIÓN DE CONSTANTES
#define PADRE(i) ((i - 1) / 2)
#define IZQUIERDO(i) (2 * i + 1)
#define DERECHO(i) (2 * i + 2)

//DEFINICIÓN DE FUNCIONES LOCALES
/*Función para intercambiar elementos en el montículo*/
static void intercambiar(Monticulo *m, int i, int j) {
    int temp = m->celdas[i];
    m->celdas[i] = m->celdas[j];
    m->celdas[j] = temp;
}

/*Función para "bajar" un elemento en el montículo (heapify)*/
static void bajar(Monticulo *m, int i) {
    int izquierda = IZQUIERDO(i);
    int derecha = DERECHO(i);
    int mejor = i;

    if (izquierda < m->numElementos &&
        ((m->tipo == Monticulo_MAXIMO && m->celdas[izquierda] > m->celdas[mejor]) ||
         (m->tipo == Monticulo_MINIMO && m->celdas[izquierda] < m->celdas[mejor]))) {
        mejor = izquierda;
    }

    if (derecha < m->numElementos &&
        ((m->tipo == Monticulo_MAXIMO && m->celdas[derecha] > m->celdas[mejor]) ||
         (m->tipo == Monticulo_MINIMO && m->celdas[derecha] < m->celdas[mejor]))) {
        mejor = derecha;
    }

    if (mejor != i) {
        intercambiar(m, i, mejor);
        bajar(m, mejor);
    }
}

/*Función para "subir" un elemento en el montículo*/
static void subir(Monticulo *m, int i) {
    while (i > 0 && 
           ((m->tipo == Monticulo_MAXIMO && m->celdas[i] > m->celdas[PADRE(i)]) ||
            (m->tipo == Monticulo_MINIMO && m->celdas[i] < m->celdas[PADRE(i)]))) {
        intercambiar(m, i, PADRE(i));
        i = PADRE(i);
    }
}

//DEFINICIÓN DE FUNCIONES DECLARADAS EN "moticulo.h"

/**
 * @brief Inicializa una montículo con numCeldas celdas de capacidad
 * 
 * @param m 
 * @param celdas 
 * @param numCeldas 
 */
void Monticulo_inicializa(Monticulo *m,int *celdas,int numCeldas,TipoMonticulo tipo)
{
    if (m == NULL || celdas == NULL || numCeldas <= 0) return;
    m->celdas = celdas;
    m->numCeldas = numCeldas;
    m->numElementos = 0;
    m->tipo = tipo;
}

/**
 * @brief Introduce un valor en el montículo
 * 
 * @param m 
 * @param valor 
 * @return int 0 Valor introducido, -1 montículo lleno
 */
int Monticulo_introduce(Monticulo *m,int valor)
{
    if (m == NULL || m->numElementos >= m->numCeldas) return -1;

    m->celdas[m->numElementos] = valor;
    subir(m, m->numElementos);
    m->numElementos++;
    return 0;
}

/**
 * @brief Lee el valor al tope del montículo, no modifica el montículo
 * 
 * @param m 
 * @param destino 
 * @return int 0 Valor leido, -1 montículo vacío
 */
int Monticulo_leeTope(const Monticulo *m,int *destino)
{
    if (m == NULL || destino == NULL || m->numElementos == 0) return -1;

    *destino = m->celdas[0];
    return 0;
}

/**
 * @brief Toma el valor al tope del montículo, el valor es removido del
 * montículo
 * 
 * @param m 
 * @param destino 
 * @return int 0 Valor tomado, -1 montículo 
 */
int Monticulo_tomaTope(Monticulo *m,int *destino)
{
    if (m == NULL || destino == NULL || m->numElementos == 0) return -1;

    *destino = m->celdas[0];
    m->numElementos--;
    m->celdas[0] = m->celdas[m->numElementos];
    bajar(m, 0);
    return 0;
}
