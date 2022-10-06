#include <bits/stdc++.h>

using namespace std;
#define forn(i,a,n) for(int i=a; i<(int)n; i++)
#define MAX 100000+100
#define fi first
#define se second
#define pb push_back
#define endl '\n'

int n,m;

vector<int> g[MAX];
bool vis[MAX];
queue<int> q;
int ant[MAX];

bool BFS(int x){
	bool cont = false;
	q.push(x);
	while(!q.empty()){

		int s = q.front();q.pop();
		if(s != x) vis[s] = true;
		for(auto v : g[s]){
			if(s == x){q.push(v); continue;} 
			if(v == x && !cont){cont = true; continue;}
			if(vis[v]) continue;
			vis[v] = true;
			ant[v] = s;
			q.push(v);
		}
		if(vis[x]) return true;
	}
	return false;
}

int main(){
	cin>>n>>m;

	forn(i,1,m+1){
		int v,u; cin>>v>>u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	bool bandera = false;
	int cant = 1;
	vector<int> c;
	forn(i,1,n+1){
		if(BFS(i)){
			bandera = true;
			int aux = i;
			
			while(aux != 0){
				c.pb(aux);
				aux = ant[aux];
				cant++;
			}
			c.pb(i);
			cout << cant << endl;
			
			forn(i,0,c.size()){
				cout << c[i] << ' ';
			}
			cout << endl;
			break;
		}
	}
	if(!bandera) cout << "IMPOSSIBLE";
}