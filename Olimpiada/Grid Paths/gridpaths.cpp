#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
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

const int MOD = 1e9+7;
const int MAX = 1000+100;

int n;
char grid[MAX][MAX];
int dp[MAX][MAX];

int solve(int x, int y){
	if(x >= n || y >= n) return 0;
	if(grid[x][y] == '*') return 0;
	if(dp[x][y] != -1) return dp[x][y];
	if(x == n-1 && y == n-1) return 1;
	return dp[x][y] = (solve(x+1,y) + solve(x,y+1))%MOD;
}

int main(){
	fastio;
	cin >> n;

	memset(dp, -1, sizeof(dp));

	forn(i,n){
		forn(j,n) cin >> grid[i][j];		
	}
	cout << solve(0,0) << endl;
}