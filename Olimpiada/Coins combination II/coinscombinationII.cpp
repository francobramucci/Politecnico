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
const int MAX = 1000000;


int dp[MAX];

int main(){
	fastio;
	int n,x; cin >> n >> x;
	vector<int> coins;
	forn(i,n){ int v; cin >> v; coins.pb(v); }

	dp[0] = 1;

	forn(i,n){ 														// Iteramos por la cantidad de monedas
		forr(num,1,x+1){ 											// Iteramos por todos los numeros de 0 a x para sacar sus posibles combinaciones
			if(num-coins[i] >= 0){ 									// Solo nos interesan los positivos
				dp[num] = (dp[num] + dp[num-coins[i]])%MOD; 		// Si existen combinaciones para la resta entre num y esa moneda, entonces
			}
		}
	}
	cout << dp[x] << endl;
}		