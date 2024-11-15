#include <bits/stdc++.h>
#define INF 1e9
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

queue<int> q;
vector<int> ans;
int p[100010];
int D[100010];
int dx[3] = {0,0,2};
int dy[3] = {-1,1,0};
int N, K;

void solve()
{
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        // cout << "cur: " << cur << '\n';
        if (cur == K) return;
        int x[3] = {cur*2, cur-1, cur+1};
        for (int i =0; i<3; ++i) {
            int nxt = x[i];
            
            if (!(nxt >= 0 && nxt<=100000)) continue;
            if (D[nxt] < D[cur] + 1) continue;
            // cout <<"nxt: "<< nxt << '\n';
            D[nxt] = D[cur] + 1;
            p[nxt] = cur;
            q.push(nxt);
            
        }
    }
}
void print()
{
    int cur = K;
    while(p[cur] != cur) {
        ans.push_back(cur);
        cur = p[cur];
    }
    ans.push_back(N);
    reverse(all(ans));
    cout << ans.size()-1 << '\n';
    for (auto& a : ans) cout << a << " ";
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N >> K;
    for (int i =0; i<100001; ++i) D[i] = INF;
    D[N] = 0; p[N] = N;
    q.push(N);
    solve();
    print();
    return 0;
}