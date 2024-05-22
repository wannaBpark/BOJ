#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int N;
vector<int> v;
vector<int> ans;
vector<int> realAns;
int d[5050];
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i<N; ++i) {
        int a;  cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < v.size(); ++i) {
        int cur = v[i];
        int sz = ans.size();
        auto idx = lower_bound(ans.begin(), ans.end(), cur) - ans.begin();
        if (idx == sz) ans.push_back(cur);
        else {
            ans[idx] = cur;
        }
    }
    cout << N - ans.size();
    return 0;
}