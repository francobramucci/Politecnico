#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define MAX 1100
#define forn(i,a,n) for(int i=a; i<n; i++)
#define INF -9999999


int n,m;
char matriz[MAX][MAX];
int memo[MAX][MAX];

int solve(int i, int j, int cont){
	if(i > m || i < 0) return INF;
	if(j > n) return cont;
	if(cont == 0 && matriz[i][j] == 'M') return INF;
	if(memo[i][j] != -1) return memo[i][j];
	
	if(matriz[i][j] == 'M') return memo[i][j] = max( max(solve(i, j + 1, 0), solve(i + 1, j + 1, 0)), solve(i - 1, j + 1, 0) );
	if(matriz[i][j] == 'J') return memo[i][j] = max( max(solve(i, j + 1, cont+1), solve(i + 1, j + 1, cont+1)), solve(i - 1, j + 1, cont+1) ) ;
	return memo[i][j] = max( max(solve(i, j + 1, cont), solve(i + 1, j + 1, cont)), solve(i - 1, j + 1, cont) );	
}

int main(){
	cin >> m >> n;
	int indice, resultado;

	forn(i,0,MAX){
		forn(j,0,MAX){
			memo[i][j] = -1;
		}
	}

	forn(i,0,m){
		forn(j,0,n){
			cin >> matriz[i][j];
		}
		if(matriz[i][0] == 'A') indice = i;
	}

	resultado = solve(indice, 0, 0);

	if(resultado < 0){ 
		cout << "SIN SALIDA" << "\n";
	}
	else{
		cout << resultado << "\n";
	}
}