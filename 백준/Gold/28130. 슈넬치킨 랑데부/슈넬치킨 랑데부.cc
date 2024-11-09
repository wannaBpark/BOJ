#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 1e9
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int visited[1010][1010]={0,};
int Dist[1010][1010];
int T1[1010][1010]={0,};
char A[1010][1010];
int N, M;
queue<pii> q;
queue<pii> q_it;
pii sunwoo;
int dir = 0;
int ans = INF;
static inline int isRange(int i, int j) {
    return (i>= 0 && i<N && j<M && j>= 0);
}
void bfs() {
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        auto& i = p.first; auto& j = p.second;
        auto& cur = Dist[i][j];
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int nx = i + dx[k]; int ny = j + dy[k];
            if (!isRange(nx, ny) || Dist[nx][ny] == -1 || visited[nx][ny] == true) continue;
            auto& nxt = Dist[nx][ny];
            visited[nx][ny] = true;
            nxt = min(cur + 1, nxt);
            q.push({nx, ny});
        }
    }
}
void iteration() {
    int d = dir;
    int nx, ny;
    int x = sunwoo.first; int y = sunwoo.second;
    int cnt =0;
    int rendez_vous = 2*(N+M) - 4;
    while (visited[x][y]!=true) {
        nx = x + dx[d]; ny = y + dy[d];
        if (!isRange(nx, ny)) {
            ++d; d = d%4;
            nx = x + dx[d]; ny = y + dy[d];
        }
        int t1 = cnt++; int t2 = Dist[x][y];
        visited[x][y] = true;
        while (!(t1 >= t2)) {
            t1 += rendez_vous;
        }
        if ( (t1-t2) % 2== 0) {
            ans = min(ans, t1);
        }
        x=nx; y = ny;
    }
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N >> M;
    for (int i =0; i<N; ++i) {
        for (int j =0; j<M; ++j) {
            char c; cin >> c;
            A[i][j] = c;
            Dist[i][j] = INF;
            if (c == 'A') {
                Dist[i][j] = 0; q.push({i,j});
            } else if (c=='G') {
                Dist[i][j] = -1;
            } else if (c=='B') {
                sunwoo = {i,j};
            }
        }
    }
    bfs();
    for (int i =0; i<N; ++i) for (int j =0; j<M; ++j) visited[i][j] = 0;
    if ( sunwoo.first == 0) {
        dir = 0;
    } else if (sunwoo.first == N-1) {
        dir = 2;
    } else {
        if (sunwoo.second == M-1) dir = 1;
        else dir = 3;
    }
    iteration();
    if (ans==INF) ans = -1;
    cout << ans;
    return 0;
}