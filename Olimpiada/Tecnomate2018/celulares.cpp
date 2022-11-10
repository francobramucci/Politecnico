#include <bits/stdc++.h>

using namespace std;

#define forr(i,a,b) for(int i = int(a); i < int(b); i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i = int(n); i > 0; i--)
#define endl '\n'
#define pb push_back

using ll = long long;

int main(){
	int n, k; cin >> n >> k;
	vector<int> c;
	
	forn(i,n){ int v; cin >> v; c.pb(v);}

	sort(c.begin(), c.end());
	int bandera = 0;
	int sum = 0;
	
	dfor(i,c.size()-1){
		sum += c[i];
		if(sum >= k){
			cout << n-i << endl;
			bandera = 1;
			break;
		}
	}
	if(bandera == 0) cout << "-1" << endl;

}