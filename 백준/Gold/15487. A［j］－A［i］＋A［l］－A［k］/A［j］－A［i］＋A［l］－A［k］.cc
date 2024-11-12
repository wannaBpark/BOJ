#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
int D[1000'001];
int A[1000'001];
int N;
int ans = -1e9;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    int mn = 1e9; D[0] = -1e9;
    for (int i = 0; i<N; ++i) {
        cin >> A[i];
        if (i>=1) D[i] = max(D[i-1], A[i] - mn); // A[j] - A[i] 최댓값
        mn = min(mn, A[i]);
    }
    int mx = A[N-1];
    int j_i, l_k = -1e9;
    for (int k = N-2; k>1; --k) {
        j_i = D[k-1];
        l_k = max(l_k, mx - A[k]);
        ans = max(ans, j_i + l_k);
        mx = max(mx, A[k]);
    }
    cout << ans;
    return 0;
}