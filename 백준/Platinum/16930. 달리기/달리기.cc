#include <bits/stdc++.h>
const int INF = 1e9;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
queue<pii> q;
char A[1010][1010];
int D[1010][1010];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int N, M, K;
int X1, Y1, X2, Y2;
void input();

static inline int IsRange(int i, int j) {
    return (i>=1 && i<=N && j>=1 && j<=M);
}

void solve(int i, int j)
{
    q.push({i,j});
    while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (i == X2 && j == Y2) continue;

        for(int dir=0; dir<4; ++dir) {
            for (int k = 1; k <= K; ++k) {
                int nx = dx[dir] * k + i; 
                int ny = dy[dir] * k + j;
                if (!IsRange(nx,ny) || A[nx][ny] == '#' || D[nx][ny] < D[i][j] + 1) {
                    break;
                }
                if (D[nx][ny] == INF) {
                    D[nx][ny] = D[i][j] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    input();
    D[X1][Y1] = 0;
    solve(X1, Y1);
    
    if (D[X2][Y2] == INF) {
        D[X2][Y2] = -1;    
    }
    cout << D[X2][Y2]<<'\n';
    return 0;
}

void input()
{
    cin >> N >> M >> K;
    for (int i =1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            cin >> A[i][j]; 
            D[i][j] = INF;
        }
    }
    cin >> X1 >> Y1 >> X2 >> Y2;
}