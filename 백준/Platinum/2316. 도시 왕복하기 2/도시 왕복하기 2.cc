#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
const int MAX_V = 900;
const int INF = 1e9;

int N, P;                  // 소의 수 N, 축사의 수 M
int c[MAX_V][MAX_V] = {0}; // c[i][j]: i에서 j로 가는 간선의 용량
int f[MAX_V][MAX_V] = {0}; // f[i][j]: i에서 j로 현재 흐르는 유량
vector<int> adj[MAX_V];    // 인접 리스트

int ans = 0;
const int OUT = 402;

// total: 총 유량, S: 소스, E: 싱크
int total = 0, S = 1 + OUT, E = 2;
void bfs_Edmonds_Karp()
{
    // 증가 경로를 못 찾을 때까지 루프
    while (true) {
        // 증가 경로를 BFS로 찾음
        int prev[MAX_V];
        fill(prev, prev + MAX_V, -1);
        queue<int> Q;
        Q.push(S);
        while (!Q.empty() && prev[E] == -1) {
            int cur = Q.front();
            Q.pop();
            for (int next : adj[cur]) {
                // c[i][j]-f[i][j] > 0: i에서 j로 유량을 흘릴 여유가 남았는가?
                // prev[next] == -1: next 정점을 아직 방문하지 않았는가?
                if (c[cur][next] - f[cur][next] > 0 && prev[next] == -1) {
                    Q.push(next);
                    prev[next] = cur; // 경로를 기억하기 위해 prev 배열 사용
                    if (next == E) break; // 싱크에 도달하면 나옴
                }
            }
        }
        // 싱크로 가는 경로가 더 없으면 루프 탈출
        if (prev[E] == -1) return;

        // 경로상에서 가장 허용치가 낮은 곳을 찾음
        int flow = INF;
        int cnt = 0;
        for (int i = E; i != S; i = prev[i]) {
            int& from = prev[i];
            int& to = i;
            flow = min(flow, c[from][to] - f[from][to]);
        }
        // 찾은 flow만큼 해당 경로에 유량 흘려줌
        for (int i = E; i != S; i = prev[i]) {
            int& from = prev[i];
            int& to = i;
            f[from][to] += flow;
            f[to][from] -= flow;

            ++cnt;
        }
        ans = max(ans, cnt);

        // 총 유량 값 증가
        total += flow;
    }
}

int main()
{
    fastio;
    // 간선 정보 입력받기
    cin >> N >> P;
    for (int i = 1; i<= N; ++i) {
        adj[i].push_back(i+OUT);
        adj[i+OUT].push_back(i); // 역방향 간선도 추가해줘야 함
        c[i][i+OUT] = 1;
    }
    for (int i = 0; i < P; ++i) {
        int u,v;
        cin >> u >> v;
        c[u+OUT][v] = 1; // 같은 간선이 여러 번 들어올 수 있으므로 
        c[v+OUT][u] = 1;

        adj[u+OUT].push_back(v);
        adj[v].push_back(u+OUT); // 역방향 간선
        
        adj[u].push_back(v+OUT);
        adj[v+OUT].push_back(u); // 역방향 간선
    }
    bfs_Edmonds_Karp();

    // 결과 출력
    cout << total;
}
