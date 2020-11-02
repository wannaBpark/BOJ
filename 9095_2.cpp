#include <cstdio>
int dp[100];
int main()
{
	int T,N;
	scanf("%d", &T);
	dp[1] = 1, dp[2] = 1, dp[3] = 1;
	for (int i = 1; i <= 11; i++) {
		dp[i + 1] += dp[i]; dp[i + 2] += dp[i]; dp[i + 3] += dp[i];
	}
	while (T--) {
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}
	return 0;
}