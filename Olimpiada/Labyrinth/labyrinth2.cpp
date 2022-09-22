#include <iostream>

using namespace std;

#define forn(i,a,n) for(int i=a; i<n; i++)

int n,m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	forn(i,0,n){
		forn(j,0,m){
			cin >> matriz[i][j];
		}
	}
	

}