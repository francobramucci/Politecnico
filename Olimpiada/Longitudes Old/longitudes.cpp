#include <vector>
#include <string>

using namespace std;

vector<int> dameLongitudes(vector<string> v)
{
    vector<int> longitudes(v.size());

    for(int i=0; i < v.size(); i++){
        longitudes[i] = v[i].size();
    }

    return longitudes;
}
