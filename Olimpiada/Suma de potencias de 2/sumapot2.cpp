#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
using ll = long long;
const int MOD = 1e9+7;

int pot(ll a, ll b){
	if(b == 0) return 1;
	ll x = pot(a, b/2);
	if(b % 2 == 0) return (x*x) % MOD;
	return (x*x*a) % MOD;
}

int main(){
	int n; cin >> n;
	cout << pot(2,n+1)-1 << endl;
}