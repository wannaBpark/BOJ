#include <bits/stdc++.h>
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define x first
#define y second
using namespace std;

using ll = long long;
using ld = long double;
using Point = pair<ll, ll>;

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

    // dp[현재 인덱스][남긴 인덱스]
    for (int cur = 5; cur <= sz; cur += 2) {
        int x = sz - cur;
        // 조합은 3가지
        // v[남은 인덱스] * + v[cur -1]번지
        // v[남은 인덱스] * + v[cur -2]번지
        // 남긴 것 그대로 두고, 새로운 것끼리 곱하기 v[cur - 1] * + v[cur - 2]번지
        for (int t =0; t <= cur - 3; ++t){
            dp[cur][t] = max(dp[cur][t], dp[cur-2][t] + v[cur - 1] * v[cur -2]);

            dp[cur][cur - 2] = max(dp[cur][cur - 2], dp[cur-2][t] + v[t] * v[cur - 1]);
            
            // 남은 인덱스가 N일 때..
            dp[cur][cur - 1] = max(dp[cur][cur - 1], dp[cur-2][t] + v[t] * v[cur - 2]); 
        }

    }

    // for (int cur = 3; cur <= sz; cur += 2) {
    //     for (int t =0; t <= cur; ++t){
    //         cout << dp[cur][t] << " ";
    //     }
    //     cout <<endl<<"---------------------------"<<endl;
    // }

    for (int i = 0; i <= sz; ++i) {
        ans = max(ans, dp[sz][i]);
    }
    // cout << "Answer : "<< endl;
    cout << ans << endl;
    return 0;
}