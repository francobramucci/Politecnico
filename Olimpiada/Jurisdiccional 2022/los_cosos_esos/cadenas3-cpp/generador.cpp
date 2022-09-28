#include <iostream>
#include <random>

using namespace std;

int main(){
	freopen("entrada.in", "w", stdout);
	srand(time(NULL));
	int n = 10;
	cout << n << "\n";
	for(int i=0; i<n; i++){
		cout << rand()%20000000 << " ";
	} 

	fclose(stdout);
}