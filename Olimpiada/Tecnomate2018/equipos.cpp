#include <bits/stdc++.h>

using namespace std;

#define ioshack ios_base::sync_with_stdio(false);cin.tie(NULL);
#define forr(i,a,b) for(int i = int(a); i < int(b); ++i)
#define forn(i,n) forr(i,0,n)
#define sz(v) int(v.size())
#define endl '\n'
#define fi first
#define se second
#define pb push_back
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

int main(){
	vector<int> h;
	ll total = 0;
	forn(i,10){ 
		int v; cin >> v; h.pb(v);
		total += v;
	}
	int suma = 0;
	int menor = 99999999;
	forn(i,10){
		suma = 0;
		forr(j,i+1,10){
			suma = h[i];
			suma += h[j];
			forr(k,j+1,10){
				suma = h[i] + h[j];
				suma += h[k];
				forr(z,k+1,10){
					suma = h[i] + h[j] + h[k];
					suma += h[z];
					forr(w,z+1,10){
						suma = h[i] + h[j] + h[k] + h[z];
						suma += h[w];
						menor = min(menor, int(abs(suma - (total-suma))));
					}
				}
			}
		}
	}
	cout << menor << endl;

}

