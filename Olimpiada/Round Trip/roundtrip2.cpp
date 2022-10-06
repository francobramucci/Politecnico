#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(int i=a; i<(int)n; i++)
#define MAX 100000 + 100
#define pb push_back
#define endl '\n'

int n,m;
vector<int> g[MAX];
bool vis[MAX];
queue<int> q;
int ant[MAX];

bool BFS(int s, int k){
	
	return false;
}

bool BFS(int x){
	for(auto s : g[x]){
		fill(vis, vis+MAX, false);
		vis[s] = true;
		ant[s] = x;
		bool ocur = false;
		q.push(s);

		while(!q.empty()){
			int p = q.front(); q.pop();

			for(auto v : g[p]){
				if(ocur == false && v == x){ocur = true; continue;}
				if(vis[v] == true) continue;
				vis[v] = true;
				ant[v] = p;
				q.push(v);
				if(v == x) return true;
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	forn(i,1,m+1){
		int v, u; cin>>v>>u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	int bandera = 0, cont = 1;
	vector<int> path;

	forn(i,1,n+1){
		if(BFS(i)){
			int aux = i;
			do{
				path.pb(aux);
				aux = ant[aux];
				cont++;
			}while(aux != i);
			path.pb(i);

			cout << cont << endl;

			forn(i,0,path.size()){
				cout << path[i] << ' ';
			}
			cout << endl;

			bandera = 1; 
			break;
		} 
	}

	if(bandera == 0) cout << "IMPOSSIBLE" << endl;
}