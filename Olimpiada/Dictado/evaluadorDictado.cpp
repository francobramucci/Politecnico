// La siguiente linea se usa para compilar en Geany con F9. Compilando de otra forma, podria ser necesario quitarla.

#include <iostream>
#include <string>

using namespace std;

int  dictado( string palabra );


int main()
{
    string s; cin >> s;
    cout << dictado(s) << endl;
    return 0;
}
