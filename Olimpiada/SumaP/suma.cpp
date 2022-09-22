#include <vector>

using namespace std;
#define ll long long

long long suma(vector<int> v)
{  
   ll sumador = 0;
   for(int i=0; i < v.size(); i++){
      sumador = sumador + v[i];
   }

   return sumador;
}
