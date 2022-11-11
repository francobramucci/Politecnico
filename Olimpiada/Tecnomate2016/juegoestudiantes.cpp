#include<bits/stdc++.h>

using namespace std;

#define forr(i,a,b) for(int i = int(a); i<int(b); i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i = int(n); i > 0; i--)
#define pb push_back
#define endl '\n'

using ll = long long;

const int MAX = 1000+100;

int criba(int n){
	vector<bool> p(MAX, true);
	p[0] = false;
	p[1] = false;
	int primo;
	for(int i = 2; i<n; i++){
		if(p[i]){
			for(int j = i*2; j < n; j+=i){
				p[j] = false;
			}
			primo = i;
		}
	}
	return primo;
}

int main(){
	int n,m; cin >> n >> m;
	cout << criba(n)*criba(m) << endl;
}