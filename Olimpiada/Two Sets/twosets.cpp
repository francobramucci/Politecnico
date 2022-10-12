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
#define MAX 2000000+100

ll n;
ll sum = 0;
int cont=0;
bool num[MAX];

void hola(ll s, ll b){
	if(s == sum/2){
		cont++;
		num[n] = true;
		return;
	}
	if(s+b == sum/2){
	 	num[b] = true;
	 	num[n] = true;
	 	cont+=2;
	} 
	if(s+b < sum/2){
	 	num[b] = true;
		hola(s+b, b-1);
		cont++;
	}
	if(s+b > sum/2) hola(s,b-1);
}

int main(){
 	ioshack;
 	cin >> n;

	for(int i = 1; i <= n; i++) sum += i;

	if(sum%2 == 0 && n != 1){
		cout << "YES" << endl;
		hola(n,n-1);
		cout << cont << endl;
		forr(i,1,n+1) if(num[i]) cout << i << ' ';
		cout << endl << n-cont << endl;
		forr(i,1,n) if(!num[i]) cout << i << ' '; 
	}
	else cout << "NO" << endl;
}