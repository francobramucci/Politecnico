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

int binpow(ll a, ll b){
	if(b == 0) return 1;
	ll res = binpow(a, b/2);
	if(b % 2)
		return (res * res * a) % MOD;
	else
		return (res * res) % MOD;
}

int binpow2(ll a, ll b){
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main(){
	int n; cin >> n;
	cout << binpow(2,n) << endl;
}