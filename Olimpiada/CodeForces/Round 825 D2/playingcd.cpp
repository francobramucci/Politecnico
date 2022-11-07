#include<bits/stdc++.h>
#include<numeric>

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
#define MAX 100000+100


int main(){
	int n; cin >> n;

	forn(i,n){
		int s;cin >> s;
		int a[MAX];
		int b[MAX];
		a[0] = 1;
		forr(j,1,s+1){
			cin >> a[j];
			b[j] = lcm(a[j], a[j-1])
		}
		cout << lcm(a[s], 1) << endl;

	}


}