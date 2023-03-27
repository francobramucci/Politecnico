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

int main(){
	int numeros[] = {1,5,10,20,100};
	int n; cin >> n;
	int i = 4, cont = 0;
	
	while(n != 0){
		if(numeros[i] <= n){
			n -= numeros[i];
			cont++;
		}
		else i--;
	}

	cout << cont << endl;
}