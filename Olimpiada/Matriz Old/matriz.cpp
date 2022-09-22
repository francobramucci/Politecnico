#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

void procesaMatriz(vector<vector<int> > matriz, vector<long long> &resultadoEnArreglo, vector<vector<long long> > &resultadoEnMatriz)
{
    int sum = 0, mayor = 0, menor = 99;    
    ll prod = 1;
     
    for(int i=0; i < matriz.size(); i++){
        for(int j=0; j < matriz[i].size(); j++){
            sum = sum + matriz[i][j];
            prod = prod * matriz[i][j];
            mayor = max(mayor, matriz[i][j]);
            menor = min(menor, matriz[i][j]);
        }
    }

    resultadoEnArreglo.resize(4);
    resultadoEnMatriz.resize(3);
    
    for(int i=0; i < resultadoEnMatriz.size(); i++){
        resultadoEnMatriz[i].resize(3);
    }

    resultadoEnArreglo[0] = sum;
    resultadoEnArreglo[1] = prod;
    resultadoEnArreglo[2] = mayor;
    resultadoEnArreglo[3] = menor;

    resultadoEnMatriz[0][0] = sum;
    resultadoEnMatriz[0][1] = prod;
    resultadoEnMatriz[1][0] = mayor;
    resultadoEnMatriz[1][1] = menor;
}
