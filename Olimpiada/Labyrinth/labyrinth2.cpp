#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>
using namespace std;

#define forn(i,a,n) for(int i=a; i<n; i++)
#define MAX 1000 + 100

int n,m;
char matriz[MAX][MAX];
vector<pair<int,int> > grafo[MAX][MAX];

void gridtograph(int i, int j){
	bool bandera[5];
	fill(bandera, bandera+5, false);
	matriz[i][j] = '#';

	if(matriz[i+1][j] == '.' || matriz[i+1][j] == 'B'){
		grafo[i][j].push_back({i+1,j}); grafo[i+1][j].push_back({i, j}); bandera[0]=true;
	} 
	if(matriz[i-1][j] == '.' || matriz[i-1][j] == 'B'){
		grafo[i][j].push_back({i-1,j}); grafo[i-1][j].push_back({i, j}); bandera[1]=true;
	} 
	if(matriz[i][j+1] == '.' || matriz[i][j+1] == 'B'){
		grafo[i][j].push_back({i,j+1}); grafo[i][j+1].push_back({i, j}); bandera[2]=true;
	} 
	if(matriz[i][j-1] == '.' || matriz[i][j-1] == 'B'){
		grafo[i][j].push_back({i,j-1}); grafo[i][j-1].push_back({i, j}); bandera[3]=true;
	} 
	if(bandera[0] == true) gridtograph(i+1, j);
	if(bandera[1] == true) gridtograph(i-1, j);
	if(bandera[2] == true) gridtograph(i, j+1);
	if(bandera[3] == true) gridtograph(i, j-1);
}

char asocmove(int i1, int j1, int i2 , int j2){
	if(i1-1 == i2) return 'D';
	if(i1+1 == i2) return 'U';
	if(j1-1 == j2) return 'R';
	if(j1+1 == j2) return 'L';
	return 0;
}

map<pair<int,int>, string> movimiento;
bool visitado[MAX][MAX];
int distancia[MAX][MAX];
queue<pair<int,int> > q;

void BFS(int i, int j){
	visitado[i][j] = 1;
	distancia[i][j] = 0;
	q.push({i,j});

	while(!q.empty()){
		pair<int,int> s; s = q.front(); q.pop();
		for(auto v : grafo[s.first][s.second]){
			if(visitado[v.first][v.second]) continue;
			visitado[v.first][v.second] = 1;
			distancia[v.first][v.second] = distancia[s.first][s.second]+1;
			q.push({v.first, v.second});
			movimiento[{v.first, v.second}] = movimiento[{s.first, s.second}] + asocmove(v.first, v.second, s.first, s.second);
		}
	}
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	int posi_a, posj_a, posi_b, posj_b;
	
	forn(i,0,n){
		forn(j,0,m){
			cin >> matriz[i][j];
			if(matriz[i][j] == 'A'){ posi_a = i; posj_a = j;} 
			if(matriz[i][j] == 'B'){ posi_b = i, posj_b = j;}
		}
	}
	
	gridtograph(posi_a, posj_a);
	BFS(posi_a, posj_a);

	if(distancia[posi_b][posj_b] != 0){
		cout << "YES" << "\n";
		cout << distancia[posi_b][posj_b] << "\n";
		cout << movimiento[{posi_b, posj_b}] << "\n";
	}
	else cout << "NO" << "\n";

}