#include<bits/stdc++.h>

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
bool color[MAX];

void BFSpintar(int x){
	vis[x] = true;
	q.push(x);
	bool pintura;

	while(!q.empty()){
		int s = q.front(); q.pop();
		if(color[s]) pintura = false;
		else pintura = true;	
		for(auto v : g[s]){
			if(vis[v]) continue;
			vis[v] = true;
			q.push(v);
			color[v] = pintura;	
		}	
	}

}

int ifbipartito(int x){
	vis[x] = true;
	q.push(x);
	int cont = 0, num = 0;
	while(!q.empty()){
		cont = 0;
		int s = q.front(); q.pop();
		for(auto v : g[s]){
			if(color[v] != color[s]) cont++;
			if(vis[v]) continue;
			vis[v] = true;
			q.push(v);
		}
		if(cont == (int)g[s].size()) num++;
	}
	return num; 
}

int main(){
	cin >> n >> m;

	forn(i,1,m+1){
		int v,u;cin>>v>>u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	forn(i,1,n+1){
		if(vis[i]) continue;
		BFSpintar(i);
	}
	
	fill(vis, vis+MAX, false);

	int sum=0;
	forn(i,1,n+1){
		if(vis[i]) continue;
		sum = sum + ifbipartito(i);
	}
	
	if(sum == n){
		forn(i,1,n+1){
			if(!color[i]) cout << 1;
			else cout << 2;
			cout << ' '; 
		}	
	}
	else cout << "IMPOSSIBLE";

	cout << endl;
}