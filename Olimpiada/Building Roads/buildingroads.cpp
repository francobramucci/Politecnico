#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define MAX 100000 + 100

int n,m;

vector<int> grafo[MAX];
bool visitado[MAX];
int isla[MAX];


void DFS(int s){
	stack<int> b;
	visitado[s] = true; b.push(s);

	while(!b.empty()){
		int u = b.top(); b.pop();

		for(int v: grafo[u]){ 					// Itera por los elementos guardados en el vector
			if(visitado[v]) continue;
			visitado[v] = true; b.push(v);
		}
	}

}


int main(){
	cin >> n >> m;
	int cant = 0;

	for(int i=1; i<=m; i++){
		int v, u; cin >> v >> u;

		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}

	for(int i=1; i<=n; i++){
		if(visitado[i]) continue;
		DFS(i);
		isla[cant] = i;
		cant++;
	}

	cout << cant-1 << "\n"; //Cantidad de aristas necesarias

	for(int i=0; i<cant-1; i++){
		cout << isla[i] << ' ' << isla[i+1] << endl;  //Cuales son las aristas
	}

}