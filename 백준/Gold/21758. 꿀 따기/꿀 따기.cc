#include <bits/stdc++.h>
#define MX (int)1e5
using ll = long long;
using namespace std;
void solve();

int honey[MX+10];
ll pSum[MX+10];
ll pSum2[MX+10];

int N;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> honey[i];
        pSum[i] = pSum[i-1] + honey[i];
    }
    solve();
}

void solve()
{
    ll ans = 0;
    
    for (int i = 2; i < N; ++i) {
        // 벌 벌 벌통
        ll toRight = (pSum[N] - pSum[1] - honey[i]);
        toRight += (pSum[N] - pSum[i]);
        ans = max(ans, toRight);

        // 벌통 벌 벌
        ll toLeft = (pSum[N - 1] - honey[i])
                    + (pSum[i-1]);
        ans = max(ans, toLeft);
        // 벌 벌통 벌
        ll toCenter = (pSum[i] - pSum[1]) + (pSum[N - 1] - pSum[i - 1]);
        ans = max(ans, toCenter);
    }

    cout << ans;
}