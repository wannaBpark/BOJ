#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define x first
#define y second
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<ll,ll>;

int n, k, s;
ll ans;

int dp[25][11][200];
int solve()
{
    int ans = 0;
    vector<bool> permutation(n, true);

    if (k > s || n < k) return ans;

    for (int i = 0; i < permutation.size() - k; ++i){
        permutation[i] = false;
    }
    do {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if(permutation[i]) sum += (i + 1);
        }
        ans = (sum == s) ?  ans + 1 : ans;
    } while (next_permutation(permutation.begin(), permutation.end()));
    // cout << "answer : " << ans << endl;
    return ans;
}
int main()
{
    fastio;
    n = k = s = 1;
    do {
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0) break;
        cout << solve() << endl;
    } while(n != 0 && k != 0 && s != 0);
    
    
    
    return 0;
}