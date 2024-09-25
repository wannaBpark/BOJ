#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MX 100000000
int N,M;
struct Edge{
    int x;
    int y;
    int cost;
};
struct compare{
    bool operator()(const Edge& e1, const Edge& e2) {
        int d1 = abs(M-e1.x) + abs(N-e1.y);
        int d2 = abs(M-e2.x) + abs(N-e2.y);
        if (d1 == d2) {
            return e1.cost > e2.cost;
        }
        return d1 < d2;
    }
};


int ans = MX;
int dx[4] ={0,0,-1,1};
int dy[4] ={-1,1, 0, 0};
int A[1010][1010];
int visited[1010][1010] = {0,};
priority_queue<Edge, vector<Edge>, compare> pq;

static inline int IsInRange(int x, int y) {
    return x>=1 && x <= M && y >= 1 && y <= N; 
}

void solve()
{
    while(!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();
        if (visited[cur.x][cur.y] != -1 && visited[cur.x][cur.y] <= cur.cost) continue;
        visited[cur.x][cur.y] = cur.cost;
        if (cur.x == M && cur.y == N) {
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (IsInRange(nx,ny) == false || A[nx][ny] == -1) continue;
            
            int nxtcost = cur.cost + A[nx][ny];
            if (visited[nx][ny] == -1 || visited[nx][ny] > nxtcost){
                pq.push({nx, ny, nxtcost});
            }
        }
    }
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> M >> N;
    for (int i = 1; i<=M; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> A[i][j];
            visited[i][j] = -1;
        }
    }
    if (A[1][1] == -1) {
        cout << -1;
        return 0;
    }
    pq.push({1,1,A[1][1]});
    solve();

    cout << visited[M][N];
    return 0;
}