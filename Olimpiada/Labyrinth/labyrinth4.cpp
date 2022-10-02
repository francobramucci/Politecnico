#include<bits/stdc++.h>
 
using namespace std;
#define forn(i,a,n) for(int i=a; i<(int)n; i++)
#define MAX 1000+100
#define fi first
#define se second
#define pb push_back
#define endl '\n'
 
int n,m;
char matriz[MAX][MAX];
bool vis[MAX][MAX];
int dist[MAX][MAX];
queue<pair<int,int>> q;
char ant[MAX][MAX];
vector<char> path;
 
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
			while(matriz[s][v] != 'A'){
				path.pb(ant[s][v]);
				if(path.back() == 'U') s++;
				if(path.back() == 'D') s--;
				if(path.back() == 'R') v--;
				if(path.back() == 'L') v++;				
			}
			return true;
		} 
		
		pair<int,int> p[4] = {{s-1,v}, {s+1, v}, {s, v+1}, {s, v-1}};
		char mov[4] = {'U', 'D', 'R', 'L'};
		
		forn(i,0,4){
			if(validar(p[i].fi, p[i].se)){
				dist[p[i].fi][p[i].se] = dist[s][v] + 1; q.push({p[i].fi, p[i].se}); vis[p[i].fi][p[i].se] = true;
				ant[p[i].fi][p[i].se] = mov[i];
			}
		}
	}
	return false;
}
 
int main(){
	cin >> n >> m;
	int posia=0, posja=0, posib=0, posjb=0;
 
	forn(i,0,n){
		forn(j,0,m){
			cin >> matriz[i][j];
			if(matriz[i][j] == 'A'){posia = i; posja = j;} 
			if(matriz[i][j] == 'B'){posib = i; posjb = j;} 
		}
	}
 
	if(BFSgrid(posia, posja) == true){
		cout << "YES" << '\n' << dist[posib][posjb] << '\n' ;
		while(!path.empty()){cout << path.back(); path.pop_back();}
		cout << endl;
	}	 
	else cout << "NO";
}