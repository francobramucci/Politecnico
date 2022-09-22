#include <stdio.h>
#include <stdlib.h>

typedef struct _Snodo{
    void* dato;
    struct _Snodo* sig; 
}Snodo;

Snodo* crearLista(){
    return NULL;
}

void agregarNodoFinal(Snodo** lista, void* dato){
    Snodo* nuevoNodo;
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;

    

}