#include <bits/stdc++.h>
#define MAX_M 710
#define fastio cin.tie(0)->sync_with_stdio(0)
#define x first
#define y second
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<ll,ll>;

int M, N;
int dx[3] = {-1,-1,0};
int dy[3] = {-1,0,-1};
int A[MAX_M * 2];
int ans[MAX_M][MAX_M];
int cnt[3] = {0};
int main()
{
    fastio;
    cout.tie(NULL);
    cin >> M >> N;
    for (int i = 0; i < N; ++i) {
        int a, b, c;
        int idx = 0;
        cin >> a >> b >> c;
        idx += a;
        for (int j = 0; j < b; ++j) {
            A[idx++] += 1;
        }
        for (int j = 0; j < c; ++j) {
            A[idx++] += 2;
        }
    }
    for (int i = M - 1; i >= 0; --i) {
        cout << A[i] + 1 << ' ';
        for (int j = M; j < 2*M - 1; ++j) {
            cout << A[j] + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}