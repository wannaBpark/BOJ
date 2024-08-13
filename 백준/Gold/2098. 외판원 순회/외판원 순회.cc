#include <bits/stdc++.h>
#define VISITED(to, cur) ((to) & (cur))
#define NXTCUR(to, cur) ((to) | (cur))
#define INF 1e9
using namespace std;
using ll = long long;

int dp[16][1<<17];
int W[20][20];
int complete;
int N;
int ans = INF;
int solve(int start, int prev, int cur)
{
    // cout << start << " " << prev << " " << cur << '\n';
    
    if (cur == complete) {
        if (W[prev][0] == 0) {
            return INF;
        }
        return W[prev][0];
    }
    if (dp[prev][cur] != 0)
        return dp[prev][cur];
    int res = INF;
    for (int i = 0; i < N; ++i) {
        int to = 1 << i;
        if (W[prev][i] == 0 || VISITED(to, cur)) continue;
        
        int nxt = NXTCUR(to, cur);
        int& cost = W[prev][i];
        
        res = min(res, cost + solve(start, i, nxt));
    }
    return dp[prev][cur] = res;
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    complete = (1 << (N)) - 1;
    // cout << complete<<'\n';
    for (int i=0; i<N; ++i) {
        for (int j =0; j <N; ++j) {
            cin >> W[i][j];
        }
    }
    ans = solve(0, 0, 1);
    cout << ans;
    return 0;
}