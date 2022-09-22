#include "ingreso.h"

FILE* abrir_archivo(const char *nombre_archivo, char *modo) {
  FILE *archivo = fopen(nombre_archivo, modo);
  assert(archivo != NULL);
  
  return archivo;
}

Snodo* crearLista(){
return NULL;
}

Datos* guardarStruct(FILE* datos_archivo){ // Espacio de memoria para Datos*, guardar todos los campos, fscanf
    Datos* buffer = malloc(sizeof(Datos));
    char* provincias = malloc(sizeof(char) * LARGO_MAXIMO_PALABRA);
    char* vivPartHab = malloc(sizeof(char) * LARGO_MAXIMO_NUMERO);
    char* vivPartDesh = malloc(sizeof(char) * LARGO_MAXIMO_NUMERO);
    char* vivColec = malloc(sizeof(char) * LARGO_MAXIMO_NUMERO);
    
    fscanf(datos_archivo, "%[^,],%[^,],%[^,],%[^\n]\n", provincias, vivPartHab, vivPartDesh, vivColec);

    int largo = strlen(provincias);

    buffer->provincia = malloc(sizeof(char) * (largo + 1)); 
    strcpy(buffer->provincia, provincias);

    buffer->vivPartHab = atoi(vivPartHab);

    buffer->vivPartDesh = atoi(vivPartDesh);

    buffer->vivColec = atoi(vivColec);

    free(provincias);
    free(vivPartHab);
    free(vivPartDesh);
    free(vivColec);

    return buffer;
}

void agregarNodoFinalArchivo(Snodo** lista, Datos* datos){ // Redireccionar Datos* a Snodo-> datos
    Snodo* nuevoNodo = malloc(sizeof(Snodo)); 
    nuevoNodo->datos = datos;
    nuevoNodo->sig = NULL;
    
    if(*lista == NULL){ 
        *lista = nuevoNodo;
    }else{

    Snodo* temp = *lista;
    for(;temp->sig != NULL; temp = temp->sig) {}
        temp->sig = nuevoNodo;
    }

}

void imprimirStruct(Datos* datos){
   printf("\n %22s, %8i, %8i, %8i\n", datos->provincia, datos->vivPartHab, datos->vivPartDesh, datos->vivColec);
}

void slist_print(Snodo** list, FuncionVisitante imprimirDatos){
    Snodo* temp = *list;
    for(;temp != NULL; temp = temp->sig){
        imprimirDatos(temp->datos);
    }
    
}

int sumaVivDesh(Snodo* nodos, int suma){
    return nodos->datos->vivPartDesh + suma;
}


int sumaVivTotal(Snodo* nodos, int suma){
    return nodos->datos->vivPartDesh + nodos->datos->vivPartHab + nodos->datos->vivColec + suma;
}

int fold_listas(Snodo* list, Operador operator){
    Snodo* temp = list;
    int result = 0;
    
    for(;temp != NULL; temp = temp->sig){
        result = operator(temp, result);
    }

  return result;
}

Snodo* duplicarDatos(Snodo* nodos){
    Snodo* retorno = malloc(sizeof(Snodo));
    retorno->datos = malloc(sizeof(Datos));

    retorno->datos->vivPartDesh = (nodos->datos->vivPartDesh) * 2; 
    retorno->datos->vivPartHab = (nodos->datos->vivPartHab) * 2;
    retorno->datos->vivColec = (nodos->datos->vivColec) * 2;

    return retorno;
}

int map_fold_listas2(Snodo* list, Transformacion transformator, Operador operator){ // Versión Optimizada
    Snodo* temp = list;
    Snodo* oper;
    int result = 0;

    for(;temp != NULL; temp = temp->sig){
        oper = transformator(temp);
        result = operator(oper, result);

        free(oper->datos);
        free(oper);   
    }
    return result;
}

void slist_destruir(Snodo* lista) {
    Snodo *nodo_a_eliminar;
    while (lista != NULL) {
        nodo_a_eliminar = lista;
        free(nodo_a_eliminar->datos->provincia);
        free(nodo_a_eliminar->datos);
        lista = lista->sig;
        free(nodo_a_eliminar);
    }
}