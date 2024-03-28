#include <bits/stdc++.h>
#define fastio cin.tie(NULL)->sync_with_stdio(false)
using namespace std;
using ll = long long;
vector<ll> v;
int N;
ll dp[3010][3010];
ll ans = 0;
int main()
{
    fastio;
    cin >> N;
    for (int i =0; i< N; ++i){
        ll a; cin >> a; v.push_back(a);
    }
    if (!(N & 1)) v.push_back(0);
    int sz = v.size();
    dp[3][0] = v[1]*v[2]; dp[3][1] = v[0]*v[2]; dp[3][2] = v[0]*v[1];
    for (int cur = 5; cur <= sz; cur += 2) {
        for (int t =0; t <= cur - 3; ++t){
            dp[cur][t] = max(dp[cur][t], dp[cur-2][t] + v[cur - 1] * v[cur -2]);
            dp[cur][cur - 2] = max(dp[cur][cur - 2], dp[cur-2][t] + v[t] * v[cur - 1]);
            dp[cur][cur - 1] = max(dp[cur][cur - 1], dp[cur-2][t] + v[t] * v[cur - 2]); 
        }
    }
    for (int i = 0; i <= sz; ++i) ans = max(ans, dp[sz][i]);
    cout << ans;
    return 0;
}