#include <vector>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

void duplilong(vector<string> &palabras, int K, vector<int> & longitudes)
{
    
    for(int i=0; i < K; i++){
        longitudes[i] = (int)palabras[i].size();
    }
    
    for(int i = palabras.size() - 1; K > 0; i--,K--){
        palabras[i] = palabras[i] + palabras[i];
    }
}
