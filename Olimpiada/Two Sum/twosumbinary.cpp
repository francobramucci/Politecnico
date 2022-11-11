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

void twoSum(vector<int>& nums, int target) {
	vector<int> cop; cop = nums;
	sort(cop.begin(), cop.end());
	
	int pos;
	vector<int>::iterator low1;

	if(cop[nums.size()] < target){ low1 = cop.end(); pos = nums.size();} 
	else{ 
		low1 = lower_bound(cop.begin(), cop.end(), target);
		pos = distance(cop.begin(), low1);
	}
	int ban=0;
	while(ban!=1){
		int nt = target-nums[pos];
		vi::iterator low2 = lower_bound(cop.begin(), low1, nt);
		int pos2 = distance(cop.begin(), low2);
		if(nums[pos2] == nt){
			cout << pos2 << ' ' << pos << endl;
			ban = 1;
		} 
		advance(low1, -1);
		pos--;
	}
	cout << "IMPOSSIBLE" << endl;
}

int main(){
	int n; cin >> n;
	vector<int> nums;

	forn(i,n){ int v; cin >> v; nums.pb(v); };

	int target; cin >> target;

	twoSum(nums, target);
	

}