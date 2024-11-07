#include <bits/stdc++.h>
using namespace std;
vector<int> color;
vector<int> visited;
vector<int> v[200010];
int N;
int ans = 0;
void dfs(int prev, int cur) {
    if (visited[cur] == true) return;
    ans += (color[prev] != color[cur]) ? 1 : 0;
    visited[cur] = true;
    for (auto& nxt : v[cur]) {
        if (visited[nxt]) continue;
        dfs(cur, nxt);
    }
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    color.resize(N+1);
    visited.resize(N+1);
    for (int i =1; i<=N; ++i) {
        int c; cin >> c;
        color[i] = c;
    }
    for (int i=1; i<N; ++i) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,1);
    ans += color[1]!=0 ? 1:0;
    cout << ans;
    return 0;

}