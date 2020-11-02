#include <stdio.h>
#define MIN(a,b) (a<b) ? a : b
#define CASE 0
#define NUM 1
int N, K;
int Coin[101] = { 0, };
int DP[10001] = { 0, };
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &Coin[i]);
	}
	for (int i = 1; i <= K; i++)
		DP[i] = 1000000;
	for (int j = 0; j < N; j++) {
		for (int i = Coin[j]; i <= K; i++) {
			DP[i] = MIN(DP[i], DP[i - Coin[j]] + 1);
		}
	}
	printf("%d\n", (DP[K] == 1000000) ? -1 : DP[K]);
	return 0;
}