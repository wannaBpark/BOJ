#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int m_region[1010][1010];
unordered_map<int, int> m_cnt;
int A[1010][1010];
int visited[1010][1010]={0,};
int di[4] = {0,0,-1,1};
int dj[4] = {1,-1,0,0};
int region_cnt = 0;
int N,M;
void solve();
void print();
static inline int isRange(int i, int j) {
    return (i>= 0 && i<N && j>=0 && j<M);
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i<N; ++i) {
        for (int j = 0; j<M; ++j) {
            char c;
            cin >> c;
            A[i][j] = c-'0';
        }
    }
    solve();
    print();
    return 0;
}

void bfs(int i, int j) 
{
    int r = region_cnt;
    m_cnt[r] =0;
    queue<pair<int,int>> q;
    visited[i][j] = true;
    m_region[i][j] = r;        
    q.push({i,j});
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        int curx = p.first; int cury = p.second;
        m_cnt[r] = (m_cnt[r]+1);
        for(int i=0; i<4; ++i) {
            int ni = curx + di[i];
            int nj = cury + dj[i];
            if (!isRange(ni,nj) || visited[ni][nj] || A[ni][nj] == 1) continue;
            q.push({ni,nj});
            visited[ni][nj] =true;
            m_region[ni][nj] = r; 
        }
    }
    // cout << "m_cnt[r] : " << r << " " << m_cnt[r] << '\n';
}
void solve()
{
    for (int i = 0; i<N; ++i) {
        for (int j = 0; j<M; ++j) {
            if (A[i][j] == 0 && !visited[i][j]) {
                bfs(i, j);
                region_cnt++;
            }
        }
    }

    for (int i =0; i<N; ++i) {
        for (int j =0; j<M; ++j) {
            if (A[i][j] == 0) continue;
            visited[i][j] = 0;
            set<int> s_region;
            for (int k = 0; k < 4; ++k) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (!isRange(ni,nj) || A[ni][nj] == 1) continue;
                int r = m_region[ni][nj];
                s_region.insert(r);
            }
            for (auto& it : s_region) {
                visited[i][j] += m_cnt[it];
            }
            visited[i][j] = (visited[i][j]+1) % 10;

        }
    }
}
void print()
{
    for (int i = 0; i<N; ++i) {
        for (int j = 0; j<M; ++j) {
            if (A[i][j] == 1) cout << visited[i][j];
            else cout << '0';
        }
        cout << '\n';
    }
}