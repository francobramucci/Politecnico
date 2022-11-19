#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define forr(i,a,b) for(int i = (a); i < int(b); ++i)
#define forn(i,n) forr(i,0,n)
#define sz(v) int(v.size())
#define endl '\n'
#define fi first
#define se second
#define pb push_back
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

const int MOD = 1e9+7;
const int MAXD = 100000+100;

int dp[MAXD];
 
// Recursive:
/*
int knapsack(int dinero, int libro){
	if(dinero == 0 || libro == 0) return 0;
	if(dp[dinero][libro] != -1) return dp[dinero][libro];
	if(dinero - precios[libro] >= 0)
		return dp[dinero][libro] = max(knapsack(dinero-precios[libro], libro-1) + paginas[libro], knapsack(dinero, libro-1)) % MOD;
	else 
		return dp[dinero][libro] = knapsack(dinero, libro-1) % MOD;
}
*/

int main(){
	fastio;
	int n,x; cin >> n >> x;
	vector<int> precios;
	vector<int> paginas;

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
 // Iterative:

 	forr(i,1,n+1){ // 1: precio = 4, paginas = 5
 		for(int j = x; j>0; j--){
 			if(j >= precios[i]){
 				dp[j] = max(dp[j-precios[i]] + paginas[i], dp[j]);
 			}
 		}
 	}
 	cout << dp[x] << endl; 

 	return 0;
}