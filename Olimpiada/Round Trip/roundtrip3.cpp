#include <bits/stdc++.h>

using namespace std;
#define forn(i,a,n) for(int i=a; i<(int)n; i++)
#define pb push_back
#define MAX 100000+100
#define endl '\n'

int n,m;
vector<int> g[MAX];
bool vis[MAX];
int ant[MAX];
queue<int> q;

int DFS(int x){
	stack<int> p;
	vis[x] = true;
	p.push(x);

	while(!p.empty()){
		int s = p.top(); p.pop();

		for(auto v : g[s]){
			if(vis[v] && v!= ant[s]) return v;
			if(vis[v]) continue;
			vis[v] = true;
			p.push(v);
			ant[v] = s; 
		}
	}
	return 0;
}

void BFS(int x){
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
				if(v == x) return;
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	forn(i,1,m+1){
		int u,v; cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	int nodo=0;

	forn(i,1,n+1){
		if(!vis[i]){
			int result = DFS(i);
			if(result != 0){nodo = result;break;}
		} 
	}

	int cont = 1;
	vector<int> path;

	if(nodo != 0){
		BFS(nodo);
		int aux = nodo;
		do{
			path.pb(aux);
			aux = ant[aux];
			cont++;
		}while(aux != nodo);
		path.pb(nodo);

		cout << cont << endl;

		forn(i,0,path.size()){
			cout << path[i] << ' ';
		}
		cout << endl;
	}
	else cout << "IMPOSSIBLE" << endl;
}