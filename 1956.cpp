#include <cstdio>
#include <string.h>
#define min(a,b) {(a<b) ? a:b}
int F[401][401];
const int INF = 10000;
int main()
{
	//freopen("input.txt", "r", stdin);
	int V, E, s, e, t,ans=4000000; //최악이 모든 정점 방문이므로 (정점-1)*최대비용
									//ans = 대충 V*10000 
	scanf("%d%d", &V, &E);
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			F[i][j] = 4000000;
		}
	}
	while (E--) {
		scanf("%d%d%d", &s, &e, &t);
		F[s][e] = min(t, F[s][e]);
	}
	for (int i = 0; i < E; i++) {
		scanf("%d%d%d", &s, &e, &t);
		F[s][e] = t;
	}
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				F[i][j] = min(F[i][j], F[i][k] + F[k][j]);
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			printf("%d ", F[i][j]);
		}
		printf("\n");
	}
	for (int i = 1; i <= V; i++) {
		ans = min(F[i][i], ans); //F[i][i]존재 => 사이클 있단소리
	}
	(ans < 4000000) ? printf("%d\n",ans) : printf("-1\n");
	return 0;
}