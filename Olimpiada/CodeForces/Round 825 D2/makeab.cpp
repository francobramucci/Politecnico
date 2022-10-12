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

const int MAXN = 100+10;

int main(){
	ioshack;
	int t; cin >> t;
	forn(i,t){
		int n, cont1=0, cont2=0, oper=0, bandera = 0; cin >> n;
		vector<int> a,b;
		forn(k,n){
			int h; cin >> h;
			a.pb(h);
			if(a[k] == 1) cont1++;
		}
		forn(k,n){
			int h; cin >> h;
			b.pb(h);
			if(b[k] == 1) cont2++;
		}
		if(a == b) cout << 0 << endl;
		else{
			if(cont1 == cont2) cout << 1 << endl;
			else{
				if(cont2 > cont1){ //Si hay más 1s en B que en A
					for(int j = 0; cont1 != cont2; j++){
						if(a[j] == 0 && b[j] == 1){
							a[j] = 1;
							cont1++;
							oper++;
						}
						if(a == b){bandera=1;cout << oper << endl;break;} 
					}
					if(bandera!=1) cout << 1+oper << endl;		
				}
				else{ //Si hay más 0s en B que en A
					for(int j = 0; cont1 != cont2; j++){ 
						if(a[j] == 1 && b[j] == 0){
							a[j] = 0;
							cont1--;
							oper++;
						}
						if(a == b){bandera=1;cout << oper << endl;break;}
					}
					if(bandera!=1) cout << 1+oper << endl;
				}
			}
		}
	}


}