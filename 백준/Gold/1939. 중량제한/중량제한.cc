#include <bits/stdc++.h>
#define MXC 1000000000
using namespace std;
using ll = long long;
using pii = pair<int, int>;
vector<pii> v[10010];
int N,M;
int A,B;
int ans = 0;
// returns if B is reachable when edge weight is always >= w
int reachable(int w) {
    priority_queue<pii> pq;
    int dist[10010] = {0,};
    pq.push({MXC, A});
    dist[A] = 0;
    while (!pq.empty()) {
        auto info = pq.top(); pq.pop();
        auto& cur = info.second; auto& curw = dist[cur];
        if (cur == B) {            
            return true;
        }
        for (auto& p : v[cur]) {
            auto& nxt = p.first; auto& nw = p.second;
            int mnw = (dist[cur] == 0) ? nw : min(dist[cur],nw);
            if(dist[nxt] != 0 && dist[nxt] > mnw) continue;
            if (mnw >= w && dist[nxt] < mnw) {
                dist[nxt] = mnw;
                pq.push({mnw, nxt});
            }
        }
    }
    
    return false;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i<M; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        v[from].push_back({to, weight});
        v[to].push_back({from, weight});
    }
    cin >> A >> B;

    int l = 1, r =MXC;
    while (l<=r) {
        int mid = (l+r) /2;
        int ret = reachable(mid);

        if (ret == true) {
            ans = max(mid, ans);
            l = mid +1;
        } else {
            r = mid-1;
        }
        // cout << mid << " result: " << ret <<'\n';
    }
    cout << ans;
    return 0;
}