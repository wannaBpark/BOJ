#include <cstdio>
#define min(a,b) (a<b) ? a: b
#define ll long long
struct Edge {
	int from;
	int to;
	int cost;
}V[6001];
int dist[501];
int N, M;
int INF = 10000010;
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	dist[1] = 0;
	for (int i = 2; i <= N; i++) {
		dist[i] = INF;
	}
	int update = 0;
	for (int i = 1; i <= M; i++)
		scanf("%d %d %d", &V[i].from, &V[i].to, &V[i].cost);
	int j;
	for (j = 0; j < N; j++) { //N-1까지는 음수사이클 안돌음. N까지 돌아야 음수사이클 확인가능?
		for (int i = 1; i <= M; i++) {
			if (dist[V[i].to] > dist[V[i].from] + V[i].cost &&
				dist[V[i].from]+V[i].cost <=5000000) {
				update = 1;
				dist[V[i].to] = dist[V[i].from] + V[i].cost;
			}
		}
		if (!update) break;
		update = 0;
	}
	if (j >= N) printf("-1\n");
	else {
		for (int i = 2; i <= N; i++) {
			 if(dist[i] > 5000000) printf("-1\n");
			 else printf("%d\n", dist[i]);
		}
	}
	return 0;
}