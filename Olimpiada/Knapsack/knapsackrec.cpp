#include <bits/stdc++.h>
 
using namespace std;
 
#define forr(i,a,b) for(int i = int(a); i < int(b); i++)
#define forn(i,n) forr(i,0,n)
#define endl '\n'
#define pb push_back
 
const int MOD = 1e9+7;
const int MAXD = 100000+100, MAXL = 1000+100;
vector<int> precios;
vector<int> paginas;
int dp[MAXD][MAXL];
 
int knapsack(int dinero, int libro){
	if(dinero == 0 || libro == 0) return 0;
	if(dp[dinero][libro] != -1) return dp[dinero][libro];
	if(dinero - precios[libro] >= 0)
		return dp[dinero][libro] = max(knapsack(dinero-precios[libro], libro-1) + paginas[libro], knapsack(dinero, libro-1)) % MOD;
	else 
		return dp[dinero][libro] = knapsack(dinero, libro-1) % MOD;
}
 
int main(){
	int n,x; cin >> n >> x;
	memset(dp, -1, sizeof(dp));
	
	precios.pb(0);
	forn(i,n){
		int v; cin >> v;
		precios.pb(v);
	}
	paginas.pb(0);
	forn(i,n){
		int v; cin >> v;
		paginas.pb(v);
	}
 	
 	for()
}