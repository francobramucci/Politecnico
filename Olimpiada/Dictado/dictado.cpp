#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int  dictado( string palabra )
{   
    int largo = palabra.size();
    int largo1 = largo;
    string palabra1 = palabra;
    string derecho = palabra;
    string reves;

    for(int i = 0; i < largo1; i++){
        reverse(derecho.begin(), derecho.end()); //d = aloh, palabra = hola alo al
        reves = derecho;         //d = aloh, p= hola, r = aloh  alo al
        if(palabra1 == reves){ 
            return i;
        }
        largo--;
        derecho.resize(largo); 
        reverse(derecho.begin(), derecho.end()); 
        palabra1 = derecho; 
    }   
    return palabra.size()-1;

}
