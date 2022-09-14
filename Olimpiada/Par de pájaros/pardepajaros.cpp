#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>

using namespace std;
const int INF = 300*60000;
const int MAX = 305;
using ll = long long int;

int a[60000];
int i;
ll memo[MAX][MAX];

ll solve(int x, int y){
	
	if(x > 300) return INF;
	if(x < 0) return INF;
	if(y > i) return 0;
	if(memo[x][y] != 0) return memo[x][y];

	return memo[x][y] = min(solve(x+1, y+1), solve(x-1, y+1)) + abs(x-a[y]);

}

int main(){
	freopen("pajaros.in", "r", stdin);
	cin >> i;

	a[0] = 0;
	for(int k = 1; k <= i; k++){
		cin >> a[k];
	}

	cout << solve(0, 0);
	fclose(stdin);
}