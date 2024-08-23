#ifndef MONTICULO_H
#define MONTICULO_H

#include <stdbool.h>

typedef  enum TipoMonticulo{
    Monticulo_MAXIMO,
    Monticulo_MINIMO,
    Monticulo_NUM_TIPOS
}TipoMonticulo;

typedef struct Monticulo{
    int *celdas;
    int numCeldas;
    int numElementos;
    TipoMonticulo tipo;
}Monticulo;


/**
 * @brief Inicializa una montículo con numCeldas celdas de capacidad
 * 
 * @param m 
 * @param celdas 
 * @param numCeldas 
 */
void Monticulo_inicializa(Monticulo *m,int *celdas,int numCeldas,TipoMonticulo tipo);

/**
 * @brief Introduce un valor en el montículo
 * 
 * @param m 
 * @param valor 
 * @return int 0 Valor introducido, -1 montículo lleno
 */
int Monticulo_introduce(Monticulo *m,int valor);

/**
 * @brief Lee el valor al tope del montículo, no modifica el montículo
 * 
 * @param m 
 * @param destino 
 * @return int 0 Valor leido, -1 montículo vacío
 */
int Monticulo_leeTope(const Monticulo *m,int *destino);

/**
 * @brief Toma el valor al tope del montículo, el valor es removido del
 * montículo
 * 
 * @param m 
 * @param destino 
 * @return int 0 Valor tomado, -1 montículo 
 */
int Monticulo_tomaTope(Monticulo *m,int *destino);


#endif
