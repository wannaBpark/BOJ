#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> v[3010];
int dist[3010]={0,};
int cycle[3010]={0,};
int visited[3010]={0,};
int N;
int start;
void bfs(int start)
{
    queue<pair<int,int>> q;
    int visited[3010]={0,};
    q.push({start,0});
    while(!q.empty()) {
        auto top = q.front(); q.pop();
        auto& cur = top.first; 
        auto& cost = top.second;

        for (auto& nxt : v[cur]) {
            if (cycle[nxt] || visited[nxt]) continue;
            dist[nxt] = cost+1;
            q.push({nxt, dist[nxt]});
            visited[nxt] = true;
        } 
    }
}
void dfs(int cur, int prev)
{
    int ret = false;
    visited[cur] = true;
    for (auto& nxt : v[cur]) {
        if (nxt == start && prev != nxt) {
            cycle[start] = true;
        } else if (!visited[nxt] && prev != nxt) {
            dfs(nxt, cur);
        }
    }
    visited[cur] = false;
}
void solve()
{
    for (int i =1; i<=N; ++i) {
        if (!cycle[i]) {
            start = i;
            dfs(i, i);
        }
    }
    for (int i = 1; i <= N; ++i) {
        if(cycle[i]) bfs(i);
    }
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    for (int i =0;i<N; ++i) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    solve();
    for (int i = 1; i <=N; ++i) {
        cout << dist[i] << " ";
    }
    return 0;
}