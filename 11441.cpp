#include <stdio.h>
#define MAX 100001
int N,M,i,j;
int P[MAX] = { 0, };
int A[MAX] = { 0, };
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		P[i] = A[i];
	}
	for (int i = 1; i <= N; i++) {
		P[i] += P[i - 1];
	}
	scanf("%d", &M);
	for (int k = 1; k <= M; k++) {
		scanf("%d %d", &i, &j);
		printf("%d\n", P[j] - P[i - 1]);
	}
	return 0;
}