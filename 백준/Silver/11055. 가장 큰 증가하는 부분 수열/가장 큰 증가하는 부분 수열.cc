#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, ans=-1;
int A[1010];
int D[1010];
// dp(cur) : cur(자기자신)까지 더했을때 증가하는 부분수열 합의 최댓값
int dp(int cur) {
    int& ret = D[cur];
    if (ret!=-1) return ret;
    ret = A[cur];
    for (int nxt=cur-1; nxt>=0; --nxt) {
        if (A[nxt] >= A[cur]) continue;
        ret = max(dp(nxt) + A[cur], ret);
    }
    return ret;
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    for (int i =0; i<N; ++i) {
        cin >> A[i];
        D[i] = -1;
    }
    D[0] = A[0];
    for (int i =0; i<N; ++i) {
        ans = max(ans, dp(i));
    }
    cout << ans;
    return 0;
}