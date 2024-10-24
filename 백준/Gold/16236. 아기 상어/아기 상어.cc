#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct fish{
    int sz, x, y;
};
struct distpos{
    int dist,x,y;
};
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int visited[25][25]={0,};
int A[25][25];
int N, ans = 0;
static fish shark;
vector<fish> v;
struct cmp{
    bool operator()(fish& f1, fish& f2) {
        // dist
        if (f1.sz == f2.sz) {        
            if(f1.x == f2.x) {
                return f1.y > f2.y;
            }
            return f1.x > f2.x;
        }
        return f1.sz > f2.sz;
    }
};
priority_queue<fish, vector<fish>, cmp> pq;
void input() {
    cin >> N;
    for (int i =0 ; i<N; ++i) {
        for (int j = 0; j<N; ++j) {
            cin >> A[i][j];
            if (A[i][j] == 9) {
                shark = {2, i, j};
            } else if (A[i][j] >= 1){
                v.push_back({A[i][j],i,j});
            }
        }
    }
}
int bfs(fish f) {
    queue<distpos> q;
    int vstd[25][25]={0,};
    q.push({0,shark.x, shark.y});
    // cout << "shark : " << shark.x << " " << shark.y <<'\n';
    distpos ret;
    ret.dist = 9999999;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
    
        
        if (cur.x == f.x && cur.y == f.y) {
            ret.dist = cur.dist;
            break;
        }
        for (int i =0; i<4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (!(nx>=0 && nx<N && ny>=0 && ny<N)) continue;
            if (A[nx][ny] > shark.sz || vstd[nx][ny]) continue;
            // cout << "nxt: "<<nx << " " << ny << " " << A[nx][ny]<< '\n';
            // cout << "nx ny : "<<nx << " " << ny <<" "<<A[nx][ny] << " sz " << shark.sz <<'\n';
            vstd[nx][ny] = true;
            q.push({cur.dist+1, nx,ny});
        }
    }
    return ret.dist;
}
void solve() 
{
    int cnt = 0;
    // cout << "shark: " <<shark.sz << " " << shark.x<<'\n';
    while (true) {
        pq = priority_queue<fish, vector<fish>, cmp>();
        for (int i = 0; i < v.size(); ++i) {
            fish& f = v[i];
            if(visited[f.x][f.y] || f.sz >= shark.sz) continue;

            int dist = bfs(f);
            if (dist == 9999999) continue;
            pq.push({dist, f.x, f.y});
            // cout << "pq push : " << dist<<" "<<f.x << " " << f.y <<'\n';
        }
        
        if (pq.size() == 0) break;
        
        fish f = pq.top(); pq.pop();
        ans += f.sz; // dist
        A[shark.x][shark.y] = 0;
        visited[f.x][f.y] = true;
        ++cnt;
        // cout << "ans: " << ans << " pq top : " << f.sz<<" "<<f.x << " " << f.y <<'\n';
        if (cnt == shark.sz) {
            cnt = 0; 
            ++shark.sz;
        }
        shark.x = f.x;
        shark.y = f.y;
    }
    
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    input();
    solve();
    cout << ans;
    return 0;
}