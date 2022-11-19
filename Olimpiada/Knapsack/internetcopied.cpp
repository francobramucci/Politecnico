#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000005
#define O 1000000007
#define vi vector<int>
#define vl vector<long>
#define vb vector<bool>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long, long>
#define fo(i, N) for (long i = 0; i < N; ++i)
#define fos(i, b, N) for (long i = b; i < N; ++i)
#define forr(i, N) for (long i = N; i >= 0; --i)
const double PI = 3.141592653589793238;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

int main()
{
    fast;
    ll n, x;
    cin >> n >> x;
    vll h(n), s(n);
    fo(i, n) cin >> h[i];
    fo(i, n) cin >> s[i];
    ll dp[x + 1];

    memset(dp, 0, sizeof(dp));
    
    for(long i = 1; i <= n; ++i)
    {
        for(long j = x; j > 0; --j)
            if(j - h[i - 1] >= 0)
                dp[j] = max(dp[j], s[i - 1] + dp[j - h[i - 1]]);
    }

    cout << dp[x];
    return 0;
}