#include <bits/stdc++.h>

using namespace std;

#define ioshack ios_base::sync_with_stdio(false);cin.tie(NULL);
#define forr(i,a,b) for(int i = (a); i < int(b); ++i)
#define forn(i,n) forr(i,0,n)
#define sz(v) int(v.size())
#define endl '\n'
#define fi first
#define se second
#define pb push_back
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

vector<int> twoSum(vector<int>& nums, int target){
	vector<int> slv(2);
	map<int, int> cop;

	forn(i, nums.size()){ cop[target-nums[i]] = i;}

	forn(i, nums.size()){
		int key = cop[nums[i]];
		if(nums[i] + nums[key] == target && i != key){
			slv[0] = i;
			slv[1] = cop[nums[i]];
			return slv;
		} 
	}
	return slv;
}



int main(){
	int n; cin >> n;
	vector<int> nums;

	forn(i,n){ int v; cin >> v; nums.pb(v); };

	int target; cin >> target;

	vector<int> h = twoSum(nums, target);
	cout << h[0] << ' ' << h[1] << endl;
}