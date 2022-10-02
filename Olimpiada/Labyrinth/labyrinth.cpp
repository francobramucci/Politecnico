#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 1100
#define forn(i,a,n) for(int i=a; i<n; i++)
const string INF = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

char matriz[MAX][MAX];
int n,m;

string searchB(char matriz1[][MAX], int i, int j){

	int bandera = 0;

	if(matriz1[i][j+1] == 'B') return "R"; 
	if(matriz1[i][j-1] == 'B') return "L";
	if(matriz1[i+1][j] == 'B') return "D";
	if(matriz1[i-1][j] == 'B') return "U";

	if(matriz1[i][j+1] == '.'){
		s1 = "R" + searchB(matrizaux, i, j+1);
		bandera = 1;
	}

	if(matriz1[i][j-1] == '.'){ 
		s2 = "L" + searchB(matrizaux, i, j-1);
		bandera = 1;
	}

	if(matriz1[i+1][j] == '.'){
		s3 = "D" + searchB(matrizaux, i+1, j);
		bandera = 1;
	} 

	if(matriz1[i-1][j] == '.'){
		s4 = "U" + searchB(matrizaux, i-1, j);
		bandera = 1;
	}
	
	if(bandera != 1) return INF;

	long unsigned int minimo = min( min(s1.length(), s2.length()), min(s3.length(), s4.length()) );

	if(s1.length() == minimo) return s1;
	if(s2.length() == minimo) return s2;
	if(s3.length() == minimo) return s3;
	if(s4.length() == minimo) return s4;
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	string solve;

	forn(i,0,n){
		forn(j,0,m){
			cin >> matriz[i][j];
		}
	}

	forn(i,0,n){
		forn(j,0,m){
			if(matriz[i][j] == 'A'){
				solve = searchB(matriz, i, j);				
			}
		}
	}

	if(solve >= INF){
		cout << "NO" << "\n";
	}
	else{
		cout << "YES" << "\n";
		cout << solve.length() << "\n";
		cout << solve << "\n";
	}
}