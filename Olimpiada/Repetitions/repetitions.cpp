#include <bits/stdc++.h>

using namespace std;

int main(){
	string a;
	cin >> a;

	int cont = 1;
	int mayor = 1;
	for(int i=1; i<int(a.size()); i++){
		if(a[i] == a[i-1]){
			cont++;
		}
		else{
			cont = 1;
		}
		mayor = max(mayor, cont);
	}

	cout << mayor << '\n';
}