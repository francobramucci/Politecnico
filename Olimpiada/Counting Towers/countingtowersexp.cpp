#include <bits/stdc++.h>
 
using namespace std;
 
#define forr(i,a,b) for(int i = int(a); i < int(b); i++)
#define dfor(i,n) for(int i = n; i > 0; i--)
#define forn(i,n) forr(i,0,n)
#define endl '\n'
#define pb push_back
 
using ll = long long;
 
const int MAX = 1000000+100;
const int MOD = 1e9+7;
 
ll dpD[MAX], dpS[MAX];
 
//ll D(int); // Defino las dos funciones para hacer
ll S(int); // la mutua recursión
 
ll D(int n){
	if(n == 0) return 1;
	if(dpD[n] != -1) return dpD[n];
 
	return dpD[n] = (D(n-1)*2 + S(n-1)) % MOD;
}
 
ll S(int n){
	if(n == 0) return 1;
	if(dpS[n] != -1) return dpS[n];
	
	return dpS[n] = (S(n-1)*4 + D(n-1)) % MOD;
}
 
ll solve(int n){  
	int res = D(n-1);
	res += S(n-1);
	return res %= MOD;
}
 
int main(){
	memset(dpD, -1, sizeof(dpD));
	memset(dpS, -1, sizeof(dpS));
	
	for(int i = 0; i<MAX; i+=1000){
		D(i); S(i);
	}
 
	int n; cin >> n;
	forn(i,n){
		int v; cin >> v;
		cout << solve(v) << '\n';
	}
	
}
