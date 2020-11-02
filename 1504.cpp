#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_E 400000
// 1 2 3 4와 1 3 2 4를 비교한후 출력하면된다. 
//단 ans와 INF비교할때 int 와 longlong비교가 될수있으므로 INF는 너무 크지않게 설정
using namespace std;

struct Edge {
	int to, cost;
};
bool operator<(Edge a, Edge b) {
	return a.cost > b.cost;
}
vector<Edge> v[400000];
int dist[801];
int start[3] = { 0, };
int minDist[801][801];
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
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	scanf("%d%d", &start[1], &start[2]);
	start[0] = 1;
	for (int i = 0; i < 3; i++) {
		int S = start[i];
		//printf("S : %d\n", S);

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
		for (int j = 1; j <= N; j++) {
			minDist[S][j] = dist[j];
		}
	} 
	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", minDist[i][j]);
		}
		printf("\n");
	}*/
	int centerPath = minDist[start[1]][start[2]];
	int _st1 = minDist[1][start[1]], _st2 = minDist[1][start[2]];
	int _1te = minDist[start[1]][N], _2te = minDist[start[2]][N];
	int ans = min(_st1+_2te, _st2+_1te);
	ans += centerPath;
	ans >= INF ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}