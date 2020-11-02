#include <cstdio>
int N, K;
int dp[210][210];
const int mod = 1000000000;
int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= K; i++) dp[0][i] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = (dp[i-1][j]+dp[i][j - 1])%mod;
			//dp[i][j]는 dp[0~i-1][j-1]의 합 + dp[i][j-1]에서 0을 더한값
			//dp[i-1][j]  = dp[i-1][j-1]를 합한 값 : 표참고
			//dp[i][j-1] : 이전것에서 0을 더하는 경우
		}
	}
	/*for (int i = 1; i <= N; i++) {
		printf("%d: ", i);
		for (int j = 1; j <= N; j++) {
			printf("%d ", dp[i][j]);
		}
		puts("");
	}*/
	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; i++) {
			printf("%d ", dp[i][j]);
		}
		puts("");
	}*/
	printf("%d\n", dp[N][K]);
	return 0;
}