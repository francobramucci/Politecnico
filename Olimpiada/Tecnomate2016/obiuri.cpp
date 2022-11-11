#include<bits/stdc++.h>

using namespace std;

#define forr(i,a,b) for(int i = int(a); i < int(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define endl '\n'

using ll = long long;

int main(){
	int n; cin >> n;

	forn(i,n){
		string v; cin >> v;
		if(v.size() == 3){
			if(v[0] == 'O' && v[1] == 'B' && v[2] != 'I'){
				cout << "OBI";
			}
			else if(v[0] == 'U' && v[1] == 'R' && v[2] != 'I'){
				cout << "URI";
			}
			else cout << v; 
		}
		else cout << v;
		cout << ' '; 
	}




}