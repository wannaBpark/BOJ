#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

int mxcost[510]={0,};
int build[510];
int in[510]={0,};
int N;
vector<int> edge[510];
queue<int> q;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i<=N; ++i) {
        int prev;
        cin >> build[i]; mxcost[i] = build[i];
        while ( (cin >> prev) && prev != -1) {
            // cout << prev << " " << i << '\n';
            edge[prev].push_back(i);
            ++in[i];
        }
    }
    for (int i = 1; i<=N; ++i) {
        if (!in[i]) q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto& nxt : edge[cur]) {
            mxcost[nxt] = max(mxcost[nxt], build[nxt] + mxcost[cur]);
            if (--in[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    for (int i = 1; i<=N; ++i) {
        cout << mxcost[i]<<'\n';
    }
    return 0;
}