#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//const int MAXN = 9999;

int memo[100000+100];

int solve(int n){
	if(n == 0) return 1;
	if(n < 0) return 0;
	if(memo[n] != 0) return memo[n];

	return memo[n] = solve(n-1)+solve(n-2)+solve(n-3)+solve(n-4)+solve(n-5)+solve(n-6); 
}

	

int main(){
	int n; cin >> n;
	cout << solve(n) << '\n';
}