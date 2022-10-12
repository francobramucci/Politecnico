#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000+100;
using ll = long long;

int casobase(int x, int y){
	if(x == 1 && y == 1) return 1;
	if(x == 1 && y == 2) return 2;
	if(x == 2 && y == 1) return 4;
	if(x == 2 && y == 2) return 3;
}
int main(){
	int t; cin >> t;
	ll a[MAX];
	ll result;

	for(int i=0; i < t; i++){
		ll x,y; cin >> x >> y;
		if(x<=2 && y<=2){a[i] = casobase(int(x),int(y));continue;} 
		
		if(x>=y){
			if(x%2==0) result = x*x -(y-1); // Si es par
			else result = (x-1)*(x-1)+y;	// Si es impar
			a[i] = result;
		}
		else{
			if(y%2==0) result = (y-1)*(y-1)+x;
			else result = y*y -(x-1);
			a[i] = result;
		}
	}

	for(int i=0; i<t; i++){
		cout << a[i] << '\n';
	}

}