#include <iostream>
#include <vector>

using namespace std;

#define MAX 1100

char matriz[MAX][MAX];

void quitarVecinos(char matriz[][MAX], int i, int j){

	matriz[i][j] = '#';
	if(matriz[i][j+1] == '.') quitarVecinos(matriz, i, j+1);
	if(matriz[i][j-1] == '.') quitarVecinos(matriz, i, j-1);
	if(matriz[i+1][j] == '.') quitarVecinos(matriz, i+1, j);
	if(matriz[i-1][j] == '.') quitarVecinos(matriz, i-1, j);
}


int main(){
	int n, m, cont = 0;
	cin >> n >> m;

	for(int i=0; i < n; i++){
		for(int j = 0 ; j < m; j++){
			cin >> matriz[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j=0; j<m; j++){
			if(matriz[i][j] == '#') continue;
				quitarVecinos(matriz, i, j);
				cont++;
		}
	}

	cout << cont;
}