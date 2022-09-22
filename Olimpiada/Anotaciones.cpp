#include <x> x = #include <x> x = {iostream, vector, queue, stack, cstring, string.h, algorithm, bits/stdc++.h, string}
using namespace std;

//MACROS

#define forn(i,a,n) for(int i=a; i<n; i++)
#define ll long long
#define pb push_back
/*---------------------------------------*/

//GRAFOS

vector<int> adj[N]; //LISTA DE ADYANCENCIA
bool visited[N];

//INGRESO de 1 a m
forn(i, 1, m+1){
	int u,v; cin >> u >> v;
	adj[u].pb(v);		
	adj[v].pb(u);
} 

//DFS
void dfs(int s) {
	if (visited[s]) return;
	visited[s] = true;
	// process node s
	for (auto u: adj[s]) {
		dfs(u);
	}
}

//BFS
queue<int> q;
int distance[N];

void BFS(int x){
	visited[x] = true;
	distance[x] = 0;
	q.push(x);
	while (!q.empty()) {
		int s = q.front(); q.pop();
		// process node s
		for (auto u : adj[s]) {
			if (visited[u]) continue;
			visited[u] = true;
			distance[u] = distance[s]+1;
			q.push(u);
		}
	}
}
/*---------------------------------------*/

//GRAFOS PONDERADOS

struct arista { int v, peso; }
vector<arista> grafo[N];

//Algoritmo de Bellman Ford: los caminos más cortos desde un nodo a todos los demás
void bellmanford(int x){
	for (int i = 1; i <= n; i++) distance[i] = INF;
	distance[x] = 0;
	for (int i = 1; i <= n-1; i++) {
		for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			distance[b] = min(distance[b], distance[a]+w);
		}
	}
}