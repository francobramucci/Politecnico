#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define forn(i,a,n) for(int i=a; i<n; i++)
#define INF -99999
#define MAX 1100

int m,n;
char matriz[MAX][MAX]; 
int memo[MAX][MAX];

int solve(int i, int j){			//i eje Y, j eje X
	if(i >= m || i < 0) return INF;
	if(j < 0) return INF;
	if(matriz[i][j] == 'A') return 0;
	if(memo[i][j] != -1) return memo[i][j];

	int contmonedas = max({
		solve(i-1, j-1),
		solve(i+1, j-1),
		solve(i, j-1)
	});

	if(matriz[i][j] == 'M' && contmonedas <= 0) return memo[i][j] = INF;
	if(matriz[i][j] == 'M' && contmonedas > 0) return memo[i][j] = 0;
	if(matriz[i][j] == 'J') return memo[i][j] = contmonedas +1;

	return memo[i][j] = contmonedas;
}

int main(){
	cin >> m >> n;

	forn(i,0,m){
		forn(j,0,n){
			cin >> matriz[i][j];
		}
	}

	forn(i,0,m){
		memset(memo[i], -1, sizeof(memo[i]));
	}


	int resultado = solve(0,n);

	forn(i,1,m){
		resultado = max(solve(i, n), resultado);
	}

	if(resultado < 0){
		cout << "SIN SALIDA" << "\n";
	}
	else{
		cout << resultado << "\n";
	}
	
}