#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int A[510][510]={0,};
int D[510][510] = {0,};
int N, M;
int dp(int i, int j) {
    int& ans = D[i][j];
    if (ans != -1) return ans;
    ans = 0;
    for (int k = 0; k <4; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (!(nx >= 0 && nx < N && ny >=0 && ny<M)) continue;
        if (!(A[i][j] < A[nx][ny])) continue;
        ans += (D[nx][ny] == -1) ? dp(nx, ny) : D[nx][ny];
    }

    return ans;
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N >> M;
    for (int i =0; i<N; ++i) {
        for(int j =0; j<M; ++j){
            cin >> A[i][j];
            D[i][j] = -1;
        }
    }
    D[0][0] = 1;

    cout << dp(N-1,M-1);
    return 0;
}