#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii=pair<int,int>;
const int INF = 1e9;

vector<int> v;
vector<priority_queue<int,vector<int>, greater<int>>> advent;
priority_queue<pii> plug;
// 각 전기용품의 출현시기 저장, 출현시기가 가장 늦은 것들을 unplug시키고 새로운 걸 꽂음
int used[500010]={0,};
int visited[500010]={0,};
int N,K,a;
int ans= 0;
static inline int findMostFar() {
    auto p = plug.top(); 
    plug.pop();
    // while (p.first != INF && visited[p.first]) {
    //     plug.pop();
    //     p = plug.top();
    // }
    return p.second;
}
void solve()
{
    int sz = 0;
    for (int i =0; i<K; ++i) {
        int& cur = v[i];
        int unplug;
        // cout << cur << '\n';
        if (sz < N && !used[cur]) {
            ++sz;
        } else if (sz == N && !used[cur]) {
            ++ans;
            // cout << "pq top : " << plug.top().first << " " << plug.top().second << '\n';
            unplug = findMostFar();
            used[unplug] = false;
            // cout << "unplug: "<< unplug << " "<< i <<'\n';
        }
        auto& pq = advent[cur];
        if(!pq.empty()) pq.pop();
        int nxt = (pq.empty()) ? INF : pq.top();
        plug.push({nxt,cur});
        used[cur] = true;
    }
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N >> K;
    advent.resize(K+1);
    for (int i = 0; i < K; ++i) {
        cin >> a; 
        v.push_back(a);
        advent[a].push(i);
        //  cout << advent[a].top() << '\n';
    }
    solve();
    cout << ans;
    return 0;
}