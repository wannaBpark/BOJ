#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
struct product{
    int y, k;
};
int N,M;
int in[110] = {0,};
map<int, int> m;
vector<int> basic;
vector<product> v[110];
queue<product> q;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >>N >> M;
    for (int i =0; i<M; ++i) {
        int x,y,k;
        cin >> x >> y >> k;
        v[x].push_back({y,k});
        ++in[y];
    }
    q.push({N,1});
    m[N] = 1;
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        auto cur = p.y; auto coeff = p.k;
        if (v[cur].empty()) {
            basic.push_back(cur);
            continue;
        }

        for (auto& i :v[cur]) {
            int nxt = i.y; int k = i.k;
            m[nxt] += m[cur] * k; // cur번을 만들기 위한 nxt번째 부품수 계산
            if (--in[nxt] == 0) {
                q.push({nxt, k*coeff});
            }
        }                
    }
    sort(basic.begin(), basic.end());
    for (auto& i : basic) {
        cout << i << " " << m[i] <<'\n';
    }
    return 0;
}