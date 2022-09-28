#include <string>
#include <vector>

using namespace std;

vector<int> cadenas(vector<int> &a) {
    vector<int> result;
    
    result.resize(a.size());

    for(int i=0; i < a.size(); i++){
        result[i] = a[i];
        for(int j=2; j * j <= a[i]; j++){
            while(a[i] % j == 0){
                a[i] = a[i]/j;
                result[i] = result[i] + a[i];
            }    
        }
        if(a[i] > 1) result[i] += 1;
    }

    
    return result;
}
