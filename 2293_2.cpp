#include <cstdio>
int Coin[101];
int A[11000];
int N, K;
int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &Coin[i]);
	A[0] = 1;
	for (int j = 0; j < N; j++) {
		for (int i = 1; i <= K; i++) {
			if (i>=Coin[j]) A[i] += A[i - Coin[j]];
		}
		///*for (int i = 1; i <= K; i++) printf("%d ", A[i]);
		//puts("");*/
	}

	printf("%d\n", A[K]);
	return 0;
}