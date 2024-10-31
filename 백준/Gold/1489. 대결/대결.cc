#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int A[55];
int B[55];
int D[55][55];
int dp(int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (D[i][j]) return D[i][j];
    int& a = A[i]; int& b=B[j];
    if (a>b) {
        return D[i][j] = dp(i-1, j-1) + 2;
    } else if (a==b) {
        return D[i][j] = max(dp(i-1, j-1) + 1, dp(i, j-1));
    } else if (a<b) {
        return D[i][j] = dp(i,j-1);
    }
    
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N;
    for (int i =0; i<N; ++i) {
        cin >> A[i];
    }
    for (int i =0; i<N; ++i) {
        cin >> B[i];
    }
    sort(A, A+N);
    sort(B, B+N);
    cout << dp(N-1, N-1);

    return 0;
}