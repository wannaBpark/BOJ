#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct status {
    int cur, x, y;
};
struct cmp {
    bool operator()(status& s1, status& s2){
        return s1.cur > s2.cur;
    }
};
priority_queue<status, vector<status>, cmp> pq;
int N;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int cave[150][150];
int dp[150][150] = {0,};
int ans = 0;
inline int isRange(int x, int y) {
    return (x >= 0 && x<N && y>=0 && y<N);
}

void bfs()
{    
    for (int i=0; i<N; ++i) for (int j=0; j<N;++j) dp[i][j] = 99999999;
    dp[0][0] = cave[0][0];
    while (!pq.empty()) {
        status s = pq.top(); pq.pop();
        int cur = s.cur; 
        int x = s.x, y=s.y;
        
        //cout << "cur : " << cur << " " << x << " y: " << y<<'\n';
        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i], ny = y+dy[i];
            // cout << "nx, ny : " << nx << " " << ny <<'\n';
            if (!(x >= 0 && x<N && y>=0 && y<N)) continue;
            int nxtcur = cave[nx][ny] + cur;
            // cout << "nx, ny : " << nx << " " << ny <<'\n';
            if (nxtcur < dp[nx][ny]) {
                dp[nx][ny] = nxtcur;
                pq.push({nxtcur, nx, ny});
            }
            
        }
    }
}
int main()
{
    int i =0;
    cin.tie(NULL)->sync_with_stdio(false);
    do {
        cin >> N;
        if (N==0) break;
        for (int i =0; i<N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> cave[i][j];
            }
        }
        pq = priority_queue<status, vector<status>, cmp>();
        
        pq.push({cave[0][0],0,0});
        bfs();
        cout << "Problem " << ++i << ": " << dp[N-1][N-1] << '\n';
    } while(N!=0);

    return 0;
}