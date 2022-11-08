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
	forn(i, n-1) b[i/k] += dif[i]; //inicializacion	

	forn(z, n-1){
		int sum = 0, aux = 1, bandera = 0;
		int m = z;
		while(m < k*((z/k)+1) && m < n-1){
			if(sum + dif[m] <= f){ sum+=dif[m]; aux++;}  //recorro el bloque actual
			else{ bandera = 1; break;}
			m++;
		}
		if(bandera != 1){
			int r = k;
			if(k*k != n-1) r = k+1;
			forr(i, (z/k)+1, r){
				if(sum + b[i] <= f){
					if(i == k && k*k != n-1) aux += n-1-k*k;	//recorro los siguientes bloques
					else aux += k; 
					sum += b[i];
				}
				else{
					forn(j, k){
						if(sum + dif[i*k + j] <= f){ sum+=dif[i*k + j]; aux++;} //recorro parte del bloque
						else break;
					}
					break;
				}
			}
		}
		mayor = max(mayor, aux);
	}

	if(mayor+f > d) cout << d << endl;
	else cout << mayor+f << endl;
}