#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> v;
vector<int> advent[101];
int used[101]={0,};
int N,K,a;
int ans= 0;
int findmostFar() {
    int mxadvent=-1;
    int ret = 0;
    for (int i =1; i<=K; ++i) {
        if(!used[i]) continue;
        if (advent[i].size() == 0) return i;
        if (mxadvent < advent[i][0]) {
            mxadvent = advent[i][0];
            ret = i;
        }
    }
    return ret;
}
void solve()
{
    int sz = 0;
    for (int i =0; i<K; ++i) {
        int& cur = v[i];
        // cout << cur << '\n';
        if (sz<N) {
            sz += (used[cur]) ? 0 : 1;
            used[cur] = true;
        } else if (sz==N) {
            if (!used[cur]) {
                ++ans;
                int unplug = findmostFar();
                used[unplug] = false;
                used[cur] = true;
            }
        }
        advent[cur].erase(advent[cur].begin());
    }
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
         cin >> a; 
         v.push_back(a);
         advent[a].push_back(i);
    }
    solve();
    cout << ans;
    return 0;
}