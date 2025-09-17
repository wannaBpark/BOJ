#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_E 400000
using namespace std;
struct Edge {
	int to, cost;
};
bool operator<(Edge a, Edge b) {
	return a.cost > b.cost;
}
vector<Edge> v[400000];
int dist[801]; int start[3] = { 0, }; int minDist[801][801];
priority_queue<Edge> q;
int N, E,p1,p2;
const int INF = 98765432;
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &E);
	int a, b, c;
	for (int i = 0; i < E; i++) {
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back({ b,c }); v[b].push_back({ a,c });
	}
	scanf("%d%d", &start[1], &start[2]);
	start[0] = 1;
	for (int i = 0; i < 3; i++) {
		int S = start[i];
		fill(dist, dist + N + 1, INF);
		dist[S] = 0;
		q.push({ S,0 });
		while (!q.empty()) {
			Edge cur = q.top(); q.pop();
			if (dist[cur.to] < cur.cost) continue;
			for (Edge &next : v[cur.to]) {
				if (dist[next.to] > dist[cur.to] + next.cost) {
					dist[next.to] = dist[cur.to] + next.cost;
					q.push({ next.to, dist[next.to] });
				}
			}			
		}
		for (int j = 1; j <= N; j++)
            minDist[S][j] = dist[j];
	}
	int centerPath = minDist[start[1]][start[2]];
	int _st1 = minDist[1][start[1]], _st2 = minDist[1][start[2]];
	int _1te = minDist[start[1]][N], _2te = minDist[start[2]][N];
	int ans = min(_st1+_2te, _st2+_1te);
	ans += centerPath;	ans >= INF ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}