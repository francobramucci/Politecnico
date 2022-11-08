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
	int b[MAX];
	int n, d, f; cin >> n >> d >> f;

	forn(i,n){ 
		int v; cin >> v;
		a.pb(v);
	}  
	sort(a.begin(), a.end());
	
	forn(i, n-1) dif.pb(a[i+1] - a[i]-1);
	int k = sqrt(n-1), mayor = 0;
	forn(i, n-1) b[i/k] += dif[i];	

	forn(z, k+1){
		int sum = 0, aux = 1, flag = 0;
		forr(i, z, k+1){
			if(sum + b[i] <= f){
				if(i == k && k*k != n-1) aux += n-1-k*k;
				else aux += k; 
				sum +=b[i];
			}
			else{
				forn(j, k){
					if(sum + dif[i*k + j] <= f){ sum+=dif[i*k + j]; aux++;}
					else{ flag = 1; break;}
				}
				if(i != z && flag == 1) break;
			}
		}
		mayor = max(mayor, aux);
	}

	cout << mayor+f << endl;
}