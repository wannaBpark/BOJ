#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

vector<int> v;
vector<int> ans;
int N;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for (auto it = v.begin(); it != v.end(); ++it) {
        int cur = *it;
        int sz = ans.size();
        int idx = lower_bound(ans.begin(), ans.end(), cur) - ans.begin();
        if (idx == sz) {
            ans.push_back(cur);
        } else {
            ans[idx] = cur;
        }
    }
    cout << ans.size();
    return 0;
}