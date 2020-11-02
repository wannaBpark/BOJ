#include <cstdio>
#define MAX 1025
typedef long long ll;
ll pSum[MAX][MAX] = { 0, },A[MAX][MAX];
int N, M;
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &pSum[i][j]); A[i][j] = pSum[i][j];
			pSum[i][j] += (pSum[i - 1][j] + pSum[i][j - 1] - pSum[i-1][j-1]);
			//printf("%d ", pSum[i][j]);
		}
		//printf("\n");
	}
	int x1, x2, y1, y2;
	while (M--) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		ll tmp = pSum[x2][y1 - 1] + pSum[x1 - 1][y2] - pSum[x1 - 1][y1 - 1];
		printf("%d\n", pSum[x2][y2]-tmp);
	}
	return 0;
}