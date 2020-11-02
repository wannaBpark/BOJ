#include <cstdio>
int T, N;
int dp[12];
//이전 것에서 1을 더하거나, 2를더하거나, 3을 더하는 경우
//이전값을 참조하는 것.
int main()
{
	scanf("%d", &T); dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 4; i <= 10; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	while (T--) scanf("%d", &N), printf("%d\n", dp[N]);
}