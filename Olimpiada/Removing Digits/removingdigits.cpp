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
	fastio;
	int n; cin >> n;
	vector<int> pot10{1000000, 100000, 10000, 1000, 100, 10, 1};
	int cont = 0;

	while(n != 0){
		vector<int> maxim(7,0);
		int c = n;
		int i = 0;
		for(auto v : pot10){
			if(c/v > 0){
				maxim[i] = c/v;
				c -= maxim[i]*v;
				i++;
			}
		}
		int max = *max_element(maxim.begin(), maxim.end());
		n -= max;
		cont++;	
	}

	cout << cont << endl;
}