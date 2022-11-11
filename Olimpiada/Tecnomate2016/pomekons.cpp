#include <bits/stdc++.h>

using namespace std;

#define forr(i,a,b) for(int i = int(a); i<int(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define endl '\n'

using ll = long long;

int main(){
	int n; cin >> n;
	vector<string> h;
	map<string, bool> c;
	forn(i,n){
		string v; cin >> v;
		h.pb(v);
		c[v] = false;
	}
	
	int cont =0;
	forn(i,n){
		if(c[h[i]] == false){
			c[h[i]] = true;
			cont++;
		}
	}

	cout << "Falta(m) " << 151-cont << " pomekon(s)"<< endl;

}

