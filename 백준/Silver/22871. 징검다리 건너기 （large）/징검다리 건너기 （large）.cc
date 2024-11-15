#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using ll = long long;

ll A[5010];
int N;
ll D[5010];
ll dp(int cur) {
    auto& ret = D[cur];
    if (ret!=INF) return ret;

    for (int nxt = cur-1; nxt >= 1; --nxt) {
        auto power = (cur - nxt) * (1 + abs(A[cur] - A[nxt]));
        ll result = max(power,dp(nxt));
        // cout << "cur and nxt : " << cur << " " << nxt << " pow : " << power << " result : " << result <<'\n';
        ret = min(ret,  result);
    }    
    return ret;
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    for (int i =1; i<=N; ++i) {
        cin >> A[i]; D[i] = INF;
    }
    D[1] = 0;
    cout << dp(N) <<'\n';
    // for (int i =1; i<=N; ++i) {
    //     cout << D[i] << " ";
    // }
    return 0;
}