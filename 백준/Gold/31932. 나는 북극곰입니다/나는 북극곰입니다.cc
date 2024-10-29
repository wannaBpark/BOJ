#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
struct Edge {
    int to, d, t;
};
struct info {
    int cur, time;
};
struct cmp {
    bool operator()(info& e1, info& e2) {
        return e1.time >e2.time;
    }
};

int ans = -1;
int dist[100010]={0,};
vector<Edge> v[100010];
void solve();
void input();
int reachable(int start);

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    input();
    solve();    
    // cout << "reachable : " << reachable(0)<<'\n';
    cout << ans;
    return 0;
}

int reachable(int start)
{
    for (int i = 1; i<=N; ++i) {
        dist[i] = 2e9;
    }
    // 해당 노드로 갈 때에 시간을 가장 단축하는 것이 이득
    // 간선 M을 건너는데 필요한 시간은 현재시간 + 거리 = k + d
    // k+d <= t를 만족하면서 그 차가 작은 것을 우선적으로 탐색해보자
    priority_queue<info, vector<info>, cmp> pq;
    pq.push({1,start});
    
    while (!pq.empty()) {
        auto i = pq.top(); pq.pop();
        int& cur = i.cur;
        int& k = i.time;
        if (dist[cur] < 2e9) continue;
        dist[cur] = k;
        // cout << "cur time : " << cur << " " << k << '\n';
        for (auto& e : v[cur]) {
            int& cost = e.d;
            int& nxt = e.to;
            int& t = e.t;
            if (k+cost <= t) {
                if (nxt == N) return true;
                // cout << "to time : " << e.to << " " << k+e.d <<'\n';
                pq.push({nxt, k+cost});
            }        
        }
    }
    return false;
}
void solve()
{
    int s = 0, e = 1e9;
    while (s<=e) {
        int mid = (s+e)/ 2;
        int ret = reachable(mid);
        if (ret == true) {
            ans = max(mid, ans);
            s = mid+1;
        } else {
            e = mid-1;
        }
    }
}

void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u,to,d,t;
        cin >> u >> to >> d >> t;
        v[u].push_back({to,d,t});
        v[to].push_back({u,d,t});
    }
    
}