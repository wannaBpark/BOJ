#include <cstdio>
#include <string.h>
#define min(a,b) {(a<b) ? a:b}
int F[401][401];
int chk[401][401] = { 0, };
int main()
{
	freopen("input.txt", "r", stdin);
	int V, sum = 0;
	scanf("%d", &V);
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			scanf("%d", &F[i][j]);
			sum += F[i][j];
		}
	}
	int ans = sum;
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (F[i][j] == F[i][k] + F[k][j] && (F[i][k] && F[k][j])) { //0이 들어가는 경로 방지
					chk[i][j] = chk[j][i] = 1;
				}
				else if (F[i][j] > F[i][k] + F[k][j]) {
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (chk[i][j]) ans-= F[i][j];
		}
	}
	printf("%d\n", ans / 2);
	return 0;
}