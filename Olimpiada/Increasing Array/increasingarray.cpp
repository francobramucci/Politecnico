#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,dif;cin>>n;
	int a[200100];
	long long sum=0; 
	
	cin >> a[0];
	for(int i=1; i<n; i++){
		cin >> a[i];
		if(a[i] < a[i-1]){dif = a[i-1]-a[i];a[i] += dif; sum += dif;} 
	}
	cout << sum << '\n';
}