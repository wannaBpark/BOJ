#include <cstdio>
int P[100001] = { 0, };
int N, M;
int a, b;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &P[i]);
		P[i] += P[i - 1];
	}

	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", P[b] - P[a-1]);
	}
	return 0;
}