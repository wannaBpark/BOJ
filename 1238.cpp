#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX_M 10001

using namespace std;
struct Edge {
	int to, cost;
};
bool operator<(Edge a, Edge b) {
	return a.cost > b.cost;
}
vector<Edge> v[MAX_M];


int N, M,X;
int ans = 0;
int minDist[1001][1001] = { 0, };

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &N, &M,&X);
	int a, b, c;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back({ b,c });

	}
	int S = 1;
	while (S<=N) {
		int dist[MAX_M];
		priority_queue<Edge> q;
		memset(dist, 0x5f, sizeof dist);
		dist[S] = 0;
		q.push({ S,0 });

		while (!q.empty()) {
			Edge cur = q.top();
			q.pop();
			if (dist[cur.to] < cur.cost) continue;
			for (Edge &next : v[cur.to]) {
				if (dist[next.to] > dist[cur.to] + next.cost) {
					dist[next.to] = dist[cur.to] + next.cost;
					q.push({ next.to, dist[next.to] });
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			minDist[S][i] = dist[i];
		}
		S++;
	}
	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", minDist[i][j]);
		}
		printf("\n");
	}*/
	for (int i = 1; i <= N; i++) {
		ans = max(ans, minDist[i][X] + minDist[X][i]);
	}
	printf("%d\n", ans);
	
	

	return 0;
}