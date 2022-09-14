#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//const int MAXN = 9999;

int memo[1000];

int solve(int n){
	if(n == 0) return 1;
	if(n == 1) return 1;
	if(memo[n] != 0) return memo[n];

	return memo[n] = solve(n-1) + 1; 

}

	

int main(){
	int n; cin >> n;

	cout << solve(n);


}