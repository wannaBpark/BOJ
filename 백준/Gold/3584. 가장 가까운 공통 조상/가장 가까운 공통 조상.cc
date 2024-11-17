#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> v[10010];
int depth[10002];
int par[10002];
int T, N,A,B,root;
int p, child;
void dfs(int cur, int height) {
    depth[cur] = height;
    for(auto& nxt : v[cur]) {
        dfs(nxt, height +1);
    }
}
int LCA(int a, int b) {
    if (depth[a]<depth[b]) swap(a,b);
    while(depth[a] > depth[b]) {
        a=par[a];
    }
    while(a != b) {
        a = par[a]; b = par[b];
    }
    return a;
}
void solve() {
    cin >> T;
    while (T--) {
        cin >> N;
        memset(depth, 0, N+1); 
        memset(par, 0, N+1); 
        
        for(int i=1; i<=N; ++i) v[i].clear();
        for (int i =0; i<N-1; ++i) {
            cin >> p >> child;
            v[p].push_back(child); 
            par[child] = p;
        }
        cin >> A >> B;
        for (int i =1; i<=N; ++i) {
            if (!par[i]) {root = i; break;}
        }
        par[root] = root;
        dfs(root, 0);
        cout << LCA(A, B) << '\n';
    }
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    solve();
    return 0;
}