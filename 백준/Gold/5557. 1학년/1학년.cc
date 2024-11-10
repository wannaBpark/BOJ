#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans = 0;
int diff[2] = {1,-1};
int A[110];
int N,T,M;
ll D[110][21]={0,};
// int visited[110][21]={0,};
// idx까지 더했을 때, cur값을 만드는 경우의 수 (0일수도 있으므로 visited 따로 선언 or -1로 방문 표시)
ll dp(int idx, int cur) {
    if (idx == N-1) {
        return (cur == A[N]) ? 1 : 0;
    }
    ll& ret = D[idx][cur];
    if (D[idx][cur] != -1) return ret;
    ret = 0;
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
    memset(D, -1, sizeof(D));
    cin >> N;
    for (int i =1; i<=N; ++i) cin >> A[i];
    // dp(0,0)으로 시작했다가 틀림
    // 이유 : idx=1일 때 무조건 A[1]을 더해야 함
    // 0,0으로 시작해버리면 dp(1,A[1]) + dp(1, -A[1])의 틀린 식이 계산됨
    // 문제에서 첫번째 수 이후부터 +,-붙이므로 dp(1,-A[1])는 틀린 정의
    cout << dp(1, A[1]);
    return 0;
}