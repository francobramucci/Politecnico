#include <iostream>
using namespace std;

int memo[10000];

int fibonacci(int N){
	if(N == 0){return 0;}
	if(N == 1){return 1;}
	if(memo[N] != 0) return memo[N];
	else{
	
	return memo[N] = fibonacci(N-1) + fibonacci(N-2);
	}

}

int main(){
int n; cin >> n;
cout << fibonacci(n);

return 0;
}