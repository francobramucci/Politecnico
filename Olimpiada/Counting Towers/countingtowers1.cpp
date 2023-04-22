#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define forr(i,a,b) for(int i = a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
const ll MAX = 1000000+100;
const ll MOD = 1e9+7;
 
int dpD[MAX], dpS[MAX];
 
ll D(int); // Defino las dos funciones para hacer
ll S(int); // la mutua recursión
 
ll D(int n){
	if(n == 0) return 1;
	if(dpD[n]) return dpD[n];
	return dpD[n] = (2*D(n-1) + S(n-1)) % MOD;
}
 
ll S(int n){
	if(n == 0) return 1;
	if(dpS[n]) return dpS[n];
	return dpS[n] = (4*S(n-1) + D(n-1)) % MOD;
}
 
int solve(int n){
	return (D(n-1) + S(n-1)) % MOD;
}
 
int main(){
	
	int n; cin >> n;
	forn(i,n){
		int v; cin >> v;
		cout << solve(v) << '\n';
	}
	return 0;
}