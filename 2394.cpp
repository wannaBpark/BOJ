#include <stdio.h>
int N, K;
int DP[10001] = { 0, };
int Coin[101] = { 0, };
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N,&K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &Coin[i]);
	}

	return 0;
}