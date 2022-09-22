#include <stdio.h>
#include <stdlib.h>
 
#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef enum{
    BTREE_RECORRIDO_IN,
    BTREE_RECORRIDO_PRE,
    BTREE_RECORRIDO_POST
} OrdenRecorridoBT;

typedef struct _BTNodo{
    int dato;
    struct _BTNodo* izq;
    struct _BTNodo* der;
} BTNodo;

typedef BTNodo* BTree;

int arbolVacio(BTree arbol){
    if(arbol == NULL) return 1;
    return 0;
}

BTree crearArbol(){
    return NULL;
}

BTree insertarElemento(BTree arbol, int dato){
    if(arbolVacio(arbol)){
        arbol = malloc(sizeof(BTNodo));

        arbol->dato = dato;
        arbol->izq = NULL;
        arbol->der = NULL; 
    }
    else if(arbol->dato > dato)
        arbol->izq = insertarElemento(arbol->izq, dato);
    else
        arbol->der = insertarElemento(arbol->der, dato);

    return arbol;
}

BTree buscarElemento(BTree arbol, int dato){
    if(arbolVacio(arbol))
        return NULL;
    if(arbol->dato == dato)
        return arbol;
    if(dato < arbol->dato)
        return buscarElemento(arbol->izq, dato);
    else
        return buscarElemento(arbol->der, dato);
}

void DFS(BTree arbol, OrdenRecorridoBT ord){
    if(arbolVacio(arbol)){
        //printf("nil");
    }
    else{
        if(ord == BTREE_RECORRIDO_PRE){
            printf("-%i-\n", arbol->dato);
            DFS(arbol->izq, BTREE_RECORRIDO_PRE);
            DFS(arbol->der, BTREE_RECORRIDO_PRE);
        }
        
        if(ord == BTREE_RECORRIDO_IN){
            DFS(arbol->izq, BTREE_RECORRIDO_IN);
            printf("-%i-\n", arbol->dato);
            DFS(arbol->der, BTREE_RECORRIDO_IN);
        }

        if(ord == BTREE_RECORRIDO_POST){
            DFS(arbol->izq, BTREE_RECORRIDO_POST);
            DFS(arbol->der, BTREE_RECORRIDO_POST);
            printf("-%i-\n", arbol->dato);
        }
    }
}

void imprimirBTree(BTree arbol){
    if(arbolVacio(arbol)){
        //printf("nil");
    } 
    else{
        printf("-%i-\n", arbol->dato);
        imprimirBTree(arbol->izq);
        imprimirBTree(arbol->der);
    }
}

int sumaBST(BTree arbol){
    if(arbolVacio(arbol)) return 0;
    return arbol->dato + sumaBST(arbol->izq) + sumaBST(arbol->der);
}

int cantNodos(BTree arbol){
    if(arbolVacio(arbol)) return 0;
    return 1+ cantNodos(arbol->izq) + cantNodos(arbol->der);
}

int altura(BTree arbol){
    if(arbolVacio(arbol)) return 0;
    return MAX(altura(arbol->izq), altura(arbol->der)) +1;
}

int main(){

    BTree arbol1 = crearArbol();

    arbol1 = insertarElemento(arbol1, 10);
    arbol1 = insertarElemento(arbol1, 6);
    arbol1 = insertarElemento(arbol1, 5);
    arbol1 = insertarElemento(arbol1, 4);
    arbol1 = insertarElemento(arbol1, 11);
    
    imprimirBTree(arbol1);

    printf("\n\n");

    imprimirBTree(buscarElemento(arbol1, 2));

    printf("\n %i", sumaBST(arbol1));
    printf("\n %i", cantNodos(arbol1));
    printf("\n %i", altura(arbol1));


    printf("\n\n");

    DFS(arbol1, BTREE_RECORRIDO_POST);

    return 0;
}










