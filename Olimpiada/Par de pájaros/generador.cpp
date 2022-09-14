#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;


int main(){

	freopen("pajaros.in", "w", stdout);
	
	srand((unsigned)time(NULL));
	int cont = 40000;
	cout << cont << endl;
	
	for(int i=0, n, sum=0; i < cont; i++){
		n = rand()%2;
		if(sum >= 3 && sum <= 297){
			if(n == 0) sum = sum + 3;
			if(n == 1) sum = sum - 3;
			if(n == 2) sum = sum;
		}
		else{
			if(sum < 3) sum = sum + 3;
			if(sum > 297) sum = sum -3;
		}

		cout << sum << endl;
	}
	fclose(stdout);

	return 0;
}
