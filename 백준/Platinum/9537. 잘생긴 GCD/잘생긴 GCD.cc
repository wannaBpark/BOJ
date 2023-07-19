#include <bits/stdc++.h>
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define x first
#define y second
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
int N ,T;
int main()
{
    fastio;
    cin >> T;
    while (T--) {
        vector<pii> v[100010];
        ll A, ans = 0, G;

        cin >> N;
        cin >> A; v[1].push_back({A, 1});
        ans = max(ans, A);
        for (int i = 2; i <= N; ++i){
            cin >> A;
            ans = max(ans, A); // current max = ONE element itself
            for (auto& elem : v[i - 1]) {
                G = __gcd(elem.x, A);

                if (v[i].empty() || v[i].back().x != G) {
                    v[i].push_back({G, elem.y});
                }
                ans = max(ans, G * (i - elem.y + 1));
            }
            if (v[i].back().x != A) v[i].push_back({A,i});
        }
        cout << ans << endl;
    }
   
    return 0;
}