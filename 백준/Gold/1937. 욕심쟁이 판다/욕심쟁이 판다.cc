#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int ret, ans=0;
int B[510][510]; // Bamboo
int D[510][510];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N;
static inline int isRange(int i, int j) {
    return (i>=0 &&i<N && j>=0 && j<N);
}
int dp(int i, int j) 
{
    int& ret = D[i][j];
    if (ret != -1) return ret;
    ret = 1;
    for (int k = 0; k<4; ++k) {
        int nx = dx[k] + i, ny = dy[k] + j;
        if (!isRange(nx, ny) || !(B[i][j] > B[nx][ny])) continue;
        ret = max(ret, dp(nx, ny) + 1);
    }
    return ret;
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    for (int i =0; i<N; ++i) for (int j = 0; j<N; ++j) cin >> B[i][j], D[i][j] = -1;
    for (int i = 0; i<N; ++i) {
        for (int j =0; j<N; ++j) {
            ret = dp(i,j);
            ans = max(ans, ret);
        }
    }
    cout << ans;
    return 0;
}