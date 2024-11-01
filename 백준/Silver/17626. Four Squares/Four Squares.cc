#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int D[50010] = {0,};
int N;
int dp(int cur) {
    if (cur <= 0) return 0;
    if (cur == 1) return 1;
    if(D[cur]!=50000) return D[cur];
    for (int i =1; i*i<=cur; ++i) {
        D[cur] = min(dp(cur-i*i)+1, D[cur]);
    }
    return D[cur];
}
int main()
{
    cin >> N;
    fill(D, D+N+1, 50000);
    D[0] = 0;
    D[1] = 1;
    cout << dp(N);
    return 0;
}