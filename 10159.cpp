#include <cstdio>
int N, M;
int dist[101][101] = { 0, };
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	int a, b,cnt=0;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		dist[a][b] = 1; 	
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][k] && dist[k][j]) {
					dist[i][j] = 1; 
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j]) dist[j][i] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == 0 && i != j) ++cnt;
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
	return 0;
}