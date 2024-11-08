#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int D[10010][510];
int A[10010];
int N,M;
int dp(int cur, int vel) {
    if (A[cur] || cur > N) return -1;
    if (cur == N) return 0;
    int& ret = D[cur][vel];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int i =vel+1; i>=vel-1; --i) {
        int nxt = cur + i;
        if (nxt<=cur || A[cur]) continue;
        
        int result = dp(nxt, i);
        if (result == -1) continue;
        ret = min(ret, result + 1); 
    }
    if (ret == INF) return ret = -1;
    return ret;
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >>N >> M;
    memset(D, -1, sizeof(D));
    for (int i = 0; i <M; ++i) {
        int small;
        cin >> small;
        A[small] = true;
    }
    int ans = dp(2,1);
    if (ans == -1) --ans;
    cout << ans+1;
    // for (int i =1; i<=N; ++i) {
    //     cout << D[i] << " ";
    // }
    // cout << '\n';
    return 0;
}