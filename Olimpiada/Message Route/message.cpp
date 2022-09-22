#include <iostream>
#include <vector>
#include <queue>


using namespace std;
#define forn(i,a,n) for(int i=a; i<n; i++)
#define pb push_back
#define MAX 100000 +100

int n,m;
vector<int> grafo[MAX];
bool visit[MAX];
int ant[MAX];
int dist[MAX];
queue<int> q;

void BFS(int x){
	visit[x] = true;
	dist[x] = 0;
	q.push(x);
	ant[x] = -1;
	while(!q.empty()){
		int s = q.front(); q.pop();
		for(int u : grafo[s]){
			if(visit[u]) continue;
			visit[u] = true;
			dist[u] = dist[s]+1;
			q.push(u);
			ant[u] = s;
		}
	}

}

vector<int> result;

void print(int n, int cont){
	result.resize(cont+1);
	if(ant[n] != -1){
		result[cont] = n;
		print(ant[n], cont+1);
	}
	else result[cont] = n;
}

int main(){
	cin >> n >> m;

	forn(i, 1, m+1){
		int u,v; cin >> u >> v;
		grafo[u].pb(v);
		grafo[v].pb(u);
	}

	BFS(1);

	if(visit[n]){ 
		cout << dist[n]+1 << "\n";
		print(n,0);
		for(int i=result.size()-1; i >= 0; i--){
			cout << result[i] << ' ';
		}

	}
	else cout << "IMPOSSIBLE";

}