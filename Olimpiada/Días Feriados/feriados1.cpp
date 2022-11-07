#include <bits/stdc++.h>

using namespace std;

#define ioshack ios_base::sync_with_stdio(false);cin.tie(NULL);
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
const int MAX = 200000+100;

int main(){
	vector<int> a;
	vector<int> dif;
	vector<int> b;
	int n, d, f; cin >> n >> d >> f;

	forn(i,n){ 
		int v; cin >> v;
		a.pb(v);
	}  
	sort(a.begin(), a.end());
	
	forn(i, n-1) dif.pb(a[i+1] - a[i]-1);

	forn(i, n-1){
		forr(j, 0, sqrt(n-1)){
			sum += dif[j+i];
		}
		b.pb(sum);
		sum = 0;
	}


}