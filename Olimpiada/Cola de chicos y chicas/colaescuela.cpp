#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n; cin >> n;
	int t; cin >> t;
	char boygirl;
	vector<char> queue;

	for(int i = 0; i < n; i++){
		cin >> boygirl;
		queue.push_back(boygirl);
	}
	

	for(int j = 0; j < t; j++){
		vector<char> copyqueue = queue;

		for(int z = 0; z < n; z++){
			if(copyqueue[z] == 'B' && copyqueue[z+1] == 'G'){
				queue[z] = 'G';
				queue[z+1] = 'B';
			}
		}
	}

	for(int k = 0; k < n; k++){
		cout << queue[k];
	}
}