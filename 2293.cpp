#include <stdio.h>
#define MAX(a,b) (a>b) ? a:b
#define MAX_K 100001
int DP[MAX_K] = { 0, };
int Coin[101];
int N, K;
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	//1의 배수들에++ 2의 배수들에++ 5의 배수들에 ++
	for (int i = 0; i < N; i++) {
		scanf("%d", &Coin[i]);
	}
	DP[0] = 1;
	for (int j = 0; j <N; j++) {
		for (int i = 1; i <= K; i++) {
			if (i >= Coin[j]) {
				DP[i] += DP[i - Coin[j]];
			}
		}
	}
	
	printf("%d\n", DP[K]);
	return 0;
}