#include <iostream>
 
using namespace std;
 
using ll = long long int;
 
const int MAXN = 1000005;

ll x; 
ll valores[105];
ll memo[MAXN];
int n;
 
int solve(int m){
    if(m == x) return 0;
    if(m > x) return MAXN;
    if(memo[m] != 0) return memo[m];
    
    int menor = MAXN;
    
    for(int i=0; i<n; i++){
        menor = min(menor, solve(m + valores[i]) + 1);
    }        
 
    return memo[m] = menor;
}
 
int main(){
    cin >> n; // Ingreso de cant monedas
    cin >> x; // Ingreso de la suma a crear
    
    for(int i = 0; i < n; i++){ // Ingreso de los dif valor
        cin >> valores[i];          
    }
 
    int resultado = solve(0); 
    
    if(resultado == MAXN){
        cout << -1;
    }
    else{
        cout << resultado;
    }
}