#include <bits/stdc++.h>
 
using namespace std;
 
#define forr(i,a,b) for(int i = int(a); i < int(b); i++)
#define forn(i,n) forr(i,0,n)
#define endl '\n'
#define pb push_back
// idea, dp ini dist, guardar en vector inicios
const int MOD = 1e9+7;
const int MAXI = 100+10, MAXD = 100000+10;
int dp[MAXI][MAXD];
int n, m; 
 
int solve(int ini, int dist, int fin){
	if(ini > m || dist < 0 || ini <= 0) return 0;
	if(dp[ini][dist] != -1) return dp[ini][dist];
	if(dist == 0 && abs(ini-fin) <= 1) return 1;
	if(dist == 0 && abs(ini-fin) > 1) return 0;
 
	return dp[ini][dist] = (solve(ini+1, dist-1, fin) + 
	                        solve(ini, dist-1, fin) +
	                        solve(ini-1, dist-1, fin)) % MOD;
}
 
int main(){
	cin >> n >> m;
	vector<int> num;
	int ini = 0, fin = 0, cont = 0, res = 1, cont0 = 0;
	bool bandera = 0;
	memset(dp, -1, sizeof(dp));
	
	forn(i,n){
		int v; cin >> v;
		num.pb(v);
		if(n == 1 && v == 0){cout << m << endl; return 0;}
		if(v != 0 && num[i-1] != 0 && abs(v-num[i-1]) > 1 && i != 0){cout << 0 << endl; return 0;}
		if(v == 0) cont0++;
		
		int suma = 0;
		if(v == 0 && !bandera){
			if(i == 0) ini = 0;
			else ini = num[i-1];
			cont = 0;
			bandera = 1;
		}
		if(v != 0 && bandera){
			fin = v;
			bandera = 0;
			memset(dp, -1, sizeof(dp));
			if(ini == 0){
				forr(j,1,m+1){
					suma += solve(j, cont-1, fin);
				}
				res *= suma; 
			}
			else res *= solve(ini, cont, fin);
		}
		else{
			if(i == n-1){
				if(ini == 0){
					for(int x = m; x > 0; x--){
						memset(dp, -1, sizeof(dp));
						forr(k,1,m+1){		
							suma += solve(k, cont-1, x);
						}
					}
					res = suma;
				}
				else{
					for(int b = m; b > 0; b--){
						memset(dp, -1, sizeof(dp));
						suma += solve(ini, cont, b);
					}
					res *= suma;
				}
			}
		}	
		cont++;
	}
	if(cont0 == 0) res = 1; 
	cout << res << endl;
}