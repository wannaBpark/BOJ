#include <cstdio>
int N;
int A[1010];
int dp[1010];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i])
				dp[i] = dp[j] > dp[i] ? dp[j] : dp[i];
		}
		++dp[i];
		//printf("%d ", dp[i]);
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
		if (ans < dp[i]) ans = dp[i];
	printf("%d", ans);
	return 0;
}