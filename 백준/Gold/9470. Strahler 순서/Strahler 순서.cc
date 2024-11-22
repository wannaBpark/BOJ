#include <bits/stdc++.h>
const int INF = 1e9;
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int T,K,M,P;
void solve();
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    solve();
    return 0;
}

void solve()
{
    cin >> T;
    while (T--) {
        cin >> K >> M >> P;
        vector<int> v[1010];
        vector<int> in;
        vector<pii> strah;
        queue<int> q;
        in.resize(M+1); strah.resize(M+1);
        for (int _=0; _<P; _++) {
            int a,b; cin >> a>>b;
            v[a].push_back(b);
            ++in[b];
        }
        for (int i = 1; i<=M; ++i) {
            if(!in[i]) { 
                strah[i].first = 1;
                q.push(i);
            }
        }

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            auto& s_cur = strah[cur];
            if (s_cur.second > 1) s_cur.first++;
            for (auto& nxt : v[cur]) {
                auto& s_nxt = strah[nxt];
                if (--in[nxt] == 0) {
                    q.push(nxt);
                }
                if (s_nxt.first == s_cur.first) {
                    s_nxt.second++;
                } else if (s_nxt.first < s_cur.first) {
                    s_nxt.first = s_cur.first;
                    s_nxt.second = 1;
                }
            }
        }
        // for (int i =1; i<=M; ++i) {
        //     cout << strah[i] << " ";
        // }
        // cout << '\n';
        cout << K << " " << strah[M].first << '\n';
    }
}