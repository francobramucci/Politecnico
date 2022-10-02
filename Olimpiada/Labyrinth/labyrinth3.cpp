#include<bits/stdc++.h>

using namespace std;
#define forn(i,a,n) for(int i=a; i<n; i++)
#define MAX 1000+100
#define fi first
#define se second

int n,m;
char matriz[MAX][MAX];
bool vis[MAX][MAX];
int dist[MAX][MAX];
queue<pair<int,int>> q;

bool validar(int i, int j){
	if(i < 0 || i >= n) return false;
	if(j < 0 || j >= m) return false;
	if(matriz[i][j] == '#') return false;
	if(vis[i][j] == true) return false;
	
	return true;
}

bool BFSgrid(int i, int j){
	vis[i][j] = true;
	dist[i][j] = 0;
	q.push({i,j});

	int s,v;
	while(!q.empty()){
		s = q.front().first;
		v = q.front().second; 
		q.pop();		

		if(matriz[s][v] == 'B'){
			return true;
		} 

		//UP
		if(validar(s-1, v)){
			dist[s-1][v] = dist[s][v] + 1; q.push({s-1, v}); vis[s-1][v] = true;
		} 
		//DOWN
		if(validar(s+1, v)){
			dist[s+1][v] = dist[s][v] + 1; q.push({s+1, v}); vis[s+1][v] = true;
		} 
		//RIGHT
		if(validar(s, v+1)){
			dist[s][v+1] = dist[s][v] + 1; q.push({s, v+1}); vis[s][v+1] = true;
		} 
		//LEFT
		if(validar(s, v-1)){
			dist[s][v-1] = dist[s][v] + 1; q.push({s, v-1}); vis[s][v-1] = true;
		}

	}

	return false;
}

int main(){
	cin >> n >> m;
	int posia, posja, posib, posjb;

	forn(i,0,n){
		forn(j,0,m){
			cin >> matriz[i][j];
			if(matriz[i][j] == 'A'){posia = i; posja = j;} 
			if(matriz[i][j] == 'B'){posib = i; posjb = j;} 
		}
	}

	if(BFSgrid(posia, posja) == true) cout << "YES" << '\n' << dist[posib][posjb] << '\n';
	else cout << "NO";

	return 0;
}
