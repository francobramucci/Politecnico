#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define forn(i,a,n) for(int i=a; i<n; i++)
#define MAX 100000 + 100
#define INF 999999
#define pb push_back

int n, m, d;

vector<int> grafo[MAX];
queue<int> q;
bool visit[MAX];
int dist[MAX];

void BFS(int x){
	fill(dist, dist+n, INF);
	fill(visit, visit+n, false);
	visit[x] = true;
	dist[x] = 0;
	q.push(x);
	while(!q.empty()){
		int s = q.front(); q.pop();

		for(int u : grafo[s]){
			if(visit[u]) continue;
			visit[u] = true;
			q.push(u);
			dist[u] = dist[s] + 1;
		}
	}

}


int main(){
	cin >> n >> m >> d;

	for(int i=1; i<=m; i++){
		int a,b; cin >> a >> b;
		grafo[a].pb(b);
		grafo[b].pb(a);
	}

	int distEros[MAX];

	BFS(1);
	for(int i=1; i <= n; i++){
		distEros[i] = dist[i];
	}

	BFS(n);

	int cont = 0;
	for(int i=1; i <= n; i++){
		if(distEros[i] + dist[i] <= d){
			cont++;
		}
	}
	
	cout << cont << "\n";
}