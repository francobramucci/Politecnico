#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

int main(){
	int n; cin >> n;
	int sum = 0;
	for(int i = 5; n/i > 0; i*=5){
		sum += n/i;
	}
	cout << sum << endl;
}