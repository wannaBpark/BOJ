#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define x first
#define y second
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<ll,ll>;

vector<pii> v;
int N, M;
bool cmp(const pii& p1, const pii& p2){
    return p1.y > p2.y;
}
bool canSolve(ll sz)
{
    auto cur = v[0].y - sz;
    for (int i = 1; i < v.size(); ++i) {
        // cout << "Start : " << v[i].x << " End : " << v[i].y << " cur : " << cur << endl;
        if (!(cur >= v[i].x)) {
            return false;
        }
        if (cur > v[i].y) cur = v[i].y - sz;
        else cur = cur - sz;
    }
    return true;
}
int main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; ++i){
        ll a, length; cin >> a >> length;
        v.push_back({a, a+length});
    }
    sort(v.begin(), v.end(), cmp);

    ll l = 1, r = 1e18;  
    ll ans = 0;
    // bool ret = canSolve(25);
    // cout << "ret : " << ret << endl;
    while (l <= r) {
        ll mid = (l + r) / 2;
        bool ret = canSolve(mid);
        // cout << "ret : " << ret << " mid : " << mid << endl;
        if (ret == false) {
            r = mid - 1;
        } else {
            l = mid + 1;
            ans = max(ans, mid);
        }
    }
    cout << ans << endl;
    return 0;
}