#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans = 0;
int diff[2] = {1,-1};
int A[110];
int N,T,M;
ll D[110][21]={0,};
int visited[110][21]={0,};
// idx까지 더했을 때, cur값을 만드는 경우의 수
ll dp(int idx, int cur) {
    if (idx == N-1) {
        return (cur == A[N]) ? 1 : 0;
    }
    ll& ret = D[idx][cur];
    if (visited[idx][cur]) return ret;
    visited[idx][cur] = true;
    for (int i = 0; i<2; ++i) {
        int nxt = cur + A[idx + 1]*diff[i];
        if (!(nxt>=0 && nxt<=20)) continue;
        ret += dp(idx + 1, nxt);
    }
    return ret;
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    memset(D, 0, sizeof(D));
    cin >> N;
    for (int i =1; i<=N; ++i) {
        cin >> A[i];
    }
    ans = dp(1, A[1]);
    cout << ans;
    return 0;
}