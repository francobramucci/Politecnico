#### Trabajo Practico 2 - Listas - Hecho por Franco Bramucci y Matias Nucciotti

## Compilación
	gcc main.c ingreso.c

# Windows

 	a.exe viviendas_por_provincias.csv

# Linux

 	./a.out viviendas_por_provincias.csv

## Aclaraciones:

- Al compilar y ejecutar, lo primero que veremos es la lista original, con todos sus datos, mostrada en pantalla sin ninguna modificación. Inmediatamente debajo de esto, encontramos la cantidad total de viviendas deshabitadas, calculada mediante la función fold_listas como se solicita en el apartado 4). 

Debajo de este dato, encontramos la cantidad de viviendas deshabitadas multiplicada por 2, obteniendose esto por el uso de la función map_fold_listas2, solicitada en el apartado 5). El hecho de multiplicar por 2 es un mero ejemplo para corroborar que se aplican transformaciones mediante map_fold_listas2 de forma correcta. 

Finalmente, se muestra nuevamente la lista, para dejar en claro que la lista original no fue modificada por map_fold_listas2, tal como se pide en el apartado 5).
