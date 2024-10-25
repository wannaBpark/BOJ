#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MX 1000000000;

struct info {
    int from, to, cost;
};
struct Edge {
    int to, cost;
};
struct cmp{
bool operator()(Edge e1, Edge e2) {
    return e1.cost > e2.cost;
}
};

priority_queue<Edge, vector<Edge>, cmp> pq;
vector<Edge> v[20009];
ll costs[20010];
int V,E,K;

void solve()
{
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        auto& from = cur.to;
        for (int i = 0; i < v[from].size(); ++i) {
            auto& to = v[from][i].to;
            auto& toCost = v[from][i].cost;
            if (costs[to] > costs[from] + toCost) {
                costs[to] = costs[from] + toCost;
                Edge e = {to, (int)costs[to]};
                pq.push(e);

                // cout << "from to cost  " << from <<" " <<to << " " <<costs[to] << '\n';
            }
        }
    }
}
void print();
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> V >> E;
    cin >> K;
    for (int i =0; i<E; ++i) {
        int u,j,w;
        cin >> u >> j >> w;
        Edge e1 = {j,w};
        v[u].push_back(e1);
    }
    for (int i =1; i<=V; ++i) costs[i] = MX;
    costs[K] = 0;
    for (int i = 0; i < v[K].size(); ++i) {
        int& to = v[K][i].to; int& toCost = v[K][i].cost;
        if (costs[to] > toCost) {
            costs[to] = toCost;
            pq.push({to, (int)costs[to]});

            // cout << "to cost from " << to << " " <<costs[to] <<" "<< K << '\n';
        }
    }    
    solve();

    print();
    
    return 0;
}

void print() {
    for (int i = 1; i <= V; ++i) {
        if (costs[i] == 1000000000 ) { 
            cout << "INF" << '\n';
        }
        else cout << costs[i] << '\n';
    }
}