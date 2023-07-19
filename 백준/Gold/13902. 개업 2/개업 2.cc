#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define x first
#define y second
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<ll,ll>;

vector<int> input;
vector<int> v;
int N, M;

// i 개 짜장면을 만들기 위한 최소 요리 횟수를 저장ㅉ
int dp[10100];

int main()
{
    fastio;
    cin >> N >> M;
    // memset(dp, (int)10001, sizeof(int) * (N+2));
    for (int i = 0; i <= N+2; ++i) {
        dp[i] = 1e5;
    }
    for (int i = 0; i < M; ++i) {
        int a; cin >> a;
        input.push_back(a);
        v.push_back(a);
        dp[a] = 1;
    }
    for (int i = 0; i < M - 1; ++i) {
        int a1 = input[i];
        for (int j = i + 1; j < M; ++j) {
            int a2 = input[j];
            if (a1 + a2 > N) continue;
            dp[a1+a2] = 1;
            v.push_back(a1+a2);
        }
    }
    v.erase(unique(v.begin(),v.end()),v.end());
    sort(v.begin(), v.end());
    // for (auto i : v){
    //     cout << i << endl;
    // }
    dp[0] = 0;
    size_t sz = v.size();
    for (int i = v[sz-1]; i <= N; ++i) {
        int& cur = i;
        for (int j = v.size() - 1; j >= 0; --j) {
            int prev = cur - v[j];
            if (prev <= 0) continue;
            if (dp[cur] > dp[prev] + 1) dp[cur] = dp[prev] + 1;
        }
        // for (int j = 0; j <= N; ++j) {
        //     cout << dp[j] << " ";
        // }
        // cout << endl;
    }
    int ans = (dp[N] == 1e5) ? -1 : dp[N]; 
    cout << ans << endl;
    return 0;
}