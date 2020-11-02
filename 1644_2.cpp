#include <cstdio>
long long N,ans=0;
long long A[4001000];
long long sosu[4001000];
long long pSum[4001000];
int main()
{
	scanf("%d", &N);
	int index = 1,sum;
	for (int i = 2; i*i <= N; i++) {
		for (int j = i*i; j <= N; j += i) {
			A[j]++;
		}
	}
	for (int i = 2; i <= N; i++) if (!A[i]) sosu[index++] = i;
	for (int i = 1; i < index; i++) pSum[i] += pSum[i - 1] + sosu[i];
	for (int i = 1; i < index; i++) {
		for (int j = 0; j < i; j++) {
			if (pSum[i] - pSum[j] == N) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}