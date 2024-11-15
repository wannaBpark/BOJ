#include <bits/stdc++.h>
#define INF 1e9
#define MXN 100010
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
vector<int> tree[1000'010];
int D[1000'010][2]={0,};
int visited[1000'010]={0,};
int N;
int ans = 1e9;
void dp(int cur) {
    // cout << cur << '\n';
    visited[cur] = true;
    D[cur][0] = 1;
    for (auto& child : tree[cur]) {
        if (visited[child]) continue;
        dp(child);
        D[cur][1] += D[child][0];
        D[cur][0] += min(D[child][1], D[child][0]);
    }
    
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i<N-1; ++i) {
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dp(1);
    ans = min(D[1][0],D[1][1]);
    cout << ans << '\n';
    return 0;
}