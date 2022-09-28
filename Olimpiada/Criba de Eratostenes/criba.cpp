#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
#define MAX 2000000000 + 100

int main(){
	unsigned t0, t1;	

	int n, cont = 0;
	vector<bool> c(MAX+1, 0);
	cout << "Ingrese n: ";
	cin >> n;

	c[0] = c[1]= 1; 
	
	t0 = clock();

	for(int i=2; i <= n; i++){
		if(c[i] == 0){
			for(int j = i*2; j <= n; j+=i){
				c[j] = true;
			}
			cout << i << "\n";
			cont++;
		}
	}
	
	t1 = clock();
	double time = double(t1-t0)/CLOCKS_PER_SEC;
	
	cout << "Cantidad de numeros primos hasta " << n <<": " << cont << "\n";
	cout << "Tiempo de ejecución: " << time << "\n"; 

	return 0;
}