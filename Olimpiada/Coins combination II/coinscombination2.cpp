#include <iostream>

using namespace std;
using ll = long long int;

const int MAXN = 1000015; 
const ll mod = 1e9 + 7;

ll x;
int n;
ll c[MAXN];

int solve(int x, int j){
	if(x < 0) return 0;
	if(x == 0) return 1;

	return solve(x-c[j], j+1) + solve(x-c[j], j); 
}

int main(){
	cin >> n; 
	cin >> x;

	for(int i=0; i < n; i++){
		cin >> c[i];
	}

	cout << solve(x, 0);
}