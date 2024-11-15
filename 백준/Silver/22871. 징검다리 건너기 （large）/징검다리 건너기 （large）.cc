#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using ll = long long;
ll D[5004];
ll A[5004];
int N;
// D[cur] = 1번째 돌에서 건널때 cur로 올수 있는 K의 최솟값
ll dp(int cur) {
    ll& ret = D[cur];
    if (ret!=INF) return ret;
    for (int nxt = cur-1; nxt >= 1; --nxt) {
        ll power = (cur - nxt) * (1 + abs(A[cur] - A[nxt]));
        ll result = max(power,dp(nxt));
        ret = min(ret,  result);
    }    
    return ret;
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    for (int i =1; i<=N; ++i) cin >> A[i], D[i] = INF;
    D[1] = 0;
    cout << dp(N);
    return 0;
}