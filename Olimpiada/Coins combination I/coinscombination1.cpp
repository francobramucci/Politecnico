#include <iostream>
#include <string.h>

using namespace std;
using ll = long long int;

const ll mod = 1e9+7;
const int MAXN = 1000005; 
ll x;
int n;
ll valores[105];
ll memo[MAXN];
 
int solve(int x){
	if(x == 0) return 1;
	if(x < 0) return 0; 
	if(memo[x] != -1) return memo[x];
	
	ll sum = 0; 
 
	for(int i=0; i<n; i++){
		sum = sum + solve(x - valores[i]);
	}
 
	return memo[x] = sum % mod;
}
 
int main(){
	cin >> n;
	cin >> x;
 	
 	memset(memo, -1, sizeof(memo));

	for(int i=0; i<n; i++){
		ll c; cin >> c;
		valores[i] = c;
	}
 
	cout << solve(x);
}