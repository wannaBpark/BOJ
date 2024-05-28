#include <bits/stdc++.h>
using namespace std;
#define MIN -1e9
int N,M, K;
int W[1010];
int L[1010];
int dp[1010][1010];
// dp[i][j] = i번 이기고, j번 졌을때 최댓값
static inline int visitable(int i, int j) {
    if (i<0 || j <0) return false;
    if (i>N || j > M) return false;
    return true;
}
void solve(int i, int j)
{
    if (i == 0 && j == 0) return;
    int dpi=-1e9, dpj = -1e9;
    if (visitable(i-1,j)) {
        dpi = dp[i-1][j];
    } if (visitable(i, j-1)) {
        dpj = dp[i][j-1];
    }
    if (dpj % K == 0) {
        dp[i][j] = max(dpi + W[i], dpj - L[j]);
    } else {
        int namu = (dpj>=0) ? dpj%K : K-abs(dpj%K);
        dp[i][j] = max(dpi + W[i], dpj - 
                        min(L[j], namu));
    }
}
int main ()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);
    cin >> N;
    for (int i= 1; i<= N; ++i) cin >> W[i];
    cin >> M;
    for (int i= 1; i<= M; ++i) cin >> L[i];
    cin >> K;
    dp[0][0] = 0;
    for (int i =0; i<=N; ++i) {
        for (int j =0; j <=M; ++j) {
            solve(i,j);
        }
    }
    cout << dp[N][M];
    return 0;
}
