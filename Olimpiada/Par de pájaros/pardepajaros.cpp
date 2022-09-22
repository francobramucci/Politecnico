#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int INF = 300*60000*10;
const int MAXX = 60000 + 100;
const int MAXY = 300 + 100;

int a[MAXX];
int i;
int memo[MAXY][MAXX];

int solve(int x, int y){
	
	if(x > 300) return INF;
	if(x < 0) return INF;
	if(y > i) return 0;
	if(memo[x][y] != 0) return memo[x][y];

	return memo[x][y] = min(solve(x+1, y+1), solve(x-1, y+1)) + abs(x-a[y]);

}

int main(){
	freopen("pajaros.in", "r", stdin);
	freopen("pajaros.out", "w", stdout);

	cin >> i;

	a[0] = 0;
	for(int k = 1; k <= i; k++){
		cin >> a[k];
	}

	cout << solve(0, 0) << "\n";
}