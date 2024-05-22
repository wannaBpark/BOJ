#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int N;
vector<int> v;
vector<int> ans;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i<N; ++i) {
        int a;  cin >> a;
        v.push_back(a);
    }
    for (auto it = v.begin(); it != v.end(); ++it) {
        int cur = *it;
        int sz = ans.size();
        auto idx = lower_bound(ans.begin(), ans.end(), cur) - ans.begin();
        if (idx == sz) ans.push_back(cur);
        else {
            ans[idx] = cur;
        }
    }
    cout << ans.size() ;
    // << '\n';
    // for(auto it = ans.begin(); it != ans.end(); ++it) {
    //     cout << *it << ' ';
    // }
    return 0;
}