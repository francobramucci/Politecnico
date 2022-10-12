#include <bits/stdc++.h>

using namespace std;

const int MAX = 200000+100;

int main(){
	int n; cin >> n;
	vector<int> a;
	a.resize(MAX);

	for(int i=0; i<n-1; i++){
		int v; cin >> v; 
		a[i] = v;
	}

	sort(a.begin(), a.begin()+n-1);

	for(int i=1; i<=n; i++){
		if(i != a[i-1]){cout << i << '\n'; break;}
	}
}