#include <iostream>
#include <algorithm>

using namespace std;
#define forn(i,a,n) for(int i=a; i < n; i++)
#define MAX 200100
#define ll long long

int main(){
	int N; cin >> N;
	int K; cin >> K;
	int a[MAX];

	int mayor = 0;
	int menor = 2147483647;

	forn(i,0,N){
		cin >> a[i];
		mayor = max(mayor, a[i]);
		menor = min(menor, a[i]);
	}

	if(K >= mayor){
		cout << K - menor << "\n";
	}
	else if(K <= menor){
		cout << mayor - K << "\n";
	}
	else{
		cout << mayor-menor << "\n";
	}
}