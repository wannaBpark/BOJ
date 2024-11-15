#include <bits/stdc++.h>
#define INF 1e9
#define MXN 100010
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

struct coin{
    int x, y;
};
int ans;
vector<coin> v;
char b[25][25]; // board
int visited[25][25][25][25]= {0,};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int N, M;
static inline int IsRange(coin& c) {
    int ret = (c.x >= 0 && c.x < N && c.y >= 0 && c.y < M);
    return ret == true ? 1 :0;
}
static inline int IsWall(int x, int y) {
    return b[x][y] == '#';
}
static inline int IsOneDown(coin& c1, coin& c2) {
    int cnt = IsRange(c1) + IsRange(c2);
    return cnt;
}
void bfs(coin c1, coin c2, int cnt) {
    visited[c1.x][c1.y][c2.x][c2.y]= true;
    if (ans < cnt) return;
    if (cnt > 10) return;
    for (int i=0;i<4; ++i) {
        coin n1,n2;
        n1 = {c1.x+dx[i], c1.y+dy[i]}; 
        n2 = {c2.x+dx[i], c2.y+dy[i]};
        int ret = IsOneDown(n1, n2);
        if (ret == 0) continue;
        if (ret == 1) {
            ans = min(ans, cnt+1); 
            return;
        }
        if (IsWall(n1.x, n1.y)) {n1.x = c1.x; n1.y = c1.y;}
        if (IsWall(n2.x, n2.y)) {n2.x = c2.x; n2.y = c2.y;}        
        // cout << "ret: "<<ret <<'\n'; 
        // if (visited[n1.x][n1.y][n2.x][n2.y] == true) continue;
        visited[n1.x][n1.y][n2.x][n2.y] = true;
        bfs(n1,n2, cnt+1);
    }
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j = 0; j<M; ++j) {
            cin >> b[i][j];
            if (b[i][j] == 'o') v.push_back({i,j});
        }
    }
    ans = INF;
    bfs(v[0], v[1], 0);
    if (ans == INF || ans >10) { ans = -1; }
    // cout << "ans : ";
    cout << ans << '\n';
    return 0;
}