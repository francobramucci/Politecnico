#include <bits/stdc++.h>

using namespace std;
#define forr(i,a,b) for(int i = int(a); i<int(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define endl '\n'

using ll = long long;

int main(){
	int t; cin >> t;
	
	forn(j,t){
		int n; cin >> n;
		int x = 1, y = 0, aux;
		forn(i,n){
			aux = y; //aux = 0,1,2
			y = y + x;	// y = 1,2,5
			x = y + aux;	// x = 1,3
		}
		cout << x << ' '<< y << endl;
	}
}