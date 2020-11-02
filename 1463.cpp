#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1001000];
int N;
int main()
{
	scanf("%d", &N);
	dp[1] = 0, dp[2] = 1, dp[3] = 1,dp[4] =2;
	for (int i = 5; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);
		if (i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
	}
	printf("%d\n", dp[N]);
	return 0;
}