#include <bits/stdc++.h>

using namespace std;
#define ioshack ios_base::sync_with_stdio(false);cin.tie(NULL);
#define forr(i,a,b) for(int i = (a); i < int(b); ++i)
#define forn(i,n) forr(i,0,n)
#define sz(v) int(v.size())
#define endl '\n'
#define fi first
#define se second

using ll = long long;
using pii = pair<int,int>;

const ll INF = INT_MAX;  
const int MAX = 2e5+100;

ll s[MAX];
ll a[MAX];
int n,k;

void init(){
	s[0] = INF;
	for(int i=0; i<n; i+=k){
		ll mini = INF;
		forr(j,i,i+k){ mini = min(mini, a[j]);}
		s[i/k] = mini;
	}
}

void querie(int l, int r){
	ll minir = INF;
	int bl = l/k, br = r/k;
	for(int i = l; i < (bl+1)*k; i++) minir = min(minir, a[i]);
	for(int b = bl+1; b < br; b++) minir = min(minir, s[b]);
	for(int i = br*k; i <= r; i++) minir = min(minir, a[i]);
	cout << minir << endl;
}

int main(){
	ioshack;
	int q; cin >> n >> q;
	k = sqrt(n);

	forn(i,n){
		cin >> a[i]; 
	}
	
	init();

	forn(i,q){
		int l,r; cin >> l >> r;
		if(l != r) querie(l-1,r-1);
		else cout << a[l-1] << endl;
	}
}